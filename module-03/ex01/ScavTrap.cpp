/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:47:04 by proberto          #+#    #+#             */
/*   Updated: 2022/09/12 08:00:34 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::~ScavTrap(void) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " destructor called"
		<< std::endl;
}

ScavTrap::ScavTrap(void): ClapTrap() {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " default constructor called"
		<< std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string const name): ClapTrap(name) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " string constructor called"
		<< std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &src): ClapTrap(src) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " copy constructor called"
		<< std::endl;
	*this = src;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &src) {
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

void ScavTrap::attack(std::string const &target) {
	std::cout 
		<< std::string(typeid(this).name()).substr(2)
		<< " "
		<< name;
	if (hitPoints == 0) {
		std::cout << " can't attack because it's dead" << std::endl;
		return;
	}
	if (energyPoints == 0) {
		std::cout << " can't attack because it's out of energy" << std::endl;
		return;
	}
	std::cout
		<< " attacks "
		<< target
		<< ", causing "
		<< attackDamage
		<< " points of damage!"
		<< std::endl;
	energyPoints--;
}

void ScavTrap::guardGate(void) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " "
		<< name;
	if (hitPoints == 0) {
		std::cout << " can't guard the gate because it's dead" << std::endl;
		return;
	}
	std::cout << " has entered in Gate keeper mode" << std::endl;
}
