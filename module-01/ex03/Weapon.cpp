/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:55:55 by proberto          #+#    #+#             */
/*   Updated: 2022/08/19 22:45:26 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::~Weapon(void) {}

Weapon::Weapon(std::string type) : type(type) {}

const std::string &Weapon::getType() const {
	return this->type;
}

void Weapon::setType(std::string type) {
	this->type = type;
}
