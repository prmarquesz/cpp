/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:45:39 by proberto          #+#    #+#             */
/*   Updated: 2023/06/08 17:40:43 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <stack>

class RPN {
	private: 
		RPN(void);
		static int calculate(int a, int b, char op);
	
	public: static int apply(std::string expression);
};
