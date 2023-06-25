/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:36:00 by proberto          #+#    #+#             */
/*   Updated: 2023/05/24 20:34:34 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	
	std::cout << "Generic form tests: " << std::endl << std::endl;
	std::cout
		<< "Form tries to be executed without being signed"
		<< std::endl;
	try {
		ShrubberyCreationForm form("home");
		Bureaucrat bureaucrat("Bureaucrat", 1);
		form.performAction(bureaucrat);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	
	std::cout
		<< "Form tries to be executed by bureaucrat with inferior exec grade"
		<< std::endl;
	try {
		ShrubberyCreationForm form("home");
		Bureaucrat bureaucrat("Bureaucrat", 1);
		form.beSigned(bureaucrat);
		Bureaucrat bureaucrat2("Bureaucrat2", 150);
		form.performAction(bureaucrat2);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout
		<< "Bureaucrat tries to execute unsigned form"
		<< std::endl;
	try {
		ShrubberyCreationForm form("home");
		Bureaucrat bureaucrat("Bureaucrat", 1);
		bureaucrat.executeForm(form);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl
		<< "Bureaucrat with inferior exec grade tries to execute form"
		<< std::endl;
	try {
		ShrubberyCreationForm form("home");
		Bureaucrat bureaucrat("Bureaucrat", 1);
		form.beSigned(bureaucrat);
		Bureaucrat bureaucrat2("Bureaucrat2", 140);
		bureaucrat2.executeForm(form);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl
		<< "ShrubberyCreationForm exec test: " << std::endl;
	try {
		ShrubberyCreationForm form("home");
		Bureaucrat bureaucrat("Bureaucrat", 1);
		form.beSigned(bureaucrat);
		bureaucrat.executeForm(form);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	
	std::cout << std::endl
		<< "RobotomyRequestForm exec test: " << std::endl;
	try {
		RobotomyRequestForm form("Marvin");
		Bureaucrat bureaucrat("Bureaucrat", 1);
		form.beSigned(bureaucrat);
		bureaucrat.executeForm(form);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	
	std::cout << std::endl
		<< "PresidentialPardonForm exec test: " << std::endl;
	try {
		PresidentialPardonForm form("Marvin");
		Bureaucrat bureaucrat("Bureaucrat", 1);
		form.beSigned(bureaucrat);
		bureaucrat.executeForm(form);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	return (0);
}
