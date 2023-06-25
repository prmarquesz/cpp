/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:26:55 by proberto          #+#    #+#             */
/*   Updated: 2023/05/28 16:02:18 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Double.hpp"

bool Double::_isNan = false;
bool Double::_isInf = false;
std::string Double::inf = "";

Double::~Double(void) {}

Double::Double(void) {}

Double::Double(const double num): value(num) {}

Double::Double(const Double& src) {  *this = src; }

Double& Double::operator=(const Double& src) {
	this->value = src.value;
	return (*this);
}

double Double::getValue(void) const { return (this->value); }

bool Double::getIsNan(void) { return (_isNan); }

bool Double::getIsInf(void) { return (_isInf); }

std::string Double::getInf(void) { return (inf); }

double Double::parseDouble(const std::string& literal) {
	double num;
	std::istringstream iss(literal);
	
	if (!isDouble(literal))
		throw std::invalid_argument("impossible");
	if (isNan(literal)) {
		_isNan = true;
		iss >> num;
	}
	else if (isInf(literal)) {
		_isInf = true;
		inf = literal;
		iss >> num;
	}
	else
		iss >> num;
	return (num);
}

double Double::parseDouble(const char literal) {
	double num = static_cast<double>(literal);
	return (num);
}

std::string Double::toString(const double num) {
	std::stringstream ss;
	ss << num;
	return (ss.str());
}

double Double::valueOf(const int num) { return (static_cast<double>(num)); }

double Double::valueOf(const float num) { return (static_cast<double>(num)); }

bool Double::isDouble(const std::string& str) {
	size_t i = 0;
	
	if (isNan(str) || isInf(str))
		return (true);
	if (str[i] == '-' || str[i] == '+')
		i++;
	for (; i < str.length(); i++)
		if (!std::isdigit(str[i]) && str[i] != '.')
			return (false);
	return (true);
}

bool Double::isNan(const std::string& str) {
	if (!str.compare("nan") || !str.compare("+nan") || !str.compare("-nan")
		|| !str.compare("nanf") || !str.compare("+nanf") || !str.compare("-nanf"))
		return true;
	return false;
}

bool Double::isInf(const std::string& str) {
	if (!str.compare("inf") || !str.compare("+inf") || !str.compare("-inf")
		|| !str.compare("inff") || !str.compare("+inff") || !str.compare("-inff"))
		return true;
	return false;
}

std::ostream &operator<<(std::ostream &os, Double const &_double) {
	os << _double.getValue();
	return (os);
}
