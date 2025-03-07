/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 00:14:45 by muteza            #+#    #+#             */
/*   Updated: 2023/08/14 05:26:51 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>

class Zombie {
    
    public:
        Zombie(std::string name);
        ~Zombie(void);
        void    announce(void) const;
        Zombie* newZombie( std::string name );
        void    randomChump( std::string name );
    private:
    std::string _name;
    
};
#endif