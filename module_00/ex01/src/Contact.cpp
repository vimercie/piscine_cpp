/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:20:49 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/28 01:01:38 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

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

std::string	*Contact::get_data_type(std::string type)
{
	if (type.compare("first name") == 0)
		return (&this->first_name);
	if (type.compare("last name") == 0)
		return (&this->last_name);
	if (type.compare("nickname") == 0)
		return (&this->nickname);
	if (type.compare("phone number") == 0)
		return (&this->phone_number);
	if (type.compare("darkest secret") == 0)
		return (&this->darkest_secret);
	return (NULL);
}

int	Contact::list(int index)
{
	if (this->first_name.empty())
		return (0);
	std::cout << '|' << "         " << index;
	print_in_tab(this->first_name);
	print_in_tab(this->last_name);
	print_in_tab(this->nickname);
	std::cout << '|' << std::endl;
	return (1);
}

void	Contact::display(void)
{
	std::cout << "\nFirst name =\t\t" << this->first_name << std::endl;
	std::cout << "Last name =\t\t" << this->last_name << std::endl;
	std::cout << "Nickname =\t\t" << this->nickname << std::endl;
	std::cout << "Phone number =\t\t" << this->phone_number << std::endl;
	std::cout << "darkest secret =\t" << this->darkest_secret << std::endl << std::endl;
}

void	Contact::add(std::string type)
{
	std::string	*dest = this->get_data_type(type);

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
