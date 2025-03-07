/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:33:25 by muteza            #+#    #+#             */
/*   Updated: 2023/10/15 15:22:20 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->_type  = "Cat";
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
	return ;
}

Cat &	Cat::operator=(Cat const & rhs)
{
	if (this != &rhs)
		this->_type 	= rhs._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaou !" << std::endl;
}
