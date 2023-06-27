/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:27:53 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/28 00:53:17 by vimercie         ###   ########lyon.fr   */
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
	int	i;

	for (i = 0; i <= 7; i++)
	{
		if (!this->contacts[i].list(i + 1))
			break ;
	}
	return (i);
}

void	PhoneBook::search_contact()
{
	std::string	buffer;
	int			list_size;
	int			n;

	list_size = this->print_contact_list();
	if (list_size == 0)
	{
		std::cerr << "No contact yet" << std::endl;
		return ;
	}
	std::cout << "\nEnter a contact index" << std::endl;
	std::getline(std::cin, buffer);
	n = atoi(buffer.c_str());
	if (n < 1 || n > list_size)
	{
		if (!std::cin.eof())
			std::cerr << "\nNot a valid index\n" << std::endl;
		return ;
	}
	this->contacts[n - 1].display();
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
			pb.contacts[i].add("first name");
			pb.contacts[i].add("last name");
			pb.contacts[i].add("nickname");
			pb.contacts[i].add("phone number");
			pb.contacts[i].add("darkest secret");
			if (i < 7)
				i++;
			else
				i = 0;
		}
		if (buffer == "SEARCH")
			pb.search_contact();
		if (buffer == "EXIT" || buffer.empty() || std::cin.eof())
			return (1);
	}
	return (0);
}
