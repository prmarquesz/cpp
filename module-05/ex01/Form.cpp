/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:50:53 by proberto          #+#    #+#             */
/*   Updated: 2022/09/25 16:54:53 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::~Form(void) {}

Form::Form(void): name("Form"), grade2Sign(1), grade2Exec(1), isSigned(false) {}

Form::Form(const std::string name, const int grade2Sign, const int grade2Exec): 
	name(name), grade2Sign(grade2Sign), grade2Exec(grade2Exec), isSigned(false)
{
	if (grade2Sign < 1 || grade2Exec < 1)
		throw Form::GradeTooHighException();
	if (grade2Sign > 150 || grade2Exec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src): 
	name(src.name),
	grade2Sign(src.grade2Sign),
	grade2Exec(src.grade2Exec),
	isSigned(src.isSigned)
{
	*this = src;
}

Form &Form::operator=(const Form &src) {
	if (this != &src) {
		const_cast<std::string&>(this->name) = src.name;
		const_cast<int&>(this->grade2Sign) = src.grade2Sign;
		const_cast<int&>(this->grade2Exec) = src.grade2Exec;
		this->isSigned = src.isSigned;
	}
	return (*this);
}

const std::string Form::getName(void) const {
	return (this->name);
}

bool Form::getIsSigned(void) const {
	return (this->isSigned);
}

int Form::getGrade2Sign(void) const {
	return (this->grade2Sign);
}

int Form::getGrade2Exec(void) const {
	return (this->grade2Exec);
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->grade2Sign)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Error: Form required grad is too high!");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Error: Form required grad is too low!");
}

std::ostream &operator<<(std::ostream &o, const Form &f) {
	o << "Form: " << f.getName() << std::endl;
	o << "Is signed: " << f.getIsSigned() << std::endl;
	o << "Grade to sign: " << f.getGrade2Sign() << std::endl;
	o << "Grade to execute: " << f.getGrade2Exec() << std::endl;
	return (o);
}