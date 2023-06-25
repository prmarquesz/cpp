/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:36:00 by proberto          #+#    #+#             */
/*   Updated: 2023/05/06 19:22:37 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
	ScavTrap scav;
	displayMessageTest("Test 2: String constructors");
	ScavTrap scav2("Squirtle");
	displayMessageTest("Test 3: Copy constructors");
	ScavTrap scav3(scav);
	scav3.setAttackDamage(5);
	std::cout << std::endl << "***** Player Scores *****" << std::endl;
	std::cout << scav3 << std::endl << scav2;
	displayMessageTest("Test 4: Attack if there is HP and energy points");
	scav2.attack(scav3.getName());
	displayMessageTest("Test 5: Take damage if there is HP");
	scav3.takeDamage(scav2.getAttackDamage());
	std::cout << std::endl << "***** Player Scores *****" << std::endl;
	std::cout << scav3 << std::endl << scav2;
	displayMessageTest("Test 6: Be repaired if there is HP and energy points");
	scav3.beRepaired(1);
	displayMessageTest("Test 7: Guard gate");
	scav3.guardGate();
	displayMessageTest("Test 8: Destructors");
	return (0);
}
