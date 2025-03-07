/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:31:43 by muteza            #+#    #+#             */
/*   Updated: 2023/12/08 13:31:52 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
#include "Data.h"


class Serializer {

public:

// Const
	Serializer( void );
	Serializer( Serializer const &src );
	~Serializer( void );
//member function
	static uintptr_t	serialize( Data *ptr );
	static Data			*deserialize( uintptr_t raw );

// OP overload
	Serializer	&operator=( Serializer const &rhs );

};

#endif
