/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:27:12 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/28 18:37:43 by vimercie         ###   ########lyon.fr   */
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
		void	add_contact(int index);
		void	search_contact(void);
	private:
		int		print_contact_list(void);

		Contact contacts[8];
};

#endif