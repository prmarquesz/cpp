/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 06:37:40 by proberto          #+#    #+#             */
/*   Updated: 2022/09/25 12:56:38 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::~Dog(void) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " destructor called"
		<< std::endl;
}

Dog::Dog(void): Animal() {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " default constructor called"
		<< std::endl;
	this->type = std::string(typeid(this).name()).substr(2);
}

Dog::Dog(Dog const &src): Animal(src) {
		std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " copy constructor called"
		<< std::endl;
	*this = src;
}

Dog &Dog::operator=(Dog const &src) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " copy assignment operator called"
		<< std::endl;
	this->type = src.type;
	return (*this);
}

void Dog::makeSound(void) const {
	std::cout << "woof!" << std::endl;
}
