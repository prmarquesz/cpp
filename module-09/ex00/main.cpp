/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:45:39 by proberto          #+#    #+#             */
/*   Updated: 2023/06/04 23:27:21 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <BitcoinExchange.hpp>


int main(int argc, char *argv[]) try {
	if (argc != 2)
		throw std::invalid_argument("Error: could not open file.");
	
	BitcoinExchange::exchange(argv[1]);
	return (0);
} catch (const std::exception& ex) {
	std::cerr << ex.what() << std::endl;
	return (1);
}
