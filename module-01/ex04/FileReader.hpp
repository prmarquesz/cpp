/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReader.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 00:18:56 by proberto          #+#    #+#             */
/*   Updated: 2022/08/21 13:30:39 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <sstream>
#include <exception>

class FileReader {
	private:
		std::ifstream ifs;

	public:
		FileReader(const char *file);
		~FileReader(void);
		std::string readEntire(void);
};
