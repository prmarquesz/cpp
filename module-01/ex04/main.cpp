/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:36:00 by proberto          #+#    #+#             */
/*   Updated: 2022/08/21 14:12:36 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "String.hpp"
#include "FileReader.hpp"
#include "FileWriter.hpp"

int	main(int argc, char **argv) try {
	std::string buffer;

	if (argc != 4)
		throw std::out_of_range("Invalid number of arguments");
	FileReader fr(argv[1]);
	FileWriter fw(std::string(argv[1]).append(".replace"));
	buffer = fr.readEntire();
	fw.write(String::replaceAll(buffer, argv[2], argv[3]));
	return (0);
} catch (const std::exception& ex) {
	std::cerr << ex.what() << std::endl;
	return (1);
}
