/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:26:55 by proberto          #+#    #+#             */
/*   Updated: 2023/05/28 15:03:47 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Integer.hpp"
#include "Float.hpp"
#include "Double.hpp"
#include "Char.hpp"

class ScalarConverter {
	public: static void convert(const std::string& literal);
	
	private:
		ScalarConverter(void);
		
		static void convertFromChar(const Char literal);
		static void convertFromInt(const Integer literal);
		static void convertFromFloat(const Float literal);
		static void convertFromDouble(const Double literal);
		static void convertFromString(const std::string& literal);
};
