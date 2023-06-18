/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:27:53 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/14 18:44:33 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool	PhoneBook::print_contact_list(Contact contact[8])
{
	if (contact[0].first_name.empty())
	{
		std::cout << "NO SHIT" << std::endl;
		return (0);
	}
	std::cout << "*----------*----------*----------*----------*" << std::endl;
	for (int i = 0; i <= 7; i++)
	{
		if (contact[i].first_name.empty())
			break ;
		std::cout << i << std::endl;
	}
	std::cout << "*----------*----------*----------*----------*" << std::endl;
}

void	PhoneBook::search_contact(Contact contact[8])
{
	if (contact[0].first_name.empty())
	{
		std::cout << "NO SHIT" << std::endl;
		return ;
	}
	std::cout << "*----------*----------*----------*----------*" << std::endl;
	for (int i = 0; i <= 7; i++)
	{
		if (contact[i].first_name.empty())
			break ;
		std::cout << i << std::endl;
	}
}

void	PhoneBook::add_contact(Contact *contact)
{
	while (contact->first_name.empty())
	{
		std::cout << "Enter first name" << std::endl << "> ";
		std::getline(std::cin, contact->first_name);
		std::cout << std::endl;
	}
	while (contact->last_name.empty())
	{
		std::cout << "Enter last name" << std::endl << "> ";
		std::getline(std::cin, contact->last_name);
		std::cout << std::endl;
	}
	while (contact->nickname.empty())
	{
		std::cout << "Enter nickname" << std::endl << "> ";
		std::getline(std::cin, contact->nickname);
		std::cout << std::endl;
	}
	while (contact->phone_number.empty())
	{
		std::cout << "Enter phone number" << std::endl << "> ";
		std::getline(std::cin, contact->phone_number);
		std::cout << std::endl;
	}
	while (contact->darkest_secret.empty())
	{
		std::cout << "Enter darkest secret" << std::endl << "> ";
		std::getline(std::cin, contact->darkest_secret);
		std::cout << std::endl;
	}
}

int	main(void)
{
	PhoneBook	pb;
	std::string	buffer;
	int			i;

	i = 0;
	while (1)
	{
		std::cout << "PhoneBook> ";
		std::getline(std::cin, buffer);
		if (buffer == "ADD")
		{
			pb.contacts[i].index = i + 1;
			pb.add_contact(&pb.contacts[i]);
			i = (i < 7) ? i + 1 : i = 0;
		}
		if (buffer == "SEARCH")
			pb.search_contact(pb.contacts);
		if (buffer == "EXIT")
			return (1);
	}
	return (0);
}
