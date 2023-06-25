/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReader.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 00:24:31 by proberto          #+#    #+#             */
/*   Updated: 2022/08/21 13:03:21 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReader.hpp"

FileReader::FileReader(const char *file) {
	this->ifs.open(file);
	if (!this->ifs.is_open())
		throw std::runtime_error("File not found");
}

FileReader::~FileReader(void) {
	ifs.close();
}

std::string FileReader::readEntire(void) {
	std::stringstream ss;
	ss << this->ifs.rdbuf();
	return ss.str();
}
