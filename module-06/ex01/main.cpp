/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:36:00 by proberto          #+#    #+#             */
/*   Updated: 2023/05/27 14:51:44 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int	main(void) {
	Data		data("proberto", "0");
	uintptr_t	serialized = Serializer::serialize(&data);
	Data*		deserialized = Serializer::deserialize(serialized);

	std::cout << "Data address " << &data << std::endl;
	std::cout << "Data structure: " << std::endl << data << std::endl;

	std::cout << "Serialize Data " << std::endl;
	std::cout << "serialized: " << serialized << std::endl << std::endl;

	std::cout << "Deserialization Data " << std::endl;
	std::cout << "deserialized address: " << deserialized << std::endl;
	std::cout << "deserialized structure: " << std::endl << *deserialized << std::endl;

	deserialized->setPasswd("42");
	deserialized->setUsername("proberto42");
	std::cout << "After change deserialized structure: " << std::endl << *deserialized << std::endl;
	std::cout << "Data structure: " << std::endl << data << std::endl;
	return (0);
}
