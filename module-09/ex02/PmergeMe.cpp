/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:45:39 by proberto          #+#    #+#             */
/*   Updated: 2023/06/10 11:26:45 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

void PmergeMe::mergeInsertSort(std::vector<int> &array) {
	int n = array.size();
    if (n <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;
    for (int i = 0; i < n; i += 2) {
        int second = (i + 1 < n) ? array[i + 1] : array[i];
        pairs.push_back(std::make_pair(array[i], second));
    }

    std::vector<int> largerElements;
    for (size_t i = 0; i < pairs.size(); i++) {
        largerElements.push_back(std::max(pairs[i].first, pairs[i].second));
    }

    mergeInsertSort(largerElements);

	int smallestElement = *std::min_element(array.begin(), array.end());
    largerElements.insert(largerElements.begin(), smallestElement);

    std::vector<int> sortedArray;
    for (int i = 0; i < n; i++) {
        std::vector<int>::iterator it = std::lower_bound(sortedArray.begin(), sortedArray.end(), array[i]);
        sortedArray.insert(it, array[i]);
    }
    array = sortedArray;
}

void PmergeMe::mergeInsertSort(std::deque<int> &array) {
	int n = array.size();
    if (n <= 1)
        return;

    std::deque<std::pair<int, int> > pairs;
    for (int i = 0; i < n; i += 2) {
        int second = (i + 1 < n) ? array[i + 1] : array[i];
        pairs.push_back(std::make_pair(array[i], second));
    }

    std::deque<int> largerElements;
    for (size_t i = 0; i < pairs.size(); i++) {
        largerElements.push_back(std::max(pairs[i].first, pairs[i].second));
    }

    mergeInsertSort(largerElements);

	int smallestElement = *std::min_element(array.begin(), array.end());
    largerElements.insert(largerElements.begin(), smallestElement);

    std::deque<int> sortedArray;
    for (int i = 0; i < n; i++) {
        std::deque<int>::iterator it = std::lower_bound(sortedArray.begin(), sortedArray.end(), array[i]);
        sortedArray.insert(it, array[i]);
    }
    array = sortedArray;
}
