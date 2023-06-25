/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 06:37:40 by proberto          #+#    #+#             */
/*   Updated: 2022/09/10 19:36:23 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractionalBits = 8;

Fixed::Fixed(void) {
	this->rawBits = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	rawBits = num << fractionalBits;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	rawBits = roundf(num * (1 << fractionalBits));
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->rawBits = src.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed) {
	os << fixed.toFloat();
	return (os);
}

int Fixed::getRawBits(void) const {
	return (this->rawBits);
}

void Fixed::setRawBits(int const raw) {
	this->rawBits = raw;
}

int Fixed::toInt(void) const {
	return (rawBits >> fractionalBits);
}

float Fixed::toFloat(void) const {
	return ((float)rawBits / (1 << fractionalBits));
}
