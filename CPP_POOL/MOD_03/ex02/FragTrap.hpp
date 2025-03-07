/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:14:50 by muteza            #+#    #+#             */
/*   Updated: 2023/10/05 10:22:00 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	
	public:
			//constructor and destructor
			FragTrap(); //default
			FragTrap(FragTrap const &src); //copy
			FragTrap(const std::string name); // With a name
			~FragTrap();
			//Member Function
			void	highFivesGuys();
			//operator
			FragTrap	&operator=(FragTrap const &rhs);
			
};