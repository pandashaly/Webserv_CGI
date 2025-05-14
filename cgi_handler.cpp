/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cgi_handler.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:00:11 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/14 13:04:29 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cgi_handler.hpp"
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <cstring>
#include <iostream>
#include <vector>

CgiHandler::CgiHandler(const std::string& script_path,
                       const std::map<std::string, std::string>& env,
                       const std::string& body)
    : _script_path(script_path), _env_vars(env), _request_body(body) {}

std::string CgiHandler::execute() {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        std::cerr << "pipe() failed\n";
        return "Status: 500 Internal Server Error\r\n\r\n";
    }

    pid_t pid = fork();
    if (pid < 0) {
        std::cerr << "fork() failed\n";
        return "Status: 500 Internal Server Error\r\n\r\n";
    }

    if (pid == 0) {
        // CHILD PROCESS

        // Redirect stdout to pipe write-end
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]); // close read-end in child
        close(pipefd[1]);

        // Build environment array
        char** envp = buildEnvArray();

        // argv = { script_path, NULL }
        char* const argv[] = {
            const_cast<char*>(_script_path.c_str()),
            NULL
        };

        // Execute script directly (if it has a #! shebang)
        execve(_script_path.c_str(), argv, envp);

        // If execve fails
        std::cerr << "execve() failed\n";
        freeEnvArray(envp);
        exit(1);
    }

    // PARENT PROCESS
    close(pipefd[1]); // close write-end in parent

    char buffer[1024];
    std::string output;
    ssize_t bytesRead;

    while ((bytesRead = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
        output.append(buffer, bytesRead);
    }

    close(pipefd[0]);
    waitpid(pid, NULL, 0); // wait for child to finish

    return output;
}



char** CgiHandler::buildEnvArray() const {
    char** env = new char*[_env_vars.size() + 1];
    size_t i = 0;
    for (std::map<std::string, std::string>::const_iterator it = _env_vars.begin(); it != _env_vars.end(); ++it) {
        std::string entry = it->first + "=" + it->second;
        env[i] = strdup(entry.c_str());
        i++;
    }
    env[i] = NULL;
    return env;
}

void CgiHandler::freeEnvArray(char** env) const {
    for (size_t i = 0; env[i]; ++i)
        free(env[i]);
    delete[] env;
}
