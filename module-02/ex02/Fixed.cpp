/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 06:37:40 by proberto          #+#    #+#             */
/*   Updated: 2022/09/10 20:22:29 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractionalBits = 8;

Fixed::Fixed(void) {
	this->rawBits = 0;
}

Fixed::Fixed(const int num) {
	rawBits = num << fractionalBits;
}

Fixed::Fixed(const float num) {
	rawBits = roundf(num * (1 << fractionalBits));
}

Fixed::Fixed(Fixed const &src) {
	*this = src;
}

Fixed::~Fixed(void) {
}

Fixed &Fixed::operator=(Fixed const &src) {
	this->rawBits = src.getRawBits();
	return (*this);
}

bool Fixed::operator>(Fixed const &other) const {
	return (rawBits > other.getRawBits());
}

bool Fixed::operator<(Fixed const &other) const {
	return (rawBits < other.getRawBits());
}

bool Fixed::operator>=(Fixed const &other) const {
	return (rawBits >= other.getRawBits());
}

bool Fixed::operator<=(Fixed const &other) const {
	return (rawBits <= other.getRawBits());
}

bool Fixed::operator==(Fixed const &other) const {
	return (rawBits == other.getRawBits());
}

bool Fixed::operator!=(Fixed const &other) const {
	return (rawBits != other.getRawBits());
}

Fixed Fixed::operator+(Fixed const &other) const {
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(Fixed const &other) const {
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(Fixed const &other) const {
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(Fixed const &other) const {
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed &Fixed::operator++(void) {
	++rawBits;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	rawBits++;
	return (tmp);
}

Fixed &Fixed::operator--(void) {
	--rawBits;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	rawBits--;
	return (tmp);
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

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
	return (a.getRawBits() > b.getRawBits() ? a : b);
}
