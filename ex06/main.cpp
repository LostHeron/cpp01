/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:39:20 by jweber            #+#    #+#             */
/*   Updated: 2026/01/14 18:49:27 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	Harl a;

	if (argc != 2)
	{
		std::cout << "usage : ./HarlFilter \"level\"" << std::endl;
		return (1);
	}
	a.complain(argv[1]);
}
