/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 08:08:12 by muteza            #+#    #+#             */
/*   Updated: 2024/02/21 11:49:41 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm> //std::find
#include <vector>

class NoOccurence : public std::exception {
	public:
		const char *what() const throw() {return ( "Pas d'occurence trouvé ! 👻 ");};
	};

template< typename T >

	int easyfind( const T container, int val)
	{
		typename T::const_iterator it = std::find(container.begin(), container.end(), val);
		if (it != container.end())
		{
			std::cout << "Occurence found at position : " ;
			return (std::distance(container.begin(), it));

		}
		else 
		{
			throw NoOccurence();
		}
	}

#endif
