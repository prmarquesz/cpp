/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:36:00 by proberto          #+#    #+#             */
/*   Updated: 2022/08/23 08:07:45 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv) try {
	Harl harl;

	if (argc != 2)
		throw std::out_of_range("You must enter one of the following levels: "
			"DEBUG, INFO, WARNING, ERROR");
	harl.complain(argv[1]);
	return (0);
} catch (const std::exception& ex) {
	std::cerr << ex.what() << std::endl;
	return (1);
}
