/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:34:44 by jweber            #+#    #+#             */
/*   Updated: 2026/01/07 14:00:44 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie	zombie;
	Zombie	*allocated_zombie;

	zombie.set_name("foo");
	zombie.announce();
	zombie.set_name("ahah");
	zombie.announce();
	allocated_zombie = newZombie("new_zombie_eheh");
	allocated_zombie->announce();
	delete allocated_zombie;
	std::cout << "calling randomChump(\"yo_la_team\")" << std::endl;
	randomChump("yo_la_team");
	std::cout << "outside of randomChump()" << std::endl;
	return (0);
}

Zombie	*newZombie(std::string name)
{
	Zombie *ptr_zombie = new Zombie;

	ptr_zombie->set_name(name);
	return (ptr_zombie);
}

void	randomChump(std::string name)
{
	Zombie zombie;

	zombie.set_name(name);
	zombie.announce();
}
