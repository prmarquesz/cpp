/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:07:37 by proberto          #+#    #+#             */
/*   Updated: 2022/08/17 20:47:48 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Zombie {
	private:
		std::string _name;
	
	public:
		~Zombie(void);
		Zombie(void);
		Zombie(std::string name);
		void setName(std::string name);
		void announce(void);
};

Zombie*	zombieHorde( int N, std::string name );
