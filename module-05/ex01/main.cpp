/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:36:00 by proberto          #+#    #+#             */
/*   Updated: 2022/09/25 18:23:54 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main(void) {
	
	std::cout
		<< "Trying create a Form with grade required to sign it equal to 0"
		<< std::endl;
	try {
		Form form("Form", 0, 1);
		std::cout << form << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout
		<< "Trying create a Form with grade required to execute it equal to 0"
		<< std::endl;
	try {
		Form form("Form", 1, 0);
		std::cout << form << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout
		<< "Trying create a Form with grade required to sign it equal to 151"
		<< std::endl;
	try {
		Form form("Form", 151, 1);
		std::cout << form << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout
		<< "Trying create a Form with grade required to execute it equal to 151"
		<< std::endl;
	try {
		Form form("Form", 1, 151);
		std::cout << form << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout
		<< "Trying create a Form with grade required to sign it equal to 1"
		<< " and grade required to execute it equal to 1"
		<< std::endl;
	try {
		Form form("Form", 1, 1);
		std::cout << form << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout
		<< "Trying create a Form with grade required to sign it equal to 150"
		<< " and grade required to execute it equal to 150"
		<< std::endl;
	try {
		Form form("Form", 150, 150);
		std::cout << form << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout
		<< "Grade 1 form trying to be signed by a Grade 2 bureaucrat"
		<< std::endl;
	try {
		Form form("Form", 1, 1);
		Bureaucrat bureaucrat("Bureaucrat", 2);
		form.beSigned(bureaucrat);
		std::cout << form << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout
		<< "Grade 1 form trying to be signed by a Grade 1 bureaucrat"
		<< std::endl;
	try {
		Form form("Form", 1, 1);
		Bureaucrat bureaucrat("Bureaucrat", 1);
		form.beSigned(bureaucrat);
		std::cout << form << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout
		<< "Grade 2 bureaucrat trying to sign Grade 1 Form"
		<< std::endl;
	try {
		Form form("Form", 1, 1);
		Bureaucrat bureaucrat("Bureaucrat", 2);
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout
		<< "Grade 1 bureaucrat trying to sign Grade 1 Form"
		<< std::endl;
	try {
		Form form("Form", 1, 1);
		Bureaucrat bureaucrat("Bureaucrat", 1);
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	return (0);
}
