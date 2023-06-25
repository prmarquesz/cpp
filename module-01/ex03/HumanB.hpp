/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:33:35 by proberto          #+#    #+#             */
/*   Updated: 2022/08/19 22:43:49 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
	private:
		Weapon		*weapon;
		std::string	name;
	
	public:
		~HumanB(void);
		HumanB(std::string name);
		void setWeapon(Weapon &weapon);
		void attack(void) const;
};
