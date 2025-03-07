/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 06:35:00 by muteza            #+#    #+#             */
/*   Updated: 2023/10/02 10:41:44 by muteza           ###   ########.fr       */
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
		//operator
			bool	operator<=(Fixed const &other) const;
			bool	operator>=(Fixed const &other) const;
			bool	operator==(Fixed const &other) const;
			bool	operator!=(Fixed const &other) const;
			bool	operator<(Fixed const &other) const;
			bool	operator>(Fixed const &other) const;

			Fixed	operator+(Fixed const &rhs) const;
			Fixed	operator-(Fixed const &rhs) const;
			Fixed	operator*(Fixed const &rhs) const;
			Fixed	operator/(Fixed const &rhs) const;

			Fixed	&operator=(Fixed const &rhs);
			
			Fixed	&operator++(void);
			Fixed	&operator--(void);

			Fixed	operator++(int increment);
			Fixed	operator--(int decrement);

			static Fixed		max( Fixed &x, Fixed &y ) ;
			static const Fixed	max( Fixed const &x, Fixed const &y ) ;

			static Fixed		min( Fixed &x, Fixed &y ) ;
			static const Fixed	min( Fixed const &x, Fixed const &y ) ;
		/*ASSIGNEMENT*/	
			int 	toInt() const;
			float	toFloat() const;
			void	setRawBits( int const raw );
			int		getRawBits() const;
	private:
			int	_bits;
			static const int _fracbit;
};
std::ostream	&operator<<( std::ostream &o, Fixed const &i );

#endif