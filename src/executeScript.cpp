/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executeScript.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:26:00 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/15 17:27:34 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executeScript.hpp"

ScriptExecutor::ScriptExecutor(const std::string &scriptPath, const RequestData &request) : _scriptPath(scriptPath), _request(request) {}

ScriptExecutor::~ScriptExecutor() {}

std::string ScriptExecutor::runScript()
{
	if (!createOutPipe())
		return errorResponse();
	
	pid_t pid = fork();
	if (pid < 0)
		return errorResponse();
	if (pid == 0)
		runChild();
	else
		runParent(pid);
	
	return errorResponse();
}

bool ScriptExecutor::createOutPipe()
{
	return pipe(_pipe) == 0;
}

char** ScriptExecutor::createArgv() const

std::string ScriptExecutor::getInterpreter() const

void ScriptExecutor::runChild()

std::string ScriptExecutor::runParent(pid_t pid)

void ScriptExecutor::execveScript()

std::string ScriptExecutor::errorResponse()
{
	return "Status: 500 Internal Server Error\n\n";
}

std::string ScriptExecutor::getInterpreter() const
{
	size_t dot = _scriptPath.rfind('.');
	if (dot == std::string::npos)
		return "";

	std::string ext = _scriptPath.substr(dot);

	if (ext == ".py")
		return "/usr/bin/python3";
	if (ext == ".sh")
		return "/bin/bash";
	return "";
}

void ScriptExecutor::bodytoStdin() // only for POST
