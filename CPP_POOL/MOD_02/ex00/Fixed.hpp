/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 06:35:00 by muteza            #+#    #+#             */
/*   Updated: 2023/09/26 04:27:58 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed {
	
	public:
		/*Constructeur, Destrucrteur */
			Fixed(); //constructeur
			Fixed( Fixed const &src );// copy constructeur
			~Fixed();
		/*ASSIGNEMENT*/	
			Fixed	&operator=(Fixed const &op); //overloard operator
			void	setRawBits( int const raw );
			int		getRawBits() const;
	private:
			int	_value;
			static const int _fracbit;
};
// std::ostream	&operator<<( std::ostream &o, Fixed const &i );

#endif