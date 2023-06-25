/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:36:00 by proberto          #+#    #+#             */
/*   Updated: 2022/09/28 20:34:58 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void) {
	
	std::cout
		<< "Intern tries to create a Shrubbery Creation Form"
		<< std::endl;
	try {
		Form *form = Intern().makeForm("shrubbery creation", "home");
		std::cout << *form << std::endl;
		delete form;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout
		<< "Intern tries to create a Robotomy Request Form"
		<< std::endl;
	try {
		Form *form = Intern().makeForm("robotomy request", "Bender");
		std::cout << *form << std::endl;
		delete form;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout
		<< "Intern tries to create a Presidential Pardon Form"
		<< std::endl;
	try {
		Form *form = Intern().makeForm("presidential pardon", "Bender");
		std::cout << *form << std::endl;
		delete form;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout
		<< "Intern tries to create a Form that does not exist"
		<< std::endl;
	try {
		Form *form = Intern().makeForm("form that does not exist", "Bender");
		std::cout << *form << std::endl;
		delete form;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	return (0);
}
