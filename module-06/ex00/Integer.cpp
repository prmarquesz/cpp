/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:26:55 by proberto          #+#    #+#             */
/*   Updated: 2023/05/28 14:48:03 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Integer.hpp"

Integer::~Integer(void) {}

Integer::Integer(void): value(0) {}

Integer::Integer(const long long num): value(num) {}

Integer::Integer(const Integer& src) { *this = src; }

Integer& Integer::operator=(const Integer& src) {
	this->value = src.value;
	return (*this);
}

int Integer::getValue(void) const { return (this->value); }

int Integer::parseInt(const std::string& literal) {
	long long _int = 0;
	std::istringstream iss(literal);
	
	if (!isInteger(literal))
		throw std::invalid_argument("impossible");
	iss >> _int;
	if (_int < std::numeric_limits<int>::min() 
		|| _int > std::numeric_limits<int>::max())
		throw std::out_of_range("impossible");
	return (_int);
}

int Integer::parseInt(const char literal) {
	int _int = static_cast<int>(literal);
	return (_int);
}

std::string Integer::toString(const int num) {
	std::ostringstream oss;
	oss << num;
	return (oss.str());
}

int Integer::valueOf(const float num) {
	if (Float::isNan(Float::toString(num)))
		throw std::invalid_argument("impossible");
	return (static_cast<int>(num)); 
}

int Integer::valueOf(const double num) {
	if (Double::isNan(Double::toString(num)))
		throw std::invalid_argument("impossible");
	return (static_cast<int>(num)); 
}

bool Integer::isInteger(const std::string& str) {
	size_t i = 0;
	
	if (str[i] == '-' || str[i] == '+')
		i++;
	for (; i < str.length(); i++)
		if (!std::isdigit(str[i]))
			return false;
	return true;
}

std::ostream &operator<<(std::ostream &os, Integer const &integer) {
	if (integer.getValue() < std::numeric_limits<int>::min() 
		|| integer.getValue() > std::numeric_limits<int>::max())
		os << "impossible";
	else
		os << integer.getValue();
	return (os);
}
