/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:29:33 by proberto          #+#    #+#             */
/*   Updated: 2022/08/19 22:41:40 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
	private:
		Weapon		&weapon;
		std::string	name;
	
	public:
		~HumanA(void);
		HumanA(std::string name, Weapon &weapon);
		void attack(void) const;
};
