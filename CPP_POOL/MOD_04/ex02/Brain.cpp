/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:17:11 by muteza            #+#    #+#             */
/*   Updated: 2023/10/15 18:17:22 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain called" << std::endl;
}

Brain::Brain(Brain const & src)
{
	*this = src;
	return ;
}

Brain::~Brain(void)
{
	std::cout << "Brain destroy" << std::endl;
	return ;
}

Brain &	Brain::operator=(Brain const & rhs)
{
	if (this != &rhs)
		for (int i = 0; i < 100; i++)
			this->ideas[i]	= rhs.ideas[i];
	return (*this);
}

void	Brain::setIdeas(std::string const ideas, int const i)
{
	if (i >= 100)
		return ;
	this->ideas[i] = ideas;
	return ;
}

void	Brain::viewIdeas(void)
{
	for (int i = 0; i < 100; i++)
		if (!this->ideas[i].empty())
			std::cout << this->ideas[i] << std::endl;
	return ;
}