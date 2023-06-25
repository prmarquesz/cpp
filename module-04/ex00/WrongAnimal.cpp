/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:19:44 by proberto          #+#    #+#             */
/*   Updated: 2022/09/24 21:43:30 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::~WrongAnimal(void) {
	std::cout
		<< std::string(typeid(this).name()).substr(3)
		<< " destructor called"
		<< std::endl;
}

WrongAnimal::WrongAnimal(void) {
	std::cout
		<< std::string(typeid(this).name()).substr(3)
		<< " default constructor called"
		<< std::endl;
	this->type = std::string(typeid(this).name()).substr(3);
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) {
		std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " copy constructor called"
		<< std::endl;
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " copy assignment operator called"
		<< std::endl;
	this->type = src.type;
	return (*this);
}

std::string WrongAnimal::getType(void) const {
	return (this->type);
}

void WrongAnimal::makeSound(void) const {
	std::cout << "roarrrr!" << std::endl;
}
