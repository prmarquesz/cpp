/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:45:39 by proberto          #+#    #+#             */
/*   Updated: 2023/06/24 14:44:45 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

RPN::RPN(void) {}

int RPN::calculate(int x, int y, char op) {
	switch (op) {
		case '+':
			return (x + y);
		case '-':
			return (x - y);
		case '*':
			return (x * y);
		case '/':
			if (y == 0)
				throw std::invalid_argument("Error: division by zero");
			return (x / y);
	}
	return (0);
}

int RPN::apply(std::string expression) {
	std::stack<int> operations;
	std::string tokens = "+-/*";

	for (std::string::iterator it = expression.begin(); it != expression.end(); it++) {
		if (std::isdigit(*it))
			operations.push(static_cast<int>(*it) - 48);
		else if (tokens.find(*it) != std::string::npos) {
			if (operations.size() < 2)
				throw std::invalid_argument("Invalid expression");
			int y = operations.top();
			operations.pop();
			int x = operations.top();
			operations.pop();
			operations.push(calculate(x, y, *it));
		} else
			throw std::invalid_argument("Bad input");
	}
	if (operations.size() != 1)
		throw std::invalid_argument("Invalid expression");
	return (operations.top());
}
