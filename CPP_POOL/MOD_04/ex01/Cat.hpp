/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 06:35:00 by muteza            #+#    #+#             */
/*   Updated: 2023/10/15 18:31:36 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : virtual public Animal
{
	
	public:
			//constructor and destructor
			Cat(); //default
			Cat(Cat const &src); //copy
			virtual ~Cat();
			//Member function
			Brain*	getBrain(void) const;
			void	makeSound(void) const;
			//operator
			Cat	&operator=(Cat const &rhs);
	private:
		Brain* _brain;
			
};
#endif
// std::ostream	&operator<<( std::ostream &o, ClapTrap const &i );