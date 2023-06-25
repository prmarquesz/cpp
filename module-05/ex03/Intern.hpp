/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:09:50 by proberto          #+#    #+#             */
/*   Updated: 2022/09/29 19:45:38 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {

	public:
		~Intern(void);
		Intern(void);
		Intern(const Intern& src);

		Intern& operator=(const Intern& src);

		Form* makeForm(const std::string formName, const std::string target);
		Form* makePresidentialPardonForm(const std::string target);
		Form* makeRobotomyRequestForm(const std::string target);
		Form* makeShrubberyCreationForm(const std::string target);

		class NoMatchException : public std::exception {
			public:
				const char* what(void) const throw();
		};
};
