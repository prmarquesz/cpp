/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 06:37:40 by proberto          #+#    #+#             */
/*   Updated: 2022/09/25 12:51:39 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::~Cat(void) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " destructor called"
		<< std::endl;
	delete this->brain;
}

Cat::Cat(void): Animal() {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " default constructor called"
		<< std::endl;
	this->type = std::string(typeid(this).name()).substr(2);
	this->brain = new Brain();
}

Cat::Cat(Cat const &src): Animal(src) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " copy constructor called"
		<< std::endl;
	*this->brain = *src.brain;
	*this = src;
}

Cat &Cat::operator=(Cat const &src) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " copy assignment operator called"
		<< std::endl;
	this->type = src.type;
	*this->brain = *src.brain;
	return (*this);
}

void Cat::makeSound(void) const {
	std::cout << "meow!" << std::endl;
}
