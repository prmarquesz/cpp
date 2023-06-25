/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:26:55 by proberto          #+#    #+#             */
/*   Updated: 2023/05/28 15:58:06 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& literal) {
	try {
		convertFromInt(Integer::parseInt(literal));
		return ;
	} catch (std::exception &e) {}
		
	try {
		convertFromFloat(Float::parseFloat(literal));
		return ;
	} catch (std::exception &e) {}

	try {
		convertFromDouble(Double::parseDouble(literal));
		return ;
	} catch (std::exception &e) {}

	try {
		convertFromChar(Char::parseChar(literal));
		return ;
	} catch (std::exception &e) {}

	try {
		convertFromString(literal);
		return ;
	} catch (std::exception &e) {}
}

void ScalarConverter::convertFromInt(const Integer literal) {
	std::cout << "char: " << Char::valueOf(literal.getValue()) << std::endl;
	std::cout << "int: " << literal << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << Float::valueOf(literal.getValue()) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << Double::valueOf(literal.getValue()) << std::endl;
}

void ScalarConverter::convertFromFloat(const Float literal) {
	if (Float::getIsNan()) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}
	std::cout << "char: " << Char::valueOf(literal.getValue()) << std::endl;
	std::cout << "int: " << Integer::valueOf(literal.getValue()) << std::endl;
	if (Float::getIsInf()) {
		std::cout << "float: " << std::fixed << std::setprecision(1) << Float::getInf() << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << Float::getInf() << "f" << std::endl;
	} else {
		std::cout << "floats: " << std::fixed << std::setprecision(1) << literal << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << Double::valueOf(literal.getValue()) << std::endl;
	}
}

void ScalarConverter::convertFromDouble(const Double literal) {
	if (Double::getIsNan()) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	} 
	std::cout << "char: " << Char::valueOf(literal.getValue()) << std::endl;
	std::cout << "int: " << Integer::valueOf(literal.getValue()) << std::endl;
	if (Double::getIsInf()) {
		std::cout << "float: " << std::fixed << std::setprecision(1) << Double::getInf() << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << Double::getInf() << std::endl;
	}else {
		std::cout << "float: " << std::fixed << std::setprecision(1) << Float::valueOf(literal.getValue()) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << literal << std::endl;
	}
}

void ScalarConverter::convertFromChar(const Char literal) {
	std::cout << "char: " << literal << std::endl;
	std::cout << "int: " << Integer::parseInt(literal.getValue()) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << Float::parseFloat(literal.getValue()) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << Double::parseDouble(literal.getValue()) << std::endl;
}

void ScalarConverter::convertFromString(const std::string& literal) {
	try {
		std::cout << "char: " << Char::parseChar(literal) << std::endl;
	} catch (std::exception &e) {std::cout << e.what() << std::endl;}

	try {
		std::cout << "int: " << Integer::parseInt(literal) << std::endl;
	} catch (std::exception &e) {std::cout << e.what() << std::endl;}

	try {
		std::cout << "float: " << std::fixed << std::setprecision(1) << Float::parseFloat(literal) << "f" << std::endl;
	} catch (std::exception &e) {std::cout << e.what() << std::endl;}

	try {
		std::cout << "double: " << std::fixed << std::setprecision(1) << Double::parseDouble(literal) << std::endl;
	} catch (std::exception &e) {std::cout << e.what() << std::endl;}
}
