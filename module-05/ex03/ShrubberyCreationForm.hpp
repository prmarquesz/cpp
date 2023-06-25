/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:48:51 by proberto          #+#    #+#             */
/*   Updated: 2023/05/24 21:23:15 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Form.hpp"

class ShrubberyCreationForm: public Form {
	private:
		static const std::string asciiTrees;
		
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &src);

		void execute(Bureaucrat const & executor) const;

		class FileOutException : public std::exception {
			public:
				const char* what() const throw();
		};
};
