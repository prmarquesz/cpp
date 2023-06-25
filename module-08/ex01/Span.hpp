/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:13:00 by proberto          #+#    #+#             */
/*   Updated: 2023/06/18 14:23:05 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

class Span {
	private:
		unsigned int		length;
		std::vector<int>	vector;

	public:
		~Span(void);
		Span(void);
		Span(unsigned int n);
		Span(const Span& other);

		Span&	operator=(const Span& other);

		void				addNumber(int n);
		void				fullFill(void);
		int					shortestSpan(void);
		int					longestSpan(void);
		unsigned int		getLength(void) const;
		std::vector<int>	getVector(void) const;
};

std::ostream&	operator<<(std::ostream& out, const Span& span);
