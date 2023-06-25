/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:41:13 by proberto          #+#    #+#             */
/*   Updated: 2023/06/19 21:30:42 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T> MutantStack<T>::~MutantStack(void) {}

template <typename T> MutantStack<T>::MutantStack(void) {}

template <typename T> MutantStack<T>::MutantStack(MutantStack const& src) { *this = src; }

template <typename T> MutantStack<T>& MutantStack<T>::operator=(MutantStack const& src) {
	if (this != &src) {
		std::stack<T>::operator=(src);
	}
	return *this;
}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return std::stack<T>::c.begin();
}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::end() {
	return std::stack<T>::c.end();
}
