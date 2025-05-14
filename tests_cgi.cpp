/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_cgi.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:57:45 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/14 19:01:25 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cgi_handler.hpp"
// #include <iostream>
// #include <map> //env vars

// int main()
// {
// 	std::map<std::string, std::string> env; //fake env for testing putposes
// 	env["REQUEST_METHOD"] = "GET";
// 	env["SCRIPT_FILENAME"] = "./cgi/scripts/test.py";

// 	CgiHandler handler("test.py", env);
// 	std::string output = handler.execute();

// 	std::cout << "=== CGI SCRIPT OUTPUT ===" << std::endl;
// 	std::cout << output << std::endl;

// 	return 0;
// }

#include "receiveRequest.hpp"
#include "prepEnv.hpp"
#include <iostream>

int main() {
	std::map<std::string, std::string> headers;
	headers["Content-Type"] = "application/testing-cgi-modules";
	headers["Content-Length"] = "42";

	RequestData request("POST", "./www/cgi-bin/totally_not_a_virus.py", "download=yes", headers, "screaming=internally&chaos=100%");

	EnvBuilder envBuilder(request);
	char** envp = envBuilder.buildEnvArray();

	std::cout << "== CGI ENVIRONMENT VARIABLES ==" << std::endl;
	for (size_t i = 0; envp[i]; ++i)
		std::cout << envp[i] << std::endl;

	envBuilder.freeEnvArray(envp);

	return 0;
}

