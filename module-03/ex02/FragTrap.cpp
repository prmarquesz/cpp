/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:47:04 by proberto          #+#    #+#             */
/*   Updated: 2022/09/13 20:30:06 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::~FragTrap(void) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " destructor called"
		<< std::endl;
}

FragTrap::FragTrap(void): ClapTrap() {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " default constructor called"
		<< std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(std::string const name): ClapTrap(name) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " string constructor called"
		<< std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &src): ClapTrap(src) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " copy constructor called"
		<< std::endl;
	*this = src;
}

FragTrap &FragTrap::operator=(FragTrap const &src) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " copy assignment operator called"
		<< std::endl;
	const_cast<std::string &>(this->name) = src.name;
	this->hitPoints = src.hitPoints;
	this->energyPoints = src.energyPoints;
	this->attackDamage = src.attackDamage;
	return (*this);
}

void FragTrap::highFivesGuys(void) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " "
		<< name;
	if (this->hitPoints > 0)
		std::cout
			<< " requested high five!"
			<< std::endl;
	else
		std::cout
			<< " is dead and can't give a high five :("
			<< std::endl;
}
