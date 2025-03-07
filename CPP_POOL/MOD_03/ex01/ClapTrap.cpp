/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:29:30 by muteza            #+#    #+#             */
/*   Updated: 2023/10/04 19:12:29 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructor 

ClapTrap::ClapTrap() : _name("Default"), _hitpoints(10), _energypoints(10), _attackdamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitpoints(10), _energypoints(10), _attackdamage(0)
{
	std::cout << "Named constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// Operator overload

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs) {

	this->_name = rhs._name;
	this->_attackdamage = rhs._attackdamage;
	this->_energypoints = rhs._energypoints;
	this->_hitpoints = rhs._hitpoints;

	return (*this);
}

// Member function

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitpoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already DEAD his Hit Points : " 
		<< this->_hitpoints << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_attackdamage << " points of damage!" << std::endl;
		this->_energypoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is DEAD "<< std::endl;
	}
	else
	{
		this->_hitpoints -=	amount;
		std::cout << "ClapTrap " << this->_name;
		std::cout << " take damage " << amount;
		std::cout << ", remaining hit points " << this->_hitpoints;
		std::cout << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitpoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is DEAD "<< std::endl;
	}
	else
	{
		this->_hitpoints +=	amount;
		this->_energypoints--;
		std::cout << "ClapTrap " << this->_name;
		std::cout << " be repaired " << amount;
		std::cout << ", remaining hit points " << this->_hitpoints;
		std::cout << std::endl;
	}
}


// Accessor

const int &ClapTrap::getHitPoints() const
{
	return (this->_hitpoints);
}

const int	&ClapTrap::getEnergyPoints( void ) const
{

	return (this->_energypoints);
}

const int	&ClapTrap::getAttackDamage( void ) const
{

	return (this->_attackdamage);
}

// Destructor

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;	
}
