/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 06:37:45 by proberto          #+#    #+#             */
/*   Updated: 2022/08/25 00:34:32 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed {
	private:
		static const int	fractionalBits;
		int					rawBits;
	
	public:
		Fixed(void);
		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed &operator=(Fixed const &src);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};
