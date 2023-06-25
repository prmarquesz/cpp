/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:18:20 by proberto          #+#    #+#             */
/*   Updated: 2022/09/25 00:20:20 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::~Brain(void) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " destructor called"
		<< std::endl;
}

Brain::Brain(void) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " default constructor called"
		<< std::endl;
	this->index = 0;
}

Brain::Brain(Brain const &src) {
		std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " copy constructor called"
		<< std::endl;
	this->index = src.index;
	*this = src;
}

Brain &Brain::operator=(Brain const &src) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " copy assignment operator called"
		<< std::endl;
	this->index = src.index;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	return (*this);
}

std::string Brain::getIdea(short index) const {
	if (index > 99)
		throw std::out_of_range("It wasn't me who had this idea");
	return (this->ideas[index]);
}

void Brain::addIdea(std::string idea) {
	if (this->index > 99)
		throw std::out_of_range("I'm full of ideas");
	this->ideas[index++] = idea;
}

std::ostream &operator<<(std::ostream &o, Brain const &i) {
  for (int j = 0; j < 100; j++) {
    o << i.getIdea(j) << std::endl;
  }
  return (o);
}
