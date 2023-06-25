/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:26:55 by proberto          #+#    #+#             */
/*   Updated: 2023/05/27 14:46:09 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Data {
	
	private:
		std::string username;
		std::string passwd;
	
	public:
		~Data(void);
		Data(void);
		Data(const std::string username, const std::string passwd);
		Data(const Data &src);
		Data &operator=(const Data &src);

		std::string getUsername(void) const;
		std::string getPasswd(void) const;
		void setUsername(const std::string username);
		void setPasswd(const std::string passwd);
};

std::ostream &operator<<(std::ostream &os, const Data &data);
