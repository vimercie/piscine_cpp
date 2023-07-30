/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:19:52 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/30 17:44:09 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class	Brain
{
	private:
		std::string	*ideas;
	public:
		Brain();
		Brain(const Brain& src);
		~Brain();

		Brain&	operator=(const Brain& src);
};

#endif