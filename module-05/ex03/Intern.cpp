/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:19:38 by proberto          #+#    #+#             */
/*   Updated: 2022/09/29 19:46:51 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::~Intern(void) {}

Intern::Intern(void) {}

Intern::Intern(const Intern& src)
{
	*this = src;
}

Intern& Intern::operator=(const Intern& src)
{
	(void) src;
	return (*this);
}

Form* Intern::makeForm(const std::string formName, const std::string target)
{
	Form* ( Intern::*f[] ) ( const std::string ) = { 
		&Intern::makePresidentialPardonForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makeShrubberyCreationForm
	};

	std::string formNames[] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
			return ((this->*f[i])(target));
	}
	throw Intern::NoMatchException();
}

Form* Intern::makePresidentialPardonForm(const std::string target) {
	return (new PresidentialPardonForm(target));
}

Form* Intern::makeRobotomyRequestForm(const std::string target) {
	return (new RobotomyRequestForm(target));
}

Form* Intern::makeShrubberyCreationForm(const std::string target) {
	return (new ShrubberyCreationForm(target));
}

const char* Intern::NoMatchException::what(void) const throw() {
	return ("Error: No match found for the form name");
}
