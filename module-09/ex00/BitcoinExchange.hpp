/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:45:39 by proberto          #+#    #+#             */
/*   Updated: 2023/06/24 23:21:25 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>

#define FILENAME "data.csv"

class BitcoinExchange {
	private:
		BitcoinExchange(void);
		static std::map<std::string, float> map;
		static float findByDateBeforeOrOn(std::string searchDate);
		static float findInCache(std::string searchDate);
		static float findInFile(std::string searchDate);
		static bool isValidDate(std::string date);
		static bool isValidValue(std::string price);

	public:
		static void exchange(std::string filename);
};
