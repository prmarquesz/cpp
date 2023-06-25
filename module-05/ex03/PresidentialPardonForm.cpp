/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:21:40 by proberto          #+#    #+#             */
/*   Updated: 2023/05/24 21:17:44 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm::PresidentialPardonForm(void):
	Form("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	Form("PresidentialPardonForm", 25, 5) {
	const_cast<std::string&>(this->target) = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src):
	Form(src) {
	*this = src;
}

PresidentialPardonForm
&PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	if (this != &src) {
		const_cast<std::string&>(this->target) = target;
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox."
		<< std::endl;
	std::cout
		<< executor.getName()
		<< " executed "
		<< this->getName()
		<< std::endl;
}
