/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cgi_handler.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:00:06 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/14 13:00:46 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CGI_HANDLER_HPP
#define CGI_HANDLER_HPP

#include <string>
#include <map>

class CgiHandler {
public:
    CgiHandler(const std::string& script_path,
               const std::map<std::string, std::string>& env,
               const std::string& body = "");
    
    std::string execute();  // Run script, return output

private:
    std::string _script_path;
    std::map<std::string, std::string> _env_vars;
    std::string _request_body;

    char** buildEnvArray() const;
    void freeEnvArray(char** env) const;
};

#endif
