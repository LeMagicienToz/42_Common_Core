/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:16:30 by muteza            #+#    #+#             */
/*   Updated: 2023/10/10 15:15:34 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_name			= "Default";
	this->_hitpoints	= 100;
	this->_energypoints	= 100;
	this->_attackdamage	= 30;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	this->_name			= name;
	this->_hitpoints	= 100;
	this->_energypoints	= 100;
	this->_attackdamage	= 30;
	std::cout << "FragTrap Named constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = src;
}

// Operator overload

FragTrap	&FragTrap::operator=(FragTrap const &rhs) {

	this->_name = rhs._name;
	this->_attackdamage = rhs._attackdamage;
	this->_energypoints = rhs._energypoints;
	this->_hitpoints = rhs._hitpoints;

	return (*this);
}

//member function

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name;
	std::cout << " Hey, high fives guys ?!";
	std::cout << std::endl;
}

// Destructor

FragTrap::~FragTrap()
{
	std::cout << " FragTrap Destructor called" << std::endl;	
}