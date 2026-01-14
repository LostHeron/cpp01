/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:15:53 by jweber            #+#    #+#             */
/*   Updated: 2026/01/12 11:23:32 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
	public:
		HumanB(const std::string& str);
		~HumanB();
		void	unsetWeapon(void);
		void	setWeapon(Weapon& newWeapon);
		void	attack(void);

	private:
		std::string	name;
		Weapon		*ptr_weapon;
};

#endif
