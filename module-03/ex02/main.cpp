/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:36:00 by proberto          #+#    #+#             */
/*   Updated: 2023/05/06 19:23:34 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

static void displayMessageTest(std::string const &message)
{
	std::cout
		<< std::endl
		<< "\001\033[1;32m\002"
		<< message
		<< "\001\033[0m\002"
		<< std::endl;
}

int	main(void) {

	displayMessageTest("Test 1: Default constructors");
	FragTrap flag;
	ScavTrap scav;
	displayMessageTest("Test 2: String constructors");
	FragTrap flag2("Squirtle");
	ScavTrap scav2("Bulbasaur");
	displayMessageTest("Test 3: Copy constructors");
	FragTrap flag3(flag);
	ScavTrap scav3(scav);
	std::cout << std::endl << "***** Player Scores *****" << std::endl;
	std::cout << flag << std::endl << flag2 << std::endl << scav2 << std::endl;
	displayMessageTest("Test 7: High fives request");
	flag.highFivesGuys();
	displayMessageTest("Test 8: Destructors");
	return (0);
}
