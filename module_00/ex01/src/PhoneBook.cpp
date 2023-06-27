/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:27:53 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/27 19:53:33 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

static bool	isalnum_str(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!isalnum(str[i]))
			return (false);
		i++;
	}
	return (true);
}

void	PhoneBook::print_in_tab(std::string str)
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

int	PhoneBook::print_contact_list(PhoneBook pb)
{
	int	i;

	for (i = 0; i <= 7; i++)
	{
		if (pb.contacts[i].first_name.empty())
			break ;
		std::cout << '|' << "         " << i + 1;
		pb.print_in_tab(pb.contacts[i].first_name);
		pb.print_in_tab(pb.contacts[i].last_name);
		pb.print_in_tab(pb.contacts[i].nickname);
		std::cout << '|' << std::endl;
	}
	return (i);
}

void	PhoneBook::search_contact(PhoneBook pb)
{
	std::string	buffer;
	int			list_size;
	int			n;

	list_size = pb.print_contact_list(pb);
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
	std::cout << "\nFirst name =\t\t" << pb.contacts[n - 1].first_name << std::endl;
	std::cout << "Last name =\t\t" << pb.contacts[n - 1].last_name << std::endl;
	std::cout << "Nickname =\t\t" << pb.contacts[n - 1].nickname << std::endl;
	std::cout << "Phone number =\t\t" << pb.contacts[n - 1].phone_number << std::endl;
	std::cout << "darkest secret =\t" << pb.contacts[n - 1].darkest_secret << std::endl << std::endl;
}

void	PhoneBook::add_contact(std::string *dest, std::string type)
{
	if (std::cin.eof())
		return ;
	if (!(*dest).empty())
		(*dest).clear();
	while ((*dest).empty())
	{
		std::cout << "Enter " << type << std::endl << "> ";
		std::getline(std::cin, *dest);
		if (std::cin.eof())
			return ;
		if (!isalnum_str(*dest))
		{
			(*dest).clear();
			std::cerr << "\nOnly letters or numbers." << std::endl;
		}
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
			pb.add_contact(&pb.contacts[i].first_name, "first name");
			pb.add_contact(&pb.contacts[i].last_name, "last name");
			pb.add_contact(&pb.contacts[i].nickname, "nickname");
			pb.add_contact(&pb.contacts[i].phone_number, "phone number");
			pb.add_contact(&pb.contacts[i].darkest_secret, "darkest secret");
			if (i < 7)
				i++;
			else
				i = 0;
		}
		if (buffer == "SEARCH")
			pb.search_contact(pb);
		if (buffer == "EXIT" || buffer.empty() || std::cin.eof())
			return (1);
	}
	return (0);
}
