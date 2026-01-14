/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:23:45 by jweber            #+#    #+#             */
/*   Updated: 2026/01/12 11:24:03 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"
#include "Weapon.hpp"


HumanB::HumanB(const std::string& str) : name(str), ptr_weapon(NULL)
{
	std::cout << "HumanB constructor called" << std::endl;
}

void	HumanB::attack(void)
{
	if (this->ptr_weapon == NULL)
		std::cout << this->name << " does not have a weapon" << std::endl;
	else
		std::cout << this->name << " attack with their " << this->ptr_weapon->getType()
		<< std::endl;
}

void	HumanB::setWeapon(Weapon& newWeapon)
{
	this->ptr_weapon = &newWeapon;
}

void	HumanB::unsetWeapon(void)
{
	this->ptr_weapon = NULL;
}

HumanB::~HumanB()
{
	std::cout << "HumanB destructor called" << std::endl;
}
