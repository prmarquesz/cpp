/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 06:37:40 by proberto          #+#    #+#             */
/*   Updated: 2022/09/24 21:24:17 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::~Animal(void) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " destructor called"
		<< std::endl;
}

Animal::Animal(void): type(std::string(typeid(this).name()).substr(2)){
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " default constructor called"
		<< std::endl;
}

Animal::Animal(Animal const &src) {
		std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " copy constructor called"
		<< std::endl;
	*this = src;
}

Animal &Animal::operator=(Animal const &src) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " copy assignment operator called"
		<< std::endl;
	this->type = src.type;
	return (*this);
}

std::string Animal::getType(void) const {
	return (this->type);
}

void Animal::makeSound(void) const {
	std::cout << "roarrrr!" << std::endl;
}
