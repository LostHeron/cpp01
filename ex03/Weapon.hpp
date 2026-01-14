/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:50:33 by jweber            #+#    #+#             */
/*   Updated: 2026/01/07 15:38:48 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define  WEAPON_HPP

# include <string>

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon(std::string);
		~Weapon();
		const std::string&	getType(void) const;
		void				setType(const std::string& newType);
};

#endif
