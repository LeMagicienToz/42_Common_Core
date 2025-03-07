/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:33:42 by muteza            #+#    #+#             */
/*   Updated: 2023/10/15 23:20:16 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#define TAB 6

int main ()
{
	const Animal* j = new Dog(); 
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	
	std::cout << std::endl;
	std::cout << " |||| test creation et destruction ||" << std::endl;
	const Animal* animals[TAB];
	for (int i = 0; i < TAB; i++)
		(i < TAB / 2) ? animals[i] = new Dog() : animals[i] = new Cat();
	for (int i = 0; i < TAB; i++)
		delete animals[i];


	//test deep copy
	const Dog* z = new Dog();

	z->getBrain()->setIdeas("Wesh", 0);
	z->getBrain()->setIdeas("Hello Worlds", 1);
	const Dog* y = new Dog(*z);
	y->getBrain()->setIdeas("bouuuuuu", 1);
	delete z;
	y->getBrain()->viewIdeas();
	delete y;
	// system("leaks Animal");

	Dog a;

	a.getBrain()->setIdeas("Wesh", 0);
	a.getBrain()->setIdeas("Hello Worlds", 1);
	Dog b = a;
	b.getBrain()->setIdeas("bouuuuu", 1);
	b.getBrain()->viewIdeas();
	a.getBrain()->viewIdeas();
}
