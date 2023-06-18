/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:27:12 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/14 18:43:16 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class	PhoneBook
{
	public:
		Contact contacts[8];
		bool	print_contact_list(Contact contact[8]);
		void	search_contact(Contact contact[8]);
		void	add_contact(Contact *contact);
};


#endif