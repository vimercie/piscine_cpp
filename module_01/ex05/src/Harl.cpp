/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:11:03 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/16 22:12:43 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

Harl::Harl()
{
	this->complaintMap.insert(std::make_pair("DEBUG", &Harl::debug));
	this->complaintMap.insert(std::make_pair("INFO", &Harl::info));
	this->complaintMap.insert(std::make_pair("WARNING", &Harl::warning));
	this->complaintMap.insert(std::make_pair("ERROR", &Harl::error));
}

void    Harl::complain(std::string level)
{
	std::map<std::string, void (Harl::*)()>::iterator i = complaintMap.find(level);

	if (i != this->complaintMap.end())
		(this->*(i->second))();
	else
		std::cout << "I be poppin' nothing :(" << std::endl;
}

void    Harl::debug()
{
	std::cout << "I be poppin' bottles of Champagne" << std::endl;
}

void    Harl::info()
{
	std::cout << "I BE POPPIN' BOTTLES" << std::endl;
}

void    Harl::warning()
{
	std::cout << "I shall be poppin' bottles" << std::endl;
}

void    Harl::error()
{
	std::cout << "I ain't poppin' bottles" << std::endl;
}
