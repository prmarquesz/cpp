/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:32:52 by proberto          #+#    #+#             */
/*   Updated: 2022/08/21 15:36:28 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class String {
	public:
		static std::string replace(
			std::string str,
			std::string from,
			std::string to
		);
		static std::string replaceAll(
			std::string str,
			std::string from,
			std::string to
		);
};
