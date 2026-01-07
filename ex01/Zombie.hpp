/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:27:17 by jweber            #+#    #+#             */
/*   Updated: 2026/01/07 14:29:10 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	private:
		std::string	name;

	public:
		~Zombie();
		void		announce(void);
		void		set_name(const std::string& name);
		std::string	get_name(void);
};


Zombie* zombieHorde( int N, std::string name );

#endif
