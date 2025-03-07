/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 08:07:54 by muteza            #+#    #+#             */
/*   Updated: 2023/12/08 13:34:01 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base	*generate( void ) {

	srand(time(0));

	switch (rand() % 3) {

		case 0:
			return new A();

		case 1:
			return new B();

		case 2:
			return new C();

		default:
			return NULL;
	}
}

void	identify( Base *p ) {

	if (dynamic_cast<A *>(p))
		std::cout << "type * : A" << std::endl;

	else if (dynamic_cast<B *>(p))
		std::cout << "type * : B" << std::endl;

	else if (dynamic_cast<C *>(p))
		std::cout << "type * : C" << std::endl;

	else
		std::cout << "type * : Unknown" << std::endl;
}

void	identify( Base &p ) {

	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "type & : A" << std::endl;
		return ;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "type & : B" << std::endl;
		return ;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "type & : C" << std::endl;
		return ;
	}
	catch (...) {}
}

int	main(void)
{
	Base	*a = generate();

	identify(a);
	identify(*a);

	delete a;

	return (0);
}
