/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 04:04:22 by muteza            #+#    #+#             */
/*   Updated: 2023/12/08 13:30:14 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
//const 

Serializer::Serializer( void ) {}

Serializer::Serializer( Serializer const &src ) 
{ 
	*this = src;
}

Serializer::~Serializer( void ) {}

// member function

uintptr_t	Serializer::serialize( Data *ptr ) 
{ 
	return (reinterpret_cast<uintptr_t>(ptr)); 
}

Data	*Serializer::deserialize( uintptr_t x ) 
{ 
	return (reinterpret_cast<Data *>(x));
}

//Assignement 

Serializer	&Serializer::operator=( Serializer const &rhs ) {

	(void) rhs;

	std::cout << "Nothing to assign." << std::endl;
	return (*this);
}
