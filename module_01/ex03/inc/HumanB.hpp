/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:10:56 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/30 19:42:40 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class	HumanB
{
	public:
		HumanB(std::string name);

		void	attack(void);
		void	setWeapon(Weapon &weapon);
	private:
		std::string	name;
		Weapon		*weapon;
};

#endif
