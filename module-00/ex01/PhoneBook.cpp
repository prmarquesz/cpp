/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 01:44:04 by proberto          #+#    #+#             */
/*   Updated: 2023/03/13 02:39:53 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

short PhoneBook::contactsSize() {
	short size = 0;

	for (short i = 0; i < MAX_CONTACTS; i++) {
		if (contacts[i].getName() != "") {
			size++;
		}
	}
	return (size);
}

short PhoneBook::findOldestContact() {
	short 		index = 0;
	std::time_t	oldest = std::time(NULL);

	for (short i = 0; i < this->contactsSize(); i++) {
		if (this->contacts[i].getCreatedAt() < oldest) {
			oldest = this->contacts[i].getCreatedAt();
			index = i;
		}
	}
	return (index);
}

void PhoneBook::addContact(Contact contact) {
	short i;

	if (this->contactsSize() < MAX_CONTACTS)
		i = this->contactsSize();
	else
		i = findOldestContact();
	this->contacts[i] = contact;
	std::cout << CLEAR << "Contact added!" << std::endl;
}

void PhoneBook::printFormattedField(std::string field) {
	std::string fmtField;

	fmtField = field.length() > COL_WIDTH ? 
		field.substr(0, COL_WIDTH).replace(COL_WIDTH - 1, 1, ".") : field;
	std::cout << std::right;
	std::cout << std::setw(COL_WIDTH);
	std::cout << fmtField;
	std::cout << "|";
}

void PhoneBook::displayContacts() {
	short size = this->contactsSize();

	std::cout << CLEAR << "Saved contacts" << std::endl;
	std::cout << "|";
	std::cout << "     index|";
	std::cout << "first name|";
	std::cout << " last name|";
	std::cout << " nick name|";
	std::cout << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (short i = 0; i < size; i++) {
		std::stringstream index;
		index << i;
		std::cout << "|";
		printFormattedField(index.str());
		printFormattedField(contacts[i].getName());
		printFormattedField(contacts[i].getLastName());
		printFormattedField(contacts[i].getNickName());
		std::cout << std::endl;
		std::cout << "---------------------------------------------";
		std::cout << std::endl;
	}
}

void PhoneBook::searchContactByIndex(std::string index) {
	if (index.empty() || (std::atoi(index.c_str()) == 0 && index.at(0) != '0'))
		throw std::invalid_argument("Wrong index: cannot be converted to int");
	
	short i = std::atoi(index.c_str());
	if (i > this->contactsSize() - 1 || i < 0)
		throw std::invalid_argument("Index out of range");
	std::cout << CLEAR << "Contact information: " << std::endl;
	std::cout << "First name: " << this->contacts[i].getName() << std::endl;
	std::cout << "Last name: " << this->contacts[i].getLastName() << std::endl;
	std::cout << "Nick name: " << this->contacts[i].getNickName() << std::endl;
	std::cout << "Phone number: " << this->contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[i].getDarkestSecret() << std::endl;
}
