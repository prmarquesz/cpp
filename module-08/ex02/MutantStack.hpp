/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:41:13 by proberto          #+#    #+#             */
/*   Updated: 2023/06/19 21:29:59 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>

template<typename T>
class MutantStack: public std::stack<T> {
	
	public:
		~MutantStack(void);
		MutantStack(void);
		MutantStack(const MutantStack &src);
		
		MutantStack &operator=(const MutantStack &src);
		
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin(void);
		iterator end(void);

};

#include "MutantStack.tpp"
