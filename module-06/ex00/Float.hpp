/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:26:55 by proberto          #+#    #+#             */
/*   Updated: 2023/05/28 15:51:07 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <sstream>
#include <limits>

class Float {
	private:
		float value;
		static bool _isNan;
		static bool _isInf;
		static std::string inf;
	
	public:
		~Float(void);
		Float(void);
		Float(const float num);
		Float(const Float& src);

		Float& operator=(const Float& src);

		float getValue(void) const;
		static bool getIsNan(void);
		static bool getIsInf(void);
		static std::string getInf(void);

		static float parseFloat(const std::string& literal);
		static float parseFloat(const char literal);
		static std::string toString(const float num);
		static float valueOf(const int num);
		static float valueOf(const double num);

		static bool isFloat(const std::string& str);
		static bool isNan(const std::string& str);
		static bool isInf(const std::string& str);
};

std::ostream &operator<<(std::ostream &os, Float const &_float);
