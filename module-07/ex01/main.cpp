/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:36:00 by proberto          #+#    #+#             */
/*   Updated: 2023/06/15 21:41:39 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int	main(void) {

	int		array1[] = { 0, 1, 2, 3, 4 };
	char	array2[] = { 'a', 'b', 'c', 'd', 'e' };
	float	array3[] = { 0.0f, 0.1f, 0.2f, 0.3f, 0.4f };
	std::string	array4[] = { "hello", "world", "42", "SP", "Brazil" };

	std::cout << "INT ARRAY: " << std::endl;
	iter(array1, 5, ft_printf);
	std::cout << std::endl;

	std::cout << "CHAR ARRAY: " << std::endl;
	iter(array2, 5, ft_printf);
	std::cout << std::endl;

	std::cout << "FLOAT ARRAY: " << std::endl;
	iter(array3, 5, ft_printf);
	std::cout << std::endl;

	std::cout << "STRING ARRAY: " << std::endl;
	iter(array4, 5, ft_printf);
	return (0);
}
