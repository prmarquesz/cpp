/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:42:16 by proberto          #+#    #+#             */
/*   Updated: 2023/05/27 15:23:50 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(void) {}

Base * generate(void) {
	int n = std::rand() % 3;
	
	switch (n) {
		case 0:
			std::cout << "Instantiating class A" << std::endl;
			return (new A);
		case 1:
			std::cout << "Instantiating class B" << std::endl;
			return (new B);
		default :
			std::cout << "Instantiating class C" << std::endl;
			return (new C);
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type: C" << std::endl;
	else
		std::cerr << "Invalid pointer" << std::endl;
}

void identify(Base& p) {
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Type: A" << std::endl;
	} catch (std::exception &e) {}
	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Type: B" << std::endl;
	} catch (std::exception &e) {}
	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Type: C" << std::endl;
	} catch (std::exception &e) {}
}