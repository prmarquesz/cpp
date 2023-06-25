/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:45:39 by proberto          #+#    #+#             */
/*   Updated: 2023/06/24 23:27:53 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

std::map<std::string, float> BitcoinExchange::map = std::map<std::string, float>();

BitcoinExchange::BitcoinExchange(void) {}

float BitcoinExchange::findInFile(std::string searchDate) {
	std::ifstream file(FILENAME);
	std::string line;
	std::string date;
	float price = 0;
	float exchangeRate = 0;

	if (searchDate < "2009-01-02") {
		std::cout << "Warning: bitcoin did not exist before 2009: ";
		return (0.0);
	}
	if (searchDate > "2022-03-29") {
		std::cout << "Warning: the most recent quotation in the database is 2022-03-29: ";
		return (47115.93);
	}
	if (!file.is_open())
		throw std::invalid_argument("Error: could not open file.");
	(void)std::getline(file, line);
	while (std::getline(file, line)) {
		date = line.substr(0, line.find(','));
		std::stringstream(line.substr(line.find(',') + 1)) >> price;
		if (searchDate > date) {
			map[date] = price;
			continue ;
		} else if (searchDate == date) {
			exchangeRate = price;
			map[date] = price;
			break ;
		} else {
			std::map<std::string, float>::iterator it = map.end();
			try {
				--it;
				exchangeRate = it->second;
				map[date] = price;
				break ;
			} catch (std::exception &e) {
				exchangeRate = price;
				map[date] = price;
				break ;
			};
		}
	}
	file.close();
	return (exchangeRate);
}

float BitcoinExchange::findInCache(std::string searchDate) {
	std::map<std::string, float>::iterator it;
	
	if (map.empty())
		return (-1.0);
	if (searchDate < "2009-01-02") {
		std::cout << "Warning: bitcoin did not exist before 2009: ";
		return (0.0);
	}
	if (searchDate > "2022-03-29") {
		std::cout << "Warning: the most recent quotation in the database is 2022-03-29: ";
		return (47115.93);
	}
	for (it = map.begin(); it != map.end(); it++) {
		if (searchDate > it->first)
			continue ;
		else if (searchDate == it->first)
			return (it->second);
		else {
			try {
				--it;
				return (it->second);
			}
			catch(std::exception& e) {
				return (-1.0);
			}
		}
	}
	return (-1.0);
}

float BitcoinExchange::findByDateBeforeOrOn(std::string searchDate) {
	float exchangeRate = 0;

	exchangeRate = findInCache(searchDate);
	if (exchangeRate < 0.0)
		exchangeRate = findInFile(searchDate);
	return (exchangeRate);
}

bool BitcoinExchange::isValidValue(std::string value) {
	std::string price = "0123456789.";

	value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
	if (value == "")
		return (false);
	return (true);
}

bool BitcoinExchange::isValidDate(std::string date) {
	int year = 0;
	int month = 0;
	int day = 0;
	std::string digits = "0123456789";

	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	if (date.substr(0, 4).find_first_not_of(digits) != std::string::npos)
		return (false);
	if (date.substr(5, 2).find_first_not_of(digits) != std::string::npos)
		return (false);
	if (date.substr(8, 2).find_first_not_of(digits) != std::string::npos)
		return (false);
	std::stringstream(date.substr(0, 4)) >> year;
	std::stringstream(date.substr(5, 2)) >> month;
	std::stringstream(date.substr(8, 2)) >> day;
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);
	return (true);
}

void BitcoinExchange::exchange(std::string fileName) {
	std::ifstream file(fileName.c_str());
	std::string line;
	std::string date;
	float price = 0;
	float exchangeRate = 0;
	char token;

	if (!file.is_open())
		throw std::invalid_argument("Error: could not open file.");
	(void)std::getline(file, line);
	if (line.find(',') != std::string::npos)
		token = ',';
	else if (line.find('|') != std::string::npos)
		token = '|';
	else
		throw std::invalid_argument("Error: bad input => missing token.");
	if (line.substr(0, line.find(token)).find("date") == std::string::npos)
		throw std::invalid_argument("Error: bad input => missing date.");
	if (line.substr(line.find(token) + 1).find("value") == std::string::npos)
		throw std::invalid_argument("Error: bad input => missing value.");
	while (std::getline(file, line)) {
		if (line.find(token) != std::string::npos) {
			std::stringstream(line.substr(line.find(token) + 1)) >> price;
			if (price < 0.0)
				date = std::string("Error: not a positive number.");
			else if (price > 1000.0)
				date = std::string("Error: too large a number.");
			else {
				date = line.substr(0, line.find(token));
				date = date.substr(0, date.find(' '));
				if (isValidDate(date) && isValidValue(line.substr(line.find(token) + 1)))
					exchangeRate = price * findByDateBeforeOrOn(date);
				else
					date = std::string("Error: bad input => ").append(line);
			}
		}
		else {
			date = std::string("Error: bad input => ").append(line);
			price = 0;
		}
		std::cout << date;
		if (date.find("Error") != std::string::npos)
			std::cout << std::endl;
		else
			std::cout << " => " << price << " = " << exchangeRate << std::endl;
	}
	file.close();
}
