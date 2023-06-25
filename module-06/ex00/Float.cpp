/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:26:55 by proberto          #+#    #+#             */
/*   Updated: 2023/05/28 15:51:41 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Float.hpp"

bool Float::_isNan = false;
bool Float::_isInf = false;
std::string Float::inf = "";

Float::~Float(void) {}

Float::Float(void) {}

Float::Float(const float num): value(num) {}

Float::Float(const Float& src) {  *this = src; }

Float& Float::operator=(const Float& src)
{
	this->value = src.value;
	return (*this);
}

float Float::getValue(void) const { return (this->value); }

bool Float::getIsNan(void) { return (_isNan); }

bool Float::getIsInf(void) { return (_isInf); }

std::string Float::getInf(void) { return (inf); }

float Float::parseFloat(const std::string& literal) {
	float num;
	std::string floatStr;
	
	if (!isFloat(literal))
		throw std::invalid_argument("impossible");
	if (isNan(literal)) {
		_isNan = true;
		if (literal[literal.length() - 1] == 'f')
			floatStr = literal.substr(0, literal.length() - 1);
		else
			floatStr = literal;
		std::istringstream iss(floatStr);
		iss >> num;
	} else if (isInf(literal)) {
		if (literal[literal.length() - 1] == 'f' && literal[literal.length() - 2] == 'f')
			floatStr = literal.substr(0, literal.length() - 1);
		else
			floatStr = literal;
		_isInf = true;
		inf = floatStr;
		std::istringstream iss(floatStr);
		iss >> num;
	}
	else {
		if (literal[literal.length() - 1] == 'f')
			floatStr = literal.substr(0, literal.length() - 1);
		else
			floatStr = literal;
		std::istringstream iss(floatStr);
		iss >> num;
		if (num == std::numeric_limits<float>::infinity())
			throw std::out_of_range("impossible");
	}
	return (num);
}

float Float::parseFloat(const char literal) {
	float num = static_cast<float>(literal);
	return (num);
}

std::string Float::toString(const float num) {
	std::stringstream ss;
	ss << num;
	return (ss.str());
}

float Float::valueOf(const int num) { return (static_cast<float>(num)); }

float Float::valueOf(const double num) { return (static_cast<float>(num)); }

bool Float::isFloat(const std::string& str) {
	size_t i = 0;
	
	if (isNan(str) || isInf(str))
		return (true);
	if (str[i] == '-' || str[i] == '+')
		i++;
	for (; i < str.length(); i++)
		if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
			return (false);
	return (true);
}

bool Float::isNan(const std::string& str) {
	if (!str.compare("nan") || !str.compare("+nan") || !str.compare("-nan")
		|| !str.compare("nanf") || !str.compare("+nanf") || !str.compare("-nanf"))
		return true;
	return false;
}

bool Float::isInf(const std::string& str) {
	if (!str.compare("inf") || !str.compare("+inf") || !str.compare("-inf")
		|| !str.compare("inff") || !str.compare("+inff") || !str.compare("-inff"))
		return true;
	return false;
}

std::ostream &operator<<(std::ostream &os, Float const &_float) {
	os << _float.getValue();
	return (os);
}

