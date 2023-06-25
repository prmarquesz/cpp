/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:36:00 by proberto          #+#    #+#             */
/*   Updated: 2023/06/15 21:56:47 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "whatever.hpp"

int	main(void) {

	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	a = 2;
	int e = 2;
	::swap( a, e );
	std::cout << "a = " << a << ", e = " << e << std::endl;
	std::cout << "min( a, e ) = " << ::min( a, e ) << std::endl;
	std::cout << "max( a, e ) = " << ::max( a, e ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	double f = 42.0;
	double g = 52.0;

	::swap(f, g);
	std::cout << "f = " << std::fixed << std::setprecision(1) << f << ", g = " << g << std::endl;
	std::cout << "min( f, g ) = " << ::min( f, g ) << std::endl;
	std::cout << "max( f, g ) = " << ::max( f, g ) << std::endl;

	return (0);
}
