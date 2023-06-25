/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:42:37 by proberto          #+#    #+#             */
/*   Updated: 2022/09/25 14:58:51 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

class Bureaucrat {
	private:
		const std::string name;
		int grade;
	
	public:
		~Bureaucrat(void);
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);

		const std::string &getName(void) const;
		int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);

		class GradeTooHighException : public std::exception {
			public:
				const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream & o, Bureaucrat const & b);
