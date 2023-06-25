/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 01:35:45 by proberto          #+#    #+#             */
/*   Updated: 2023/03/13 00:04:01 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::~Contact() {};

Contact::Contact() {};

Contact::Contact(
	std::string firstName, 
	std::string lastName, 
	std::string nickName, 
	std::string phoneNumber, 
	std::string darkestSecret
): 	firstName(firstName),
	lastName(lastName),
	nickName(nickName),
	phoneNumber(phoneNumber),
	darkestSecret(darkestSecret)
{
	nameValidation(this->firstName, "First name");
	nameValidation(this->lastName, "Last name");
	nameValidation(this->nickName, "Nick name");
	phoneNumberValidation(this->phoneNumber);
	if (this->darkestSecret.empty())
		throw std::invalid_argument(
			"Darkest secret cannot be empty \n"
			"sad :(, it seems you don't trust me"
		);
	this->createdAt = std::time(NULL);
}

void Contact::nameValidation(std::string name, std::string field) {
	if (name.length() < 2)
		throw std::invalid_argument("Invalid " + field + "!");
	for (std::string::iterator it = name.begin(); it != name.end(); it++)
		if (!std::isalpha(*it))
			throw std::invalid_argument("Invalid " + field + "!");
}

void Contact::phoneNumberValidation(std::string number){
	std::string presets = "*#+-(),;";

	if (number.length() < 7)
		throw std::invalid_argument("Invalid phone number!");
	for (std::string::iterator it = number.begin(); it != number.end(); it++)
		if (!std::isdigit(*it) && presets.find(*it) == std::string::npos)
			throw std::invalid_argument("Invalid phone number!");
}

std::string Contact::getName() {
	return firstName;
}

std::string Contact::getLastName() {
	return lastName;
}

std::string Contact::getNickName() {
	return nickName;
}

std::string Contact::getPhoneNumber() {
	return phoneNumber;
}

std::string Contact::getDarkestSecret() {
	return darkestSecret;
}

std::time_t Contact::getCreatedAt() {
	return createdAt;
}
