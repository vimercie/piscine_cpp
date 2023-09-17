/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:17:33 by vimercie          #+#    #+#             */
/*   Updated: 2023/09/18 01:18:26 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T &container, int N)
{
	typename T::iterator	val = std::find(container.begin(), container.end(), N);

	if (val == container.end())
		throw std::runtime_error("Value not found");
	return val;
}
