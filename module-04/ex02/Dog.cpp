/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 06:37:40 by proberto          #+#    #+#             */
/*   Updated: 2022/09/25 12:51:22 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::~Dog(void) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " destructor called"
		<< std::endl;
	delete this->brain;
}

Dog::Dog(void): Animal() {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " default constructor called"
		<< std::endl;
	this->type = std::string(typeid(this).name()).substr(2);
	this->brain = new Brain();
}

Dog::Dog(Dog const &src): Animal(src){
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " copy constructor called"
		<< std::endl;
	this->brain = new Brain(*src.brain);
	*this = src;
}

Dog &Dog::operator=(Dog const &src) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " copy assignment operator called"
		<< std::endl;
	this->type = src.type;
	*this->brain = *src.brain;
	return (*this);
}

void Dog::makeSound(void) const {
	std::cout << "woof!" << std::endl;
}

void Dog::haveIdea(std::string idea) const {
	this->brain->addIdea(idea);
}

void Dog::showIdeas(void) const {
	std::cout << *this->brain;
}
