/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 00:01:46 by proberto          #+#    #+#             */
/*   Updated: 2023/03/13 01:18:11 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
#include "Contact.hpp"

#define MAX_CONTACTS	8
#define COL_WIDTH		10
#define CLEAR			"\x1B[2J\x1B[H"

class PhoneBook {
	private:
		Contact	contacts[MAX_CONTACTS];

	private:
		short	findOldestContact();
		void	printFormattedField(std::string field);

	public:
		short	contactsSize();
		void	addContact(Contact contact);
		void	displayContacts();
		void	searchContactByIndex(std::string index);
};
