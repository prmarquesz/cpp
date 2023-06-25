/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:58:21 by proberto          #+#    #+#             */
/*   Updated: 2023/03/13 00:06:18 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "PhoneBook.hpp"

std::string prompt(std::string request) {
	std::string	cmd;

	std::cout << request << std::endl << ">> ";
	std::getline(std::cin, cmd);
	std::cout << std::endl;
	if (!std::cin)
		std::exit(1);
	return (cmd);
}

Contact contactForm() {
	std::cout << "Please enter new contact information:" << std::endl;
	return (
		Contact (
			prompt("First Name: "),
			prompt("Last Name: "),
			prompt("Nick Name: "),
			prompt("Phone Number: "),
			prompt("Darkest Secret: ")
		)
	);
}

int main() {
	std::string command;
	PhoneBook phoneBook;

	while (true) {
		command = prompt("Please enter one of three commands (ADD, SEARCH and EXIT): ");
		if (command == "EXIT")
			break ;
		try {
			if (command == "ADD") {
				std::cout << CLEAR << std::endl;
				phoneBook.addContact(contactForm());
			}
			else if (command == "SEARCH") {
				if (phoneBook.contactsSize() == 0)
					throw std::runtime_error("There are no contacts in the phone book.");
				phoneBook.displayContacts();
				phoneBook.searchContactByIndex(prompt("Please enter contact index to view it: "));
			}
			else
				throw std::invalid_argument("Invalid command!");
		} catch (std::exception& e) {
			std::cout << CLEAR << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	return (0);
}
