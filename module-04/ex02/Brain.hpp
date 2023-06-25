/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:13:52 by proberto          #+#    #+#             */
/*   Updated: 2022/09/25 00:24:14 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Brain {
	private:
		std::string	ideas[100];
		short		index;
		
	public:
		Brain(void);
		Brain(Brain const &src);
		~Brain(void);
		Brain &operator=(Brain const &src);
		
		std::string getIdea(short index) const;
		void addIdea(std::string idea);
};

std::ostream &operator<<(std::ostream &o, Brain const &i);
