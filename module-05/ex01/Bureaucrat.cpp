/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:57:22 by proberto          #+#    #+#             */
/*   Updated: 2022/09/25 17:12:23 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(void): name("Ash"), grade(1) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name) {
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
	if (this != &src) {
		this->grade = src.grade;
		const_cast<std::string&>(this->name) = src.name;
	}
	return (*this);
}

const std::string &Bureaucrat::getName(void) const {
	return (this->name);
}

int Bureaucrat::getGrade(void) const {
	return (this->grade);
}

void Bureaucrat::incrementGrade(void) {
	if (this->grade - 1 < 1)
		throw GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade(void) {
	if (this->grade + 1 > 150)
		throw GradeTooLowException();
	this->grade++;
}

void Bureaucrat::signForm(const Form &form) const {
	try {
		(*const_cast<Form*>(&form)).beSigned(*this);
		std::cout
			<< this->name
			<< " signed "
			<< form.getName()
			<< std::endl;
	} catch (std::exception &e) {
		std::cout
			<< this->name
			<< " couldn’t sign "
			<< form.getName()
			<< " because "
			<< e.what()
			<< std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
  return ("Exception: Bureaucrat grade is to high!");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
  return ("Exception: Bureaucrat grade is to low!");
}

std::ostream &operator<<(std::ostream & o, Bureaucrat const & b) {
	o 
		<< b.getName() 
		<< ", bureaucrat grade "
		<< b.getGrade()
		<< "."
		<< std::endl;
	return (o);
}
