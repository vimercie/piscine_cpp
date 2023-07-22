/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:10:39 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/22 14:44:26 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>


class   Harl
{
    public:
        Harl();

        void    complain(std::string level);
    private:
		typedef void	(Harl::*ft_ptr)(void);

		std::string	str_tab[4];
		ft_ptr		ptr_tab[4];

        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);
};

#endif