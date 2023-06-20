/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:27:12 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/21 01:26:18 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cstdio>
# include "Contact.hpp"

class	PhoneBook
{
	public:
		Contact contacts[8];
		void	add_contact(std::string *dest, std::string type);
		void	search_contact(PhoneBook pb);
	private:
		int		print_contact_list(PhoneBook pb);
		void	print_in_tab(std::string str);
};

#endif