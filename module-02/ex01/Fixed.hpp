/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 06:37:45 by proberto          #+#    #+#             */
/*   Updated: 2022/09/10 11:54:03 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed {
	private:
		static const int	fractionalBits;
		int					rawBits;
	
	public:
		Fixed(void);
		Fixed(const int num);
		Fixed(const float num);
		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed &operator=(Fixed const &src);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);
