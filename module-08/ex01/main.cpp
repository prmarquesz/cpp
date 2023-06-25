/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:36:00 by proberto          #+#    #+#             */
/*   Updated: 2023/06/18 14:23:19 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include <cstdlib>

int main(void) {

	std::cout << "TEST 1: try to add more than N numbers" << std::endl;
	{
		Span sp = Span(5);
		try {
			sp.addNumber(5);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			sp.addNumber(7);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl << std::endl;
		}
	}
	
	std::cout << "TEST 2: try the smallest range with only 1 num" << std::endl;
	{
		Span sp = Span(5);
		try {
			sp.addNumber(5);
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl << std::endl;
		}
	}

	std::cout << "TEST 3: try the biggest range with only 1 num" << std::endl;
	{
		Span sp = Span(5);
		try {
			sp.addNumber(5);
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl << std::endl;
		}
	}

	std::cout << "TEST 4: try the smallest/biggest span" << std::endl;
	{
		Span sp = Span(7);
		try {
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			sp.addNumber(0);
			sp.addNumber(-1);
			
			std::cout << sp;
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
			std::cout << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl << std::endl;
		}
	}

	std::cout << "TEST 5: try the smallest/biggest span" << std::endl;
	{
		Span sp = Span(100);
		try {
			srand(time(0));
			for (int i = 0; i < 100; i++)
				sp.addNumber(rand() % 10000);

			std::cout << sp;

			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl << std::endl;
		}
	}

	std::cout << "TEST 6: try the smallest/biggest span full fill" << std::endl;
	{
		Span sp = Span(15000);
		try {
			sp.fullFill();
			std::cout << sp;
			
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl << std::endl;
		}
	}

	return (0);
}
