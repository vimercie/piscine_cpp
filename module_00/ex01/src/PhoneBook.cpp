/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:27:53 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/22 16:24:00 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

void	print_in_tab(std::string str)
{
	std::string	ws;

	if (str.size() < 10)
	{
		ws = "          ";
		ws.resize(ws.size() - str.size());
		ws.append(str);
		str = ws;
	}
	else if (str.size() > 10)
	{
		str.resize(10);
		str[str.size() - 1] = '.';
	}
	std::cout << "|" << str;
}

int	PhoneBook::print_contact_list()
{
	int	index;

	for (index = 0; index <= 7; index++)
	{
		if (!this->contacts[index].list(index + 1))
			break ;
	}
	return (index);
}

void	PhoneBook::search_contact()
{
	std::string	buffer;
	int			list_size;
	int			index;

	list_size = this->print_contact_list();
	if (list_size == 0)
	{
		std::cout << "No contact yet" << std::endl;
		return ;
	}
	std::cout << "\nEnter a contact index" << std::endl;
	std::getline(std::cin, buffer);
	index = atoi(buffer.c_str());
	if (index < 1 || index > list_size)
	{
		if (!std::cin.eof())
			std::cout << "\nNot a valid index\n" << std::endl;
		return ;
	}
	this->contacts[index - 1].display();
}

void	PhoneBook::add_contact(int index)
{
	this->contacts[index - 1].add("first name");
	this->contacts[index - 1].add("last name");
	this->contacts[index - 1].add("nickname");
	this->contacts[index - 1].add("phone number");
	this->contacts[index - 1].add("darkest secret");
}


int	main(void)
{
	PhoneBook	pb;
	std::string	buffer;
	int			index;

	index = 1;
	while (1)
	{
		std::cout << "PhoneBook> ";
		std::getline(std::cin, buffer);
		if (buffer == "ADD")
		{
			pb.add_contact(index);
			if (index < 8)
				index++;
			else
				index = 1;
		}
		if (buffer == "SEARCH")
			pb.search_contact();
		if (buffer == "EXIT" || std::cin.eof())
			return (1);
	}
	return (0);
}
