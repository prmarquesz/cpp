/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:36:00 by proberto          #+#    #+#             */
/*   Updated: 2023/05/26 21:40:26 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "ScalarConverter.hpp"

int	main(int argc, char *argv[]) try {

	if (argc != 2)
		throw std::invalid_argument(
			"Please enter one valid string or char at a time!\n"
			"Example: \"c\", \"-42\", \"-4.2f\", \"-4.2\", \"nan\""
		);
	ScalarConverter::convert(argv[1]);
	return (0);
} catch (std::exception &e) {
	std::cerr << e.what() << std::endl;
	return (1);
}
