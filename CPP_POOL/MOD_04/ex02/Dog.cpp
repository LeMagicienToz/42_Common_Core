/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:33:25 by muteza            #+#    #+#             */
/*   Updated: 2023/10/16 01:59:55 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(void)
{
	this->_type  = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog called" << std::endl;
}

Dog::Dog(Dog const & src) : Animal(src)
{
	*this = src;
	return ;
}

Dog::~Dog(void)
{
	std::cout << "Dog destroy" << std::endl;
	delete this->_brain;
	return ;
}

Dog &	Dog::operator=(Dog const & rhs)
{
	if (this != &rhs)
	{
		this->_type 	= rhs._type;
		this->_brain 	= new Brain();
		for (int i = 0; i < 100; i++)
			this->_brain->ideas[i]	= rhs._brain->ideas[i];
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouaff!" << std::endl;
	return ;
}

Brain*	Dog::getBrain(void) const
{
	return (this->_brain);
}