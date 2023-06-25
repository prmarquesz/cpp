/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:26:55 by proberto          #+#    #+#             */
/*   Updated: 2023/05/31 19:27:25 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T> void swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T> const T min(T &a, T &b) {
	return (a < b ? a : b);
}

template <typename T> const T max(T &a, T &b) {
	return (a > b ? a : b);
}
