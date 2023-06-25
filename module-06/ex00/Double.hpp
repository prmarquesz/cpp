/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:26:55 by proberto          #+#    #+#             */
/*   Updated: 2023/05/28 15:58:42 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <sstream>

class Double {
	private:
		double value;
		static bool _isNan;
		static bool _isInf;
		static std::string inf;

	public:
		~Double(void);
		Double(void);
		Double(const double num);
		Double(const Double& src);

		Double& operator=(const Double& src);

		double getValue(void) const;
		static bool getIsNan(void);
		static bool getIsInf(void);
		static std::string getInf(void);

		static double parseDouble(const std::string& literal);
		static double parseDouble(const char literal);
		static std::string toString(const double num);
		static double valueOf(const int num);
		static double valueOf(const float num);

		static bool isDouble(const std::string& str);
		static bool isNan(const std::string& str);
		static bool isInf(const std::string& str);
};	

std::ostream &operator<<(std::ostream &os, Double const &_double);
