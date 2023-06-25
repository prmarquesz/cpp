/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:36:00 by proberto          #+#    #+#             */
/*   Updated: 2023/05/06 19:02:40 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

static void displayMessageTest(std::string const &message)
{
	std::cout
		<< std::endl
		<< "\001\033[1;32m\002"
		<< message
		<< "\001\033[0m\002"
		<< std::endl;
}

static ClapTrap playerWithoutEnergyPoints() {
	std::cout << "Creating a player without energy points" << std::endl;
	ClapTrap player("Pikachu");
	player.takeDamage(9);
	for (int i = 0; i < 10; i++)
		player.beRepaired(1);
	player.takeDamage(1);
	player.beRepaired(1);
	std::cout << player;
	return (player);
}

static ClapTrap playerWithoutHP() {
	std::cout << "Creating a player without HP" << std::endl;
	ClapTrap player("Pikachu");
	player.takeDamage(10);
	std::cout << player;
	return (player);
}

int	main(void) {

	displayMessageTest("Test 1: Default constructor");
	ClapTrap p1;
	displayMessageTest("Test 2: String constructor");
	ClapTrap p2("Bulbasaur");
	displayMessageTest("Test 3: Copy constructor");
	ClapTrap p3(p1);
	displayMessageTest("Test 4: Copy assignment operator");
	p1 = p3;
	p1.setAttackDamage(5);
	p2.setAttackDamage(2);
	std::cout << std::endl << "***** Player Scores *****" << std::endl;
	std::cout << p1;
	std::cout << std::endl;
	std::cout << p2;
	displayMessageTest("Test 5: Attack if there is HP and energy points");
	p1.attack(p2.getName());
	displayMessageTest("Test 6: Take damage if there is HP");
	p2.takeDamage(p1.getAttackDamage());
	std::cout << std::endl << "***** Player Scores *****" << std::endl;
	std::cout << p1;
	std::cout << std::endl;
	std::cout << p2;
	displayMessageTest("Test 7: Be repaired if there is HP and energy points");
	p2.beRepaired(1);
	std::cout << std::endl << "***** Player Scores *****" << std::endl;
	std::cout << p1;
	std::cout << std::endl;
	std::cout << p2;
	displayMessageTest("Test 8: Try to attack with HP but no energy points");
	playerWithoutEnergyPoints().attack(p2.getName());
	displayMessageTest("Test 9: Try to attack with energy points but no HP");
	playerWithoutHP().attack(p2.getName());
	displayMessageTest("Test 10: Try to take damage with no HP");
	playerWithoutHP().takeDamage(1);
	displayMessageTest("Test 11: Try to get repaired with HP but no energy points");
	playerWithoutEnergyPoints().beRepaired(1);
	displayMessageTest("Test 12: Try to get repaired with energy points but no HP");
	playerWithoutHP().beRepaired(1);
	displayMessageTest("Test 13: Destructors");
	return (0);
}
