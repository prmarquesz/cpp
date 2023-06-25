/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileWriter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:56:39 by proberto          #+#    #+#             */
/*   Updated: 2022/08/21 13:30:31 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <exception>

class FileWriter {
	private:
		std::ofstream ofs;

	public:
		FileWriter(std::string fileName);
		~FileWriter(void);
		void write(std::string text);
};
