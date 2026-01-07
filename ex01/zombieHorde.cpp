/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:28:03 by jweber            #+#    #+#             */
/*   Updated: 2026/01/07 14:33:34 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*ptr_zombie = new Zombie[N];
	for (int i = 0; i < N; i++)
		ptr_zombie[i].set_name(name);
	return (ptr_zombie);
}
