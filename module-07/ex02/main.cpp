/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:36:00 by proberto          #+#    #+#             */
/*   Updated: 2023/06/15 21:38:18 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main(void) {

	Array<int> a(5);
	Array<char> b(5);
	Array<float> c(5);
	Array<float> d(c);
	Array<int> e(0);

	std::cout << "Empty ARRAY: " << std::endl;
	Array<int> emptyInt = Array<int>();
	Array<char> emptyChar = Array<char>();
	Array<float> emptyFloat = Array<float>();
	std::cout << emptyInt << std::endl;
	std::cout << emptyChar << std::endl;
	std::cout << emptyFloat << std::endl;
	
	std::cout << "INT ARRAY: " << std::endl;
	for (unsigned int i = 0; i < 5; i++)
		a[i] = i + 1;
	std::cout << a << std::endl;

	std::cout << "COPY ARRAY: " << std::endl;
	Array<int> y(a);
	for (unsigned int i = 0; i < 5; i++)
		y[i] = i + 1;
	std::cout << y << std::endl;

	std::cout << "SIZE ARRAY: " << std::endl;
	std::cout << a.size() << std::endl << std::endl;

	std::cout << "CHAR ARRAY: " << std::endl;
	for (unsigned int i = 0; i < 5; i++)
		b[i] = i + 'a';
	std::cout << b << std::endl;

	std::cout << "FLOAT ARRAY: " << std::endl;
	for (unsigned int i = 0; i < 5; i++)
		c[i] = 1.1f + static_cast<float>(i);
	std::cout << c << std::endl;

	std::cout << "Index out of range: " << std::endl;
	try {
		e[100];
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		e[-1];
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Array<int> f;
		f[0] = 1;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
