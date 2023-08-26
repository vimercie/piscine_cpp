/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:08:18 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/14 13:47:22 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"
#include "../inc/Data.h"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& src) {*this = src;}

Serializer::~Serializer() {}

Serializer&	Serializer::operator=(const Serializer& src)
{
	(void)src;
	return *this;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t	raw;

	raw = reinterpret_cast<uintptr_t>(ptr);
	return raw;
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	Data	*data = reinterpret_cast<Data *>(raw);

	return data;
}
