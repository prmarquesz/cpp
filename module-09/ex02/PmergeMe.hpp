/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:45:39 by proberto          #+#    #+#             */
/*   Updated: 2023/06/10 11:21:41 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>

class PmergeMe {
	private: PmergeMe(void);

	public:
		static void mergeInsertSort(std::vector<int> &array);
		static void mergeInsertSort(std::deque<int> &array);
};

template <typename T> void fillArray(T &array, char *elements[]) {
	int number;

	for (int i = 1; elements[i]; i++) {
		std::stringstream ss(elements[i]);
		ss >> number;
		array.push_back(number);
	}
}

template <typename T> void printArray(T &array) {
	for (typename T::iterator it = array.begin(); it != array.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}
