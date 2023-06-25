/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:45:39 by proberto          #+#    #+#             */
/*   Updated: 2023/06/10 11:10:21 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <ctime>
#include "PmergeMe.hpp"

void printBenchmark(size_t numElements, std::string container, double elapsedTime) {
	std::cout << "Time to process a range of " 
		<< std::fixed 
		<< std::setprecision(5) 
		<< numElements 
		<< " elements with std::" << container << " : " 
		<< elapsedTime << " us" 
		<< std::endl;
}

int main(int argc, char *argv[]) try {
	std::vector<int> vec;
	std::deque<int> deq;
	clock_t start = 0;
	clock_t end = 0;
	double elapsedTime = 0.0;
	
	
	if (argc < 3)
		throw std::invalid_argument("Invalid number of arguments");
	fillArray(vec, argv);
	fillArray(deq, argv);
	
	std::cout << "Before:: ";
	printArray(vec);
	start = clock();
	PmergeMe::mergeInsertSort(vec);
	end = clock();
	elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "After:: ";
	printArray(vec);
	printBenchmark(vec.size(), "vector", elapsedTime);
	
	start = clock();
	PmergeMe::mergeInsertSort(deq);
	end = clock();
	elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	printBenchmark(deq.size(), "deque", elapsedTime);
} catch (const std::exception& ex) {
	std::cerr << ex.what() << std::endl;
	return (1);
}
