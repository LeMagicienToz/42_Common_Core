/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 08:08:12 by muteza            #+#    #+#             */
/*   Updated: 2023/12/01 03:37:52 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename ARRAY, typename SIZE>
void iter(ARRAY *tab, SIZE const size, void(*f)(ARRAY const & i))
{
	for (SIZE i = 0; i < size; i++)
		(*f)(tab[i]);
}

template <typename ARRAY>
void view(ARRAY const & i)
{
	std::cout << i << std::endl;
}

#endif