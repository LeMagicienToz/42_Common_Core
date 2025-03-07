/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 08:07:54 by muteza            #+#    #+#             */
/*   Updated: 2023/12/08 13:29:57 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.h"

int	main(void)
{
	Data	a;
	a.value = 42;

	std::cout << a.value << std::endl;

	uintptr_t	b = Serializer::serialize(&a);

	std::cout << b << std::endl;
	std::cout << Serializer::deserialize(b)->value << std::endl;

	return (0);
}
