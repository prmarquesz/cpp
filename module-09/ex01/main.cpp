/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:45:39 by proberto          #+#    #+#             */
/*   Updated: 2023/06/08 18:15:50 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "RPN.hpp"

void removeSpaces(std::string& str) {
    size_t pos = str.find(' ');
    while (pos != std::string::npos) {
        str.erase(pos, 1);
        pos = str.find(' ');
    }
}

int main(int argc, char *argv[]) try {
	std::string str;

	if (argc != 2)
		throw std::invalid_argument("Invalid number of arguments");
	str = argv[1];
	removeSpaces(str);
	std::cout << RPN::apply(str) << std::endl;
} catch (const std::exception& ex) {
	std::cerr << ex.what() << std::endl;
	return (1);
}
