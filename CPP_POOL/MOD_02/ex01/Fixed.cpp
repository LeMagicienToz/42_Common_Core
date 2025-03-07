/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 05:20:24 by muteza            #+#    #+#             */
/*   Updated: 2023/09/26 05:26:22 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fracbit = 8;

//constructor

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructeur called" << std::endl;
}

Fixed::Fixed(Fixed const &src) : _value(0)
{
	std::cout << "Copy constructeur called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int val) : _value(0)
{
	std::cout << "Int constructeur called" << std::endl;
	this->_value = val << this->_fracbit;
}

Fixed::Fixed(const float valFloat) : _value(0)
{
	std::cout << "Float constructeur called" << std::endl;
	this->_value = roundf(valFloat * (1 << this->_fracbit));
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
	std::cout << "Destructeur called" << std::endl;	
}

//Member function 

int	Fixed::toInt() const 
{

	return (this->_value >> this->_fracbit);
}

float	Fixed::toFloat() const
{
	return ((float) this->_value / (1 << this->_fracbit));
}

void	Fixed::setRawBits(int const raw) 
{

	this->_value = raw;
	return ;
}

int	Fixed::getRawBits() const
{
	return (this->_value);
}

//not member ,  STREAM OUT
std::ostream	&operator<<( std::ostream &o, Fixed const &i ) {

	o << i.toFloat();
	return (o);
}
