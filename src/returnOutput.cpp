/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returnOutput.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 22:08:37 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/17 22:14:09 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "returnOutput.hpp"

void ReturnOutput::parseOutput()
{

}

ReturnOutput::ReturnOutput(const std::string &output) : _rawOutput(output) {}

std::string ReturnOutput::getBody() const
{
	return _body;
}

std::map<std::string, std::string> ReturnOutput::getHeaders() const
{
	return _headers;
}
