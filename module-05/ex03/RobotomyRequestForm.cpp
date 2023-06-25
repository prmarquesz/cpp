/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:05:50 by proberto          #+#    #+#             */
/*   Updated: 2023/05/24 21:18:00 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm::RobotomyRequestForm(void):
	Form("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	Form("RobotomyRequestForm", 72, 45) {
	const_cast<std::string&>(this->target) = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src):
	Form(src) {
	*this = src;
}

RobotomyRequestForm
&RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	if (this != &src) {
		const_cast<std::string&>(this->target) = src.target;
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	std::cout << "Bzzz..Zzzzzz...Xxx...Pxxx*...****" << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << this->target << " has been robotomized successfully"
			<< std::endl;
	else
		std::cout << "Robotomy failed." << std::endl;
	std::cout
		<< executor.getName()
		<< " executed "
		<< this->getName()
		<< std::endl;
}
