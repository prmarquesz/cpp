/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileWriter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:03:39 by proberto          #+#    #+#             */
/*   Updated: 2023/04/15 19:48:39 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileWriter.hpp"

FileWriter::FileWriter(std::string fileName) {
	this->ofs.open(fileName.c_str());
	if (!this->ofs.is_open())
		throw std::runtime_error("File not found");
}

FileWriter::~FileWriter(void) {
	ofs.close();
}

void FileWriter::write(std::string text) {
	this->ofs << text;
}
