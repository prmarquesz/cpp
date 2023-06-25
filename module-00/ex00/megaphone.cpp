/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:45:34 by proberto          #+#    #+#             */
/*   Updated: 2023/03/12 17:56:09 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	std::string msg;

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++) {
		msg = argv[i];	
		for (std::string::iterator it = msg.begin(); it != msg.end(); it++) {
			std::cout << (char)std::toupper(*it);
		}
	}
	std::cout << std::endl;
	return (0);
}
