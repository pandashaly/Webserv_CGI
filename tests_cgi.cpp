/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_cgi.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:57:45 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/14 12:59:51 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cgi_handler.hpp"
#include <iostream>
#include <map> //env vars

int main()
{
	std::map<std::string, std::string> env; //fake env for testing putposes
	env["REQUEST_METHOD"] = "GET";
	env["SCRIPT_FILENAME"] = "./cgi/scripts/test.py";

	CgiHandler handler("test.py", env);
	std::string output = handler.execute();

	std::cout << "=== CGI SCRIPT OUTPUT ===" << std::endl;
	std::cout << output << std::endl;

	return 0;
}
