/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Char.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:26:55 by proberto          #+#    #+#             */
/*   Updated: 2023/05/28 14:55:18 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Char.hpp"

Char::~Char(void) {}

Char::Char(void) {}

Char::Char(const char character): value(character) {}

Char::Char(const Char& src) {  *this = src; }

Char& Char::operator=(const Char& src) {
	this->value = src.value;
	return (*this);
}

char Char::getValue(void) const { return (this->value); }

char Char::parseChar(const std::string& literal) {
	char character;
	
	if (!isChar(literal))
		throw std::invalid_argument("impossible");
	character = literal[0];
	return (character);
}

Char Char::valueOf(const int num) { return (static_cast<char>(num)); }

Char Char::valueOf(const float num) { 
	if (Float::isNan(Float::toString(num)))
		throw std::invalid_argument("impossible");
	return (static_cast<char>(num)); 
}

Char Char::valueOf(const double num) { 
	if (Double::isNan(Double::toString(num)))
		throw std::invalid_argument("impossible");
	return (static_cast<char>(num)); 
}

bool Char::isChar(const std::string& str) {
	if (str.length() != 1)
		return (false);
	return (true);
}

std::ostream &operator<<(std::ostream &os, Char const &_char) {
	if (std::isprint(_char.getValue()))
		os << "'" << _char.getValue() << "'";
	else
		os << "Non displayable";
	return (os);
}
