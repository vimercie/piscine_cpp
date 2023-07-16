/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:10:39 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/16 21:50:31 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>
# include <map>

class   Harl
{
    public:
        Harl();
        void    complain(std::string level);
    private:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);

        std::map<std::string, void (Harl::*)()> complaintMap;
};

#endif