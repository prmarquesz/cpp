/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 06:37:45 by proberto          #+#    #+#             */
/*   Updated: 2022/09/24 18:44:53 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {

	public:
		Cat(void);
		Cat(Cat const &src);
		~Cat(void);
		Cat &operator=(Cat const &src);
		
		void makeSound(void) const;
};
