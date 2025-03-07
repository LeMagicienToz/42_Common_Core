/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:43:42 by muteza            #+#    #+#             */
/*   Updated: 2023/10/11 16:37:56 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructor

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_name			= "Default";
	this->_hitpoints	= 100;
	this->_energypoints	= 50;
	this->_attackdamage	= 20;
	this->_keepmod = false;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	this->_name			= name;
	this->_hitpoints	= 100;
	this->_energypoints	= 50;
	this->_attackdamage	= 20;
	this->_keepmod = false;
	std::cout << "ScavTrap Named constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = src;
}

// Operator overload

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs) {

	this->_name = rhs._name;
	this->_attackdamage = rhs._attackdamage;
	this->_energypoints = rhs._energypoints;
	this->_hitpoints = rhs._hitpoints;

	return (*this);
}

//member function


void	ScavTrap::attack(const std::string& target)
{
	if (this->_hitpoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is already DEAD his Hit Points : " 
		<< this->_hitpoints << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " tabasse " << target
		<< ", causing " << this->_attackdamage << " points of damage!" << std::endl;
		this->_energypoints--;
	}
}

void	ScavTrap::guardGate(void)
{
	this->_keepmod = true;

	std::cout << "ScavTrap " << this->_name;
	std::cout << " enterred in Gate keeper mode";
	std::cout << std::endl;
}

// Destructor

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called" << std::endl;	
}
