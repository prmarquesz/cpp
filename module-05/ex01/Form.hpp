/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:50:47 by proberto          #+#    #+#             */
/*   Updated: 2022/09/25 17:33:30 by proberto         ###   ########.fr       */
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
		
	public:
		~Form(void);
		Form(void);
		Form(const std::string name, const int grade2Sign, const int grade2Exec);
		Form(const Form& src);
		Form& operator=(const Form& src);
		const std::string getName() const;
		bool getIsSigned() const;
		int getGrade2Sign() const;
		int getGrade2Exec() const;
		void beSigned(const Bureaucrat& bureaucrat);
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};	
};

std::ostream& operator<<(std::ostream& o, const Form& f);
