/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:36:00 by proberto          #+#    #+#             */
/*   Updated: 2022/09/25 14:49:27 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	
	std::cout << "Trying to create a Bureaucrat with grade 0" << std::endl;
	try {
		Bureaucrat b1("Bureaucrat 1", 0);
		std::cout << b1 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << "Trying to create a Bureaucrat with grade 151" << std::endl;
	try {
		Bureaucrat b2("Bureaucrat 2", 151);
		std::cout << b2 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << "Trying to create a Bureaucrat with grade 1" << std::endl;
	try {
		Bureaucrat b3("Bureaucrat 3", 1);
		std::cout << b3 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << "Trying to create a Bureaucrat with grade 150" << std::endl;
	try {
		Bureaucrat b4("Bureaucrat 4", 150);
		std::cout << b4 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << "Trying increment grade 1" << std::endl;
	try {
		Bureaucrat b5("Bureaucrat", 1);
		std::cout << b5 << std::endl;
		b5.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << "Trying decrement grade 150" << std::endl;
	try {
		Bureaucrat b6("Bureaucrat", 150);
		std::cout << b6 << std::endl;
		b6.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	return (0);
}
