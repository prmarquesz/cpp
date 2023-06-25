/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 06:37:40 by proberto          #+#    #+#             */
/*   Updated: 2022/09/11 21:49:29 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::~ClapTrap(void) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " destructor called"
		<< std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " copy constructor called"
		<< std::endl;
	*this = src;
}

ClapTrap::ClapTrap(void): name("Charmander"){
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " default constructor called"
		<< std::endl;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string const name): name(name) {
	std::cout
		<< std::string(typeid(this).name()).substr(2)
		<< " string constructor called"
		<< std::endl;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &src) {
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

std::string ClapTrap::getName(void) const {
	return (this->name);
}

int ClapTrap::getHitPoints(void) const {
	return (this->hitPoints);
}

int ClapTrap::getEnergyPoints(void) const {
	return (this->energyPoints);
}

int ClapTrap::getAttackDamage(void) const {
	return (this->attackDamage);
}

void ClapTrap::setAttackDamage(int const attackDamage) {
	this->attackDamage = attackDamage;
}

void ClapTrap::attack(std::string const &target) {
	std::cout 
		<< "ClapTrap "
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

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout
		<< "ClapTrap "
		<< name;
	if (hitPoints == 0) {
		std::cout << " can't take damage because it's dead" << std::endl;
		return;
	}
	std::cout
		<< " takes "
		<< amount
		<< " points of damage!"
		<< std::endl;
	hitPoints -= amount;
	if (hitPoints <= 0) {
		hitPoints = 0;
		std::cout << "ClapTrap " << name << " died" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap "
		<< name;
	if (hitPoints == 0) {
		std::cout << " can't be repaired because it's dead" << std::endl;
		return;
	}
	if (energyPoints == 0) {
		std::cout << " can't be repaired because it's out of energy" << std::endl;
		return;
	}
	if (hitPoints == 10) {
		std::cout << " can't be repaired because it's already full of energy" << std::endl;
		return;
	}
	std::cout
		<< " is repaired "
		<< amount
		<< " points!"
		<< std::endl;
	energyPoints--;
	hitPoints += amount;
}

std::ostream &operator<<(std::ostream &os, ClapTrap const &clapTrap) {
	os << "Name: " << clapTrap.getName() << std::endl;
	os << "Hit points: " << clapTrap.getHitPoints() << std::endl;
	os << "Energy points: " << clapTrap.getEnergyPoints() << std::endl;
	os << "Attack damage: " << clapTrap.getAttackDamage() << std::endl;
	return (os);
}
