/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:49:05 by proberto          #+#    #+#             */
/*   Updated: 2023/06/19 22:52:33 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template<typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator it = std::find(
		container.begin(),
		container.end(),
		value
	);
	if (it == container.end())
		throw std::runtime_error("Value not found!");
	return (it);
}
