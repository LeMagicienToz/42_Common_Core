/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 05:20:24 by muteza            #+#    #+#             */
/*   Updated: 2023/10/02 16:45:12 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fracbit = 8;

//constructor

Fixed::Fixed() : _bits(0)
{
	std::cout << "Default constructeur called" << std::endl;
}

//copy constructor

Fixed::Fixed(Fixed const &src) : _bits(0)
{
	std::cout << "Copy constructeur called" << std::endl;
	*this = src;
}

//int constructor

Fixed::Fixed(const int val) : _bits(0)
{
	std::cout << "Int constructeur called" << std::endl;
	this->_bits = val << this->_fracbit;
}

//float constructor

Fixed::Fixed(const float valFloat) : _bits(0)
{
	std::cout << "Float constructeur called" << std::endl;
	this->_bits = roundf(valFloat * (1 << this->_fracbit));
}

//destructor

Fixed::~Fixed()
{
	std::cout << "Destructeur called" << std::endl;	
}

//operator overload

//operator < > <=  >= == !=

bool	Fixed::operator>=( const Fixed &other ) const {

	return (this->_bits >= other._bits);
}

bool	Fixed::operator<=( const Fixed &other ) const {

	return (this->_bits <= other._bits);
}

bool	Fixed::operator==( const Fixed &other ) const {

	return (this->_bits == other._bits);
}

bool	Fixed::operator!=( const Fixed &other ) const {

	return (this->_bits != other._bits);
}

bool	Fixed::operator<( const Fixed &other ) const {

	return (this->_bits < other._bits);
}

bool	Fixed::operator>( const Fixed &other ) const {

	return (this->_bits > other._bits);
}

//operator + - * /

Fixed	Fixed::operator+( const Fixed &rhs ) const {

	return (this->toFloat() + rhs.toFloat());
}


Fixed	Fixed::operator-( const Fixed &rhs ) const {

	return (this->toFloat() - rhs.toFloat());
}


Fixed	Fixed::operator*( const Fixed &rhs ) const {

	return (this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/( const Fixed &rhs ) const {

	return (this->toFloat() / rhs.toFloat());
}

//assignement

Fixed	&Fixed::operator=( Fixed const &rhs ) {

	this->_bits = rhs.getRawBits();

	return (*this);
}

// operator preincrementation and decrementation

Fixed	&Fixed::operator++( void ) {

	++this->_bits;
	return (*this);
}


Fixed	&Fixed::operator--( void ) {

	--this->_bits;
	return (*this);
}

//operator postincrementation and decrementation 

Fixed	Fixed::operator++( int increment ) {

	(void)increment;

	Fixed	temp = *this;
	this->_bits++;
	return (temp);
}

Fixed	Fixed::operator--( int decrement ) {

	(void)decrement;

	Fixed	temp = *this;
	this->_bits--;
	return (temp);
}

//Member function 

int	Fixed::toInt() const 
{

	return (this->_bits >> this->_fracbit);
}

float	Fixed::toFloat() const
{
	return ((float) this->_bits / (1 << this->_fracbit));
}

Fixed	Fixed::max( Fixed &x, Fixed &y) {

	return (x._bits < y._bits ? y : x);
}

const Fixed	Fixed::max( Fixed const &x, Fixed const &y) {

	return (x._bits < y._bits ? y : x);
}

Fixed	Fixed::min( Fixed &x, Fixed &y) {

	return (x._bits > y._bits ? y : x);
}

const Fixed	Fixed::min( Fixed const &x, Fixed const &y) {

	return (x._bits > y._bits ? y : x);
}

//accessor

void	Fixed::setRawBits(int const raw) 
{

	this->_bits = raw;
	return ;
}

int	Fixed::getRawBits() const
{
	return (this->_bits);
}

//not member ,  STREAM OUT
std::ostream	&operator<<( std::ostream &o, Fixed const &i ) {

	o << i.toFloat();
	return (o);
}
