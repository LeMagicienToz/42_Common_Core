/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 03:37:15 by muteza            #+#    #+#             */
/*   Updated: 2023/12/20 14:37:22 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

int main ()
{
	// INIT Containers
	std::vector<int> vec;
	std::deque<int> deq;
	std::list<int>	list;
	
	//fill the containers
	for (int i = 0; i <= 10; i++)
	{
		list.push_back(i);
		deq.push_back(i);
		vec.push_back(i);
	}
	try
	{
		std::cout << "more than 10 : " << std::endl << std::endl << std::endl;
		std::cout << "list : " << ::easyfind(list, 15) << std::endl;
		// std::cout << "deq : " << ::easyfind(deq, 13) << std::endl;
		// std::cout << "vec : " << ::easyfind(vec, 200) << std::endl;
	}
	catch (std::exception const &e)
	{
		 std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "less than 10 : " << std::endl << std::endl << std::endl;
		std::cout << "list : " << ::easyfind(list, 1) << std::endl;
		std::cout << "deq : " << ::easyfind(deq, 4) << std::endl;
		std::cout << "vec : " << ::easyfind(vec, 8) << std::endl;
	}
	catch (std::exception const &e)
	{
		 std::cout << e.what() << std::endl;
	}

}
