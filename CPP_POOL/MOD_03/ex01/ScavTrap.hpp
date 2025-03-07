/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:26:35 by muteza            #+#    #+#             */
/*   Updated: 2023/10/11 16:25:53 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	
	public:
			//constructor and destructor
			ScavTrap(); //default
			ScavTrap(ScavTrap const &src); //copy
			ScavTrap(const std::string name); // With a name
			~ScavTrap();
			//operator
			ScavTrap	&operator=(ScavTrap const &rhs);
			void attack(const std::string& target);
            void guardGate();
	protected:
        bool        _keepmod;
		
			
};

// std::ostream	&operator<<( std::ostream &o, ClapTrap const &i );

#endif