/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:54:37 by jweber            #+#    #+#             */
/*   Updated: 2026/01/07 15:40:01 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string str)
{
	std::cout << "Weapon constructor called" << std::endl;
	this->type = str;
}

const std::string&	Weapon::getType(void) const
{
	return (this->type);
}

void	Weapon::setType(const std::string& newType)
{
	this->type = newType;
}

Weapon::~Weapon()
{
	std::cout << "Weapon destructor called" << std::endl;
}
