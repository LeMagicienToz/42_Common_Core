/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 03:37:15 by muteza            #+#    #+#             */
/*   Updated: 2024/08/07 13:01:07 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <vector>
int main ()
{

	//order when put in stack
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	
	//order in the stack 
	
	std::cout << " \nIterating through stack using reverse iterators: \n" << std::endl;
	MutantStack<int> mrstack;
	mrstack.push(5);
	mrstack.push(17);
	std::cout << mrstack.top() << std::endl;

	mrstack.pop();
	std::cout << mrstack.size() << std::endl;

	mrstack.push(3);
	mrstack.push(5);
	mrstack.push(737);
	mrstack.push(0);

	// LIFO (Last In, First Out)
	MutantStack<int>::reverse_iterator rit = mrstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mrstack.rend();

	while (rit != rite) {
		std::cout << *rit << std::endl;
		++rit;
	}

	
	return 0;
}
