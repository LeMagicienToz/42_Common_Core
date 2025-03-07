/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 06:35:00 by muteza            #+#    #+#             */
/*   Updated: 2023/10/04 19:10:13 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <iostream>

class ClapTrap {
	
	public:
			//constructor and destructor
			ClapTrap(); //default
			ClapTrap(ClapTrap const &src); //copy
			ClapTrap(const std::string name); // With a name
			~ClapTrap();
			//operator
			ClapTrap	&operator=(ClapTrap const &rhs);
			//accessor
			const int &getHitPoints() const;
			const int &getEnergyPoints() const;
			const int &getAttackDamage() const;
			//member function
			void attack(const std::string& target);
			void takeDamage(unsigned int amount);
			void beRepaired(unsigned int amount);
	private:
		std::string _name;
		int _hitpoints;
		int _energypoints;
		int _attackdamage;
			
};

// std::ostream	&op erator<<( std::ostream &o, ClapTrap const &i );

#endif