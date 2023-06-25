/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:49:33 by proberto          #+#    #+#             */
/*   Updated: 2023/05/27 14:46:26 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::~Data(void) {}

Data::Data(void) {}

Data::Data(std::string username, std::string passwd) {
	this->username = username;
	this->passwd = passwd;
}

Data::Data(const Data &src) {
	*this = src;
}

Data &Data::operator=(const Data &src) {
	if (this != &src) {
		this->username = src.username;
		this->passwd = src.passwd;
	}
	return (*this);
}

std::string Data::getUsername(void) const {
	return (this->username);
}

std::string Data::getPasswd(void) const {
	return (this->passwd);
}

void Data::setUsername(std::string username) {
	this->username = username;
}

void Data::setPasswd(std::string passwd) {
	this->passwd = passwd;
}

std::ostream &operator<<(std::ostream &os, const Data &data) {
	os << "username: " << data.getUsername() << std::endl;
	os << "password: " << data.getPasswd() << std::endl;
	return (os);
}
