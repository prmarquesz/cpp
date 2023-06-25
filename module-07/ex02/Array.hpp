/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:26:55 by proberto          #+#    #+#             */
/*   Updated: 2022/10/09 13:54:06 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>

template <typename T>
class Array {

	private:
		unsigned int length;
		T *array;

	public:
		~Array<T>(void) { 
			if (this->length)
				delete[] this->array;
			this->length = 0;
			this->array = NULL;
		}
		Array<T>(void) : length(0), array(NULL) {}
		Array<T>(unsigned int n) : length(n), array(NULL) {
			if (n)
				this->array = new T[n];
		}
		Array<T>(Array<T> const & src) : length(0), array(NULL) {
			if (this->length)
				this->array = new T[this->length];
			*this = src;
		}

		Array<T> & operator=(Array<T> const & src) {
			if (this != &src) {
				if (this->length)
					delete this->array;
				this->length = src.length;
				this->array = new T[src.length];
				for (unsigned int i = 0; i < src.length; i++)
					this->array[i] = src.array[i];
			}
			return *this;
		}
		
		T & operator[](unsigned int i) {
			if (i < 0 || i >= this->length)
				throw std::out_of_range("Index out of range");
			return this->array[i];
		}

		const T & operator[](unsigned int i) const {
			if (i < 0 || i >= this->length)
				throw std::out_of_range("Index out of range");
			return this->array[i];
		}

		unsigned int size() const { return this->length; }

};

template <typename T>
std::ostream & operator<<(std::ostream & os, Array<T> const & src) {
	for (unsigned int i = 0; i < src.size(); i++)
		os << src[i] << std::endl;
	return (os);
}
