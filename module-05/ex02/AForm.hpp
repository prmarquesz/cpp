/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:50:47 by proberto          #+#    #+#             */
/*   Updated: 2023/05/24 20:23:42 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	name;
		const int			grade2Sign;
		const int			grade2Exec;
		bool				isSigned;
	
	protected:
		const std::string	target;
		virtual void execute(Bureaucrat const & executor) const = 0;
		
	public:
		AForm(void);
		AForm(const std::string name, const int grade2Sign, const int grade2Exec);
		AForm(const AForm& src);
		virtual ~AForm(void);
		AForm& operator=(const AForm& src);
		
		const std::string getName(void) const;
		bool getIsSigned(void) const;
		int getGrade2Sign(void) const;
		int getGrade2Exec(void) const;
		void beSigned(const Bureaucrat& bureaucrat);
		void performAction(const Bureaucrat& bureaucrat) const;
		
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		class UnsignedFormException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& o, const AForm& f);
