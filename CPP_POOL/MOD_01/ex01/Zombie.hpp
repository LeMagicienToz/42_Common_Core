/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:01:52 by muteza            #+#    #+#             */
/*   Updated: 2023/08/16 17:26:21 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie {

	public:
		Zombie(void);
		~Zombie(void);
		void		setName(std::string name);
		void		announce(void) const;
		std::string	get_Name(void) const;
	private:
		std::string _name;
};
Zombie*		zombieHorde( int N, std::string name );