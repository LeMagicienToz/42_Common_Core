/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:29:30 by muteza            #+#    #+#             */
/*   Updated: 2023/10/15 17:40:51 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructor 

Animal::Animal()
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(Animal const &src)
{
	std::cout << "Copy Animal constructor called" << std::endl;
	*this = src;
}

// Operator overload

Animal	&Animal::operator=(Animal const &rhs) {

	this->_type = rhs._type;

	return (*this);
}

//Accessor

std::string	const &Animal::getType(void) const
{
	return (this->_type);
}

//Member function

void	Animal::makeSound(void) const
{
	std::cout << "Global Default Animal noise" << std::endl;
}

// Destructor

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;	
}
