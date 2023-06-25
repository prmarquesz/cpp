/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:36:00 by proberto          #+#    #+#             */
/*   Updated: 2022/08/17 20:45:35 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int		main(void) {
	int		size = 10;
	Zombie *zombies = zombieHorde(size, "Ellie");

	for (int i=0; i<size; i++)
		zombies[i].announce();
	delete [] zombies;
	return 0;
}