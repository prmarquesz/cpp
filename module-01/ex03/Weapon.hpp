/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:25:31 by proberto          #+#    #+#             */
/*   Updated: 2022/08/19 22:45:21 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Weapon {
	private: 
		std::string type;
	
	public:
		~Weapon(void);
		Weapon(std::string type);
		const std::string &getType() const;
		void setType(std::string type);
};
