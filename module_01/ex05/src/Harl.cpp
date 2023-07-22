/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:11:03 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/22 14:54:54 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

Harl::Harl()
{
	ptr_tab[0] = &Harl::debug;
	ptr_tab[1] = &Harl::info;
	ptr_tab[2] = &Harl::warning;
	ptr_tab[3] = &Harl::error;

	str_tab[0] = "DEBUG";
	str_tab[1] = "INFO";
	str_tab[2] = "WARNING";
	str_tab[3] = "ERROR";
}

void    Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (level.compare(this->str_tab[i]) == 0)
		{
			(this->*ptr_tab[i])();
			return ;
		}
	}
	std::cout << "Nothin' to pop (wrong level argument)" << std::endl;
}

void    Harl::debug()
{
	std::cout << "I be poppin' bottles of Champagne (debug)" << std::endl;
}

void    Harl::info()
{
	std::cout << "I BE POPPIN' BOTTLES (info)" << std::endl;
}

void    Harl::warning()
{
	std::cout << "I shall be poppin' bottles (warning)" << std::endl;
}

void    Harl::error()
{
	std::cout << "I ain't poppin' bottles (error)" << std::endl;
}
