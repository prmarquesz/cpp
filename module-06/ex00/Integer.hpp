/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:26:55 by proberto          #+#    #+#             */
/*   Updated: 2023/05/28 15:10:06 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <sstream>
#include <limits>
#include "Float.hpp"
#include "Double.hpp"

class Integer {
	private:
		long long value;
		static int _value;
	
	public:
		~Integer(void);
		Integer(void);
		Integer(const long long num);
		Integer(const Integer& src);

		Integer& operator=(const Integer& src);

		int getValue(void) const;

		static int parseInt(const std::string& literal);
		static int parseInt(const char literal);
		static std::string toString(const int num);
		static int valueOf(const float num);
		static int valueOf(const double num);

		static bool isInteger(const std::string& str);
};


std::ostream &operator<<(std::ostream &os, Integer const &integer);
