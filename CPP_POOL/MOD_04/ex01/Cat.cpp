/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:33:25 by muteza            #+#    #+#             */
/*   Updated: 2023/10/16 01:58:55 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void)
{
	this->_type  = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat called" << std::endl;
}

Cat::Cat(Cat const & src) : Animal(src)
{
	*this = src;
	return ;
}

Cat::~Cat(void)
{
	std::cout << "Cat destroy" << std::endl;
	delete this->_brain;
	return ;
}

Cat &	Cat::operator=(Cat const & rhs)
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

void	Cat::makeSound(void) const
{
	std::cout << "Miaouuu!!" << std::endl;
	return ;
}

Brain*	Cat::getBrain(void) const
{
	return (this->_brain);
}