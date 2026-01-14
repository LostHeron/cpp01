/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:51:06 by jweber            #+#    #+#             */
/*   Updated: 2026/01/14 18:49:17 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
	public:
		void	complain(std::string level);

	private:
		int		lvl;
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		void	(Harl::*f[4])(void);
};

#include <iostream>

void	Harl::complain(std::string level)
{
	f[0] = &Harl::debug;
	std::cout << level << ": ";
	(this->*f[0])();
	/*
	std::string str[4];

	str[0] = "DEBUG";
	str[1] = "INFO";
	str[2] = "WARNING";
	str[3] = "ERROR";
	for (int i = 0; i < 4; i++)
	{
		if (level == str[i])
		{
			(*f)[i]();
			return ;
		}
	}
	std::cout << "not a known classified level, chose bewteen"
		<< "'DEBUG', 'INFO', 'WARNING', 'ERROR'" << std::endl; 
	std::cout << "complain = " << level << std::endl;
	*/
}

void Harl::debug(void)
{
	std::cout << "debug message" << std::endl;
}

#endif
