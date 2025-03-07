/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 02:56:52 by muteza            #+#    #+#             */
/*   Updated: 2023/12/02 03:07:13 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

template< typename T = int >
class Array {

public:

/*------------- CONST / DEST --------------*/
	Array( void ) : _n( 0 ) 
	{ 
		std::cout << "Default constructor called size of :" << this->_n << std::endl; 
	};
	Array( unsigned int n ) : _n( n ) 
	{
		this->_array = new T[ this->_n ]; 
		std::cout << "Inital constructor called with size of :" << this->_n << std::endl; 
	};
	Array( Array<T> const &src ) 
	{ 
		*this = src; 
		std::cout << "Copy constructor called with size of :" << this->_n << std::endl; 
	};
	~Array( void ) 
	{
		std::cout << "Destructor called with Size of : " << this->_n << std::endl; 
	};

	size_t	size( void ) const 
	{ 
		return ( this->_n ); 
	};

/*----------- OPERATORS OVERLOAD ----------*/
	Array<T>	&operator=( Array<T> const &rhs )
	{ 
		if (this != &rhs) 
		{
			this->_array = rhs._array;
			this->_n = rhs._n;
		} 
		std::cout << "Operator Overload" << std::endl; 
		return (*this); 
		};
	T			&operator[]( size_t i ) 
	{ 
		if (i >= this->_n) 
			throw std::out_of_range("Error OUT OF RANGE"); 
		return (this->_array[ i ]); 
	};

private:

	T		*_array;
	size_t	_n;

};