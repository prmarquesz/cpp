/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:07:37 by proberto          #+#    #+#             */
/*   Updated: 2022/08/17 20:50:39 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Zombie {
	private:
		std::string _name;
	
	public:
		Zombie(std::string name);
		~Zombie(void);
		void announce(void);
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );
