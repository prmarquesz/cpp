/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:18:26 by proberto          #+#    #+#             */
/*   Updated: 2023/06/18 14:15:15 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::~Span(void) {}

Span::Span(void): length(0) {}

Span::Span(unsigned int n): length(n) {}

Span::Span(const Span& other) { this->operator=(other); }

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		this->length = other.length;
		this->vector = other.vector;
	}
	return (*this);
}

unsigned int Span::getLength(void) const { return (this->length); }

std::vector<int> Span::getVector(void) const { return (this->vector); }

void Span::addNumber(int n) {
	if (this->vector.size() == this->length)
		throw std::out_of_range("The span is full");
	this->vector.push_back(n);
}

void Span::fullFill(void) {
	if (this->vector.size() == this->length)
		throw std::out_of_range("The span is full");

	srand(time(0));
	if (this->vector.size() == 0)
		this->vector.push_back(rand() % 100);

	this->vector.insert(
		this->vector.end(),
		length - vector.size(),
		rand() % 100
	);
}

int Span::shortestSpan(void) {
	if (this->vector.size() < 2)
		throw std::length_error("The span is too small");

	int shortest = std::numeric_limits<int>::max();
	std::vector<int>::iterator it = this->vector.begin();
	for (; it != this->vector.end() - 1; it++)
		if ((std::abs(*it - *(it + 1)) > 0)
			&& (std::abs(*it - *(it + 1)) < shortest))
			shortest = std::abs(*it - *(it + 1));

	return (shortest);
}

int Span::longestSpan(void) {
	if (this->vector.size() < 2)
		throw std::length_error("The span is too small");

	std::vector<int>::iterator max = std::max_element(
		this->vector.begin(),
		this->vector.end()
	);
	std::vector<int>::iterator min = std::min_element(
		this->vector.begin(),
		this->vector.end()
	);

	return (*max - *min);
}

std::ostream& operator<<(std::ostream& out, const Span& span) {
	out << "Length: " << span.getLength() << std::endl;
	out << "Vector: ";
	std::vector<int> vec = span.getVector();
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		out << *it << " ";
	out << std::endl;
	return (out);
}
