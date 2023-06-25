/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:50:53 by proberto          #+#    #+#             */
/*   Updated: 2023/05/24 20:13:09 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::~AForm(void) {}

AForm::AForm(void): name("AForm"), grade2Sign(1), grade2Exec(1), isSigned(false) {}

AForm::AForm(const std::string name, const int grade2Sign, const int grade2Exec): 
	name(name), grade2Sign(grade2Sign), grade2Exec(grade2Exec), isSigned(false)
{
	if (grade2Sign < 1 || grade2Exec < 1)
		throw AForm::GradeTooHighException();
	if (grade2Sign > 150 || grade2Exec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src): 
	name(src.name),
	grade2Sign(src.grade2Sign),
	grade2Exec(src.grade2Exec),
	isSigned(src.isSigned)
{
	*this = src;
}

AForm &AForm::operator=(const AForm &src) {
	if (this != &src) {
		const_cast<std::string&>(this->name) = src.name;
		const_cast<int&>(this->grade2Sign) = src.grade2Sign;
		const_cast<int&>(this->grade2Exec) = src.grade2Exec;
		this->isSigned = src.isSigned;
	}
	return (*this);
}

const std::string AForm::getName(void) const {
	return (this->name);
}

bool AForm::getIsSigned(void) const {
	return (this->isSigned);
}

int AForm::getGrade2Sign(void) const {
	return (this->grade2Sign);
}

int AForm::getGrade2Exec(void) const {
	return (this->grade2Exec);
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->grade2Sign)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

void AForm::performAction(const Bureaucrat& bureaucrat) const {
	if (!this->isSigned)
		throw AForm::UnsignedFormException();
	if (bureaucrat.getGrade() > this->grade2Exec)
		throw AForm::GradeTooLowException();
	this->execute(bureaucrat);
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Error: Form required grad is too high!");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Error: Form required grad is too low!");
}

const char* AForm::UnsignedFormException::what() const throw() {
	return ("Error: Form is not signed!");
}

std::ostream &operator<<(std::ostream &o, const AForm &f) {
	o << "Form: " << f.getName() << std::endl;
	o << "Is signed: " << f.getIsSigned() << std::endl;
	o << "Grade to sign: " << f.getGrade2Sign() << std::endl;
	o << "Grade to execute: " << f.getGrade2Exec() << std::endl;
	return (o);
}
