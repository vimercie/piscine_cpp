/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:42:59 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/26 16:02:32 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class	Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();

		const std::string	&getType(void);
		void				setType(std::string str);
	private:
		std::string			type;
};

#endif
