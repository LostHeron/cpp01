/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:22:07 by jweber            #+#    #+#             */
/*   Updated: 2026/01/12 11:24:07 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"


HumanA::HumanA(const std::string& str, Weapon& newWeapon) : name(str), weapon(newWeapon)
{
	std::cout << "HumanA constructor called !" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attack with their " << this->weapon.getType()
		<< std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA desctructor called" << std::endl;
}
