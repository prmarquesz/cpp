/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:32:45 by proberto          #+#    #+#             */
/*   Updated: 2022/08/21 15:38:24 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "String.hpp"
#include <iostream>

std::string String::replace(
	std::string str,
	std::string from,
	std::string to
)
{
	std::string strReplaced;

	if (str.empty() || from.empty() || to.empty())
		return str;
	size_t pos = str.find(from);
	if (pos == std::string::npos)
		return str;
	strReplaced = str.substr(0, pos);
	strReplaced.append(to);
	strReplaced.append(str.substr(pos + from.length()));
	return strReplaced;
}

std::string String::replaceAll(
	std::string str,
	std::string from,
	std::string to
) 
{
	if (str.empty() || from.empty() || to.empty())
		return str;
	std::string strReplaced(str);
	size_t pos = str.find(from);
	while (pos != std::string::npos) {
		strReplaced = replace(strReplaced, from, to);
		pos = strReplaced.find(from, pos + to.length());
	}
	return strReplaced;
}
