/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 06:35:00 by muteza            #+#    #+#             */
/*   Updated: 2023/09/26 05:24:57 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed {
	
	public:
		/*Constructeur, Destrucrteur */
			Fixed(); //constructeur default
			Fixed(const int val); // int constructor
			Fixed(const float valFloat); // float constructor
			Fixed( Fixed const &src );// copy constructeur
			~Fixed();
		/*ASSIGNEMENT*/	
			Fixed	&operator=(Fixed const &op); //overloard operator
			int 	toInt() const;
			float	toFloat() const;
			void	setRawBits( int const raw );
			int		getRawBits() const;
	private:
			int	_value;
			static const int _fracbit;
};
std::ostream	&operator<<( std::ostream &o, Fixed const &i );

#endif