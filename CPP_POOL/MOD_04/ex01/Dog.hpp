/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 06:35:00 by muteza            #+#    #+#             */
/*   Updated: 2023/10/15 18:31:27 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal
{
	
	public:
			//constructor and destructor
			Dog(); //default
			Dog(Dog const &src); //copy
			virtual ~Dog();
			//Member function
			Brain*	getBrain(void) const;
			void	makeSound(void) const;
			//operator
			Dog	&operator=(Dog const &rhs);
	private:
		Brain* _brain;
};
#endif
// std::ostream	&operator<<( std::ostream &o, ClapTrap const &i );
