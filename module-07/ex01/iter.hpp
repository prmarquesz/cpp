/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:26:55 by proberto          #+#    #+#             */
/*   Updated: 2023/06/15 21:19:05 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

template <typename T> void iter(T* addr, size_t length, void (*f)(const T&))
{
	for (size_t i = 0; i < length; i++)
		f(addr[i]);
}

template <typename T> void iter(T* addr, size_t length, void (*f)(T&))
{
	for (size_t i = 0; i < length; i++)
		f(addr[i]);
}

template <typename T> void ft_printf(const T& value)
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << value << std::endl;
}
