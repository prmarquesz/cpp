/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 07:04:06 by proberto          #+#    #+#             */
/*   Updated: 2023/05/24 20:49:24 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::asciiTrees =  ""
	"       ###            ###           \n" 
    "      #o###          #o###          \n"
    "    #####o###      #####o###        \n"
    "   #o#\\#|#/##    #o#\\#|#/##       \n"
    "    ##\\|/#o#      ##\\|/#o#        \n"
    "     # }|{ #        # }|{ #         \n"
    "       }|{            }|{           \n";

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("ShrubberyCreationForm", 145, 137) {
	const_cast<std::string&>(this->target) = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src):
	AForm(src) {
	*this = src;
}

ShrubberyCreationForm 
&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	if (this != &src) {
		const_cast<std::string&>(this->target) = src.target;
	}
	return (*this);
}

const char* ShrubberyCreationForm::FileOutException::what() const throw() {
	return ("Error: File output exception!");
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	std::ofstream ofs(std::string(this->target + "_shrubbery").c_str());
	if (!ofs.is_open())
		throw ShrubberyCreationForm::FileOutException();
    ofs << this->asciiTrees << std::endl;
	ofs.close();
	std::cout << "ASCII trees created!" << std::endl;
	std::cout
			<< executor.getName()
			<< " executed "
			<< this->getName()
			<< std::endl;
}
