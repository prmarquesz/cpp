/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 00:04:00 by proberto          #+#    #+#             */
/*   Updated: 2023/03/12 15:56:15 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string.h>
#include <ctime>

class Contact {
	private:
		std::string 
			firstName,
			lastName,
			nickName,
			phoneNumber,
			darkestSecret;
		std::time_t
			createdAt;

	private:
		void nameValidation(std::string name, std::string field);
		void phoneNumberValidation(std::string number);
	
	public:
		Contact();
		Contact(
			std::string firstName,
			std::string lastName,
			std::string nickName,
			std::string phoneNumber,
			std::string darkestSecret
		);
		~Contact();
	
	public:
		std::string getName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
		std::time_t getCreatedAt();
};
