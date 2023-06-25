/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:36:00 by proberto          #+#    #+#             */
/*   Updated: 2023/05/27 15:16:56 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Base.hpp"

int	main(void) {
	Base *	ptr;

	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		ptr = generate();
		identify(ptr);
		identify(*ptr);
		std::cout << "===========================================" << std::endl;
		delete ptr;
	}
	return (0);
}
