/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:26:38 by jweber            #+#    #+#             */
/*   Updated: 2026/01/15 10:27:31 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void	Harl::complain(std::string level)
{
	void	(Harl::*f[4])(void);
	std::string	str[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};

	f[0] = &Harl::debug;
	f[1] = &Harl::info;
	f[2] = &Harl::warning;
	f[3] = &Harl::error;
	for (int i = 0; i < 4; i++)
	{
		if (str[i] == level)
		{
			switch (i) {
				case 0:
					(this->*f[0])();
					__attribute__((fallthrough)); /* must use if adding -Weverything in compile flags*/
					//[[fallthrough]]; /* new style but only available since C++17 */
				case 1:
					(this->*f[1])();
					//[[fallthrough]];
					__attribute__((fallthrough));
				case 2:
					(this->*f[2])();
					//[[fallthrough]];
					__attribute__((fallthrough));
				case 3:
					(this->*f[3])();
			}
			return ;
		}
	}
	std::cout << "'" << level << "' is not a known level !" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "debug message" << std::endl;
}


void Harl::info(void)
{
	std::cout << "info message" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "warning message" << std::endl;
}

void Harl::error(void)
{
	std::cout << "error message" << std::endl;
}

