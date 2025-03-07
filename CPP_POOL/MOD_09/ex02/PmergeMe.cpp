/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:00:46 by muteza            #+#    #+#             */
/*   Updated: 2024/08/22 14:02:07 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe( const PmergeMe & src ) {
	*this = src;
}

PmergeMe::~PmergeMe()
{}

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	if ( this != &rhs ) {
		this->vector = rhs.vector;
		deque = rhs.deque;
	}
	return *this;
}