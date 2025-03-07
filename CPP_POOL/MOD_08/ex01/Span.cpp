/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:32:58 by muteza            #+#    #+#             */
/*   Updated: 2024/05/07 14:41:11 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>
#include <iterator>

/* Constructor & destructor */

Span::Span( void ) : _size( 0 ) { this->_span.reserve( this->_size ); }

Span::Span(unsigned int N) : _size(N) {this->_span.reserve(this->_size); }

Span::Span( Span const &src ) { *this = src; }

Span::~Span( void ) {}

/* Function Member */

void Span::addNumber(unsigned int const &number)
{
	if (this->_size == this->_span.size())
		throw SpanFull();
	this->_span.push_back(number);
}

unsigned int	Span::shortestSpan( void ) const 
{
	if (this->_span.size() < 2)
		throw LessTwoNumbers();
	std::vector<unsigned int>	tmp(this->_span);
	unsigned int	min_dist = std::numeric_limits<unsigned int>::max();

	std::sort( tmp.begin(), tmp.end() );

	for (unsigned int i = 0; i < tmp.size() - 1; i++) {

		unsigned int diff = static_cast<int>( std::abs( static_cast<int>(tmp[ i ] - tmp[ i + 1 ]) ) );

		min_dist = std::min(min_dist, diff);
		// std::cout << min_dist << std::endl;
	}
	return (min_dist);
}

unsigned int Span::longestSpan()
{
	if (this->_span.size() < 2)
		throw LessTwoNumbers();
	std::vector<unsigned int> tmp(_span);
	std::sort(tmp.begin(), tmp.end());
	// std::copy(tmp.begin(), tmp.end(), std::ostream_iterator<int>(std::cout, " "));
	return(tmp.back() - tmp.front());
	// std::cout << "Les deux nombre les plus eloigne sont " << tmp[0] << "et " << tmp[tmp.size() - 1] << std::endl;
}

/* OPERATOR */
Span	&Span::operator=( Span const &rhs ) {

	if (this != &rhs)
		this->_size = rhs._size;

	return (*this);
}
