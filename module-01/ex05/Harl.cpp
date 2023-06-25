/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 06:37:40 by proberto          #+#    #+#             */
/*   Updated: 2022/08/23 08:21:07 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ) {}

Harl::~Harl( void ) {}

void Harl::complain( std::string level ) {
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	void (Harl::*methods[]) (void) = { 
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (short i = 0; i < 4; i++) {
		if (!levels[i].compare(level)) {
			(this->*methods[i])();
			return ;
		}
	}
	throw std::invalid_argument("You must enter one of the following levels: "
			"DEBUG, INFO, WARNING, ERROR");
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
