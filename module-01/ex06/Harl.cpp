/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 06:37:40 by proberto          #+#    #+#             */
/*   Updated: 2022/08/24 01:20:23 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ) {}

Harl::~Harl( void ) {}

void Harl::complain( std::string level ) {
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	short int	i = 0;

	for (i = 0; i < 4; i++) {
		if (!levels[i].compare(level))
			break ;
	}
	switch (i) {
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
		default:
			throw std::out_of_range(
				"[ Probably complaining about insignificant problems ]"
			);
	}
}

void Harl::debug( void ) {
	std::cout
		<< "[ DEBUG ]" << std::endl
		<< "I love having extra bacon for my "
		"7XL-double-cheese-triple-pickle-special- ketchup burger." << std::endl
		<< "I really do!" << std::endl
		<< std::endl;
}

void Harl::info( void ) {
	std::cout
		<< "[ INFO ]" << std::endl
		<< "I cannot believe adding extra bacon costs more money." << std::endl
		<< "You didn’t put enough bacon in my burger! If you did, "
		"I wouldn’t be asking for more!" << std::endl
		<< std::endl;
}

void Harl::warning( void ) {
	std::cout
		<< "[ WARNING ]" << std::endl
		<< "I think I deserve to have some extra bacon for free. " << std::endl
		<< "I’ve been coming for years whereas you started working here since "
		"last month." << std::endl
		<< std::endl;
}

void Harl::error( void ) {
	std::cout
		<< "[ ERROR ]" << std::endl
		<< "This is unacceptable! "
		"I want to speak to the manager now." << std::endl
		<< std::endl;
}
