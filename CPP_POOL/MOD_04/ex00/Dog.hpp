/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 06:35:00 by muteza            #+#    #+#             */
/*   Updated: 2023/10/15 17:19:54 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : virtual public Animal
{
	
	public:
			//constructor and destructor
			Dog(); //default
			Dog(Dog const &src); //copy
			virtual ~Dog();
			//Member function
			void	makeSound(void) const;
			//operator
			Dog	&operator=(Dog const &rhs);
};
#endif
// std::ostream	&operator<<( std::ostream &o, ClapTrap const &i );
