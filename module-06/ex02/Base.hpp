/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:37:04 by proberto          #+#    #+#             */
/*   Updated: 2023/05/27 15:13:31 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

class Base { public: virtual ~Base(void); };

class A : public Base {};
class B : public Base {};
class C : public Base {};
class D;

Base * generate(void);
void identify(Base* p);
void identify(Base& p);
