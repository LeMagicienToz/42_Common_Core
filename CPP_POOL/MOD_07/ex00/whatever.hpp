/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 08:08:12 by muteza            #+#    #+#             */
/*   Updated: 2023/11/30 04:37:25 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void	swap(T &x, T &y ) 
{

	T swap;

	swap = x;
	x = y;
	y = swap;
}

template< typename T >
T const	&min(T const &x, T const &y)
{
	return ( x < y ? x : y ); 
}

template< typename T >
T const	&max(T const &x, T const &y)
{
	return ( x > y ? x : y ); 
}

#endif