/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 06:37:45 by proberto          #+#    #+#             */
/*   Updated: 2022/09/25 12:54:20 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#pragma once

class Animal {
	protected:
		std::string type;

	public:
		Animal(void);
		Animal(Animal const &src);
		virtual ~Animal(void);
		Animal &operator=(Animal const &src);
		
		std::string getType(void) const;
		virtual void makeSound(void) const = 0;
};
