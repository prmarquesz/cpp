/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:36:00 by proberto          #+#    #+#             */
/*   Updated: 2023/06/18 13:47:38 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <deque>
#include <list>
#include <vector>
#include <algorithm>

void	ft_print(int n) {
	std::cout << n << " ";
}

int main(void) {

	std::deque<int>			deque;
	std::list<int>			list;
	std::vector<int>		vector;

	std::cout << std::endl << "DEQUE INT:" << std::endl;
	for (int i = 0; i < 5; i++)
		deque.insert(deque.end(), i + 1);
	std::for_each(deque.begin(), deque.end(), ft_print);
	std::cout << std::endl << "SEARCH VALUE 2" << std::endl;
	std::cout << "Result: ";
	try {
		std::deque<int>::iterator it = easyfind(deque, 2);
		std::cout << *it << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}


	std::cout << std::endl << "LIST INT:" << std::endl;
	for (int i = 0; i < 5; i++)
		list.insert(list.end(), i + 1);
	std::for_each(list.begin(), list.end(), ft_print);
	std::cout << std::endl << "SEARCH VALUE 4" << std::endl;
	std::cout << "Result: ";
	try {
		std::list<int>::iterator it = easyfind(list, 4);
		std::cout << *it << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}


	std::cout << std::endl << "VECTOR INT:" << std::endl;
	for (int i = 0; i < 5; i++)
		vector.insert(vector.end(), i + 1);
	std::for_each(vector.begin(), vector.end(), ft_print);
	std::cout << std::endl << "SEARCH VALUE 5" << std::endl;
	std::cout << "Result: ";
	try {
		std::vector<int>::iterator it = easyfind(vector, 5);
		std::cout << *it << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}


	std::cout << std::endl << "SEARCH VALUE 6 (exception)" << std::endl;
	std::cout << "Result: ";
	try {
		std::vector<int>::iterator it = easyfind(vector, 6);
		std::cout << *it << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
