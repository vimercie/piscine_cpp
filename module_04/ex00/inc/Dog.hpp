/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:16:33 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/04 15:35:50 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include <iostream>

# include "Animal.hpp"

class	Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& src);
		virtual ~Dog();

		Dog&			operator=(const Dog& src);

		virtual void	makeSound() const;
};

#endif