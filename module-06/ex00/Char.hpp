/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Char.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:26:55 by proberto          #+#    #+#             */
/*   Updated: 2023/05/28 14:53:58 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <sstream>
#include "Float.hpp"
#include "Double.hpp"

class Char {
	private:
		char value;
		
	public:
		~Char(void);
		Char(void);
		Char(const char character);
		Char(const Char& src);

		Char& operator=(const Char& src);

		char getValue(void) const;

		static char parseChar(const std::string& literal);
		static Char valueOf(const int num);
		static Char valueOf(const float num);
		static Char valueOf(const double num);
		static bool isChar(const std::string& str);
};

std::ostream &operator<<(std::ostream &os, Char const &_char);
