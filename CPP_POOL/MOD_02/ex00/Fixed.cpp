/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 05:20:24 by muteza            #+#    #+#             */
/*   Updated: 2023/10/06 15:30:50 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fracbit = 8;

//constructor

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) : _value(0)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

//operators

Fixed	&Fixed::operator=(Fixed const &op) {

	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = op.getRawBits();

	return (*this);
}

//destructor

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;	
}

//Member function 

void	Fixed::setRawBits(int const raw) 
{

	this->_value = raw;
	return ;
}

int	Fixed::getRawBits() const
{

	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}


// std::ostream	&operator<<( std::ostream &o, Fixed const &i )
// {

// 	(void) i;
// 	return (o);
// }
