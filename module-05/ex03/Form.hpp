/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:50:47 by proberto          #+#    #+#             */
/*   Updated: 2023/05/24 21:28:32 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	name;
		const int			grade2Sign;
		const int			grade2Exec;
		bool				isSigned;
	
	protected:
		const std::string	target;
		virtual void execute(Bureaucrat const & executor) const = 0;
		
	public:
		Form(void);
		Form(const std::string name, const int grade2Sign, const int grade2Exec);
		Form(const Form& src);
		virtual ~Form(void);
		Form& operator=(const Form& src);
		
		const std::string getName(void) const;
		bool getIsSigned(void) const;
		int getGrade2Sign(void) const;
		int getGrade2Exec(void) const;
		const std::string getTarget(void) const;
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

std::ostream& operator<<(std::ostream& o, const Form& f);
