/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:36:54 by proberto          #+#    #+#             */
/*   Updated: 2023/04/15 19:46:07 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::~HumanA(void) {}

HumanA::HumanA(std::string name, Weapon &weapon): weapon(weapon), name(name) {}

void HumanA::attack(void) const {
	std::cout
		<< name
		<< " attacks with their "
		<< weapon.getType()
		<< std::endl;
}
