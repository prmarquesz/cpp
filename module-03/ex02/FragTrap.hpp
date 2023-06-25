/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:05:09 by proberto          #+#    #+#             */
/*   Updated: 2022/09/13 20:12:45 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(std::string const name);
		FragTrap(FragTrap const &src);
		~FragTrap(void);

		FragTrap &operator=(FragTrap const &src);

		void highFivesGuys(void);
};
