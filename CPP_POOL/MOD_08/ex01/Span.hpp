/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 08:08:12 by muteza            #+#    #+#             */
/*   Updated: 2024/04/08 10:47:23 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm> // std::sort
#include <vector>

class LessTwoNumbers : public std::exception {
	public:
		const char *what() const throw() {return ( "Can't find 2 numbers ! 👻 ");};
	};

class SpanFull : public std::exception {
	public:
		virtual const char *what() const throw() {return ("The Span is Full ! 👻 ");};
	};

class Span {
	
	public:
			//constructor and destructor
			Span(unsigned int N); //default (assignement)
			Span(Span const &src); //copy
			virtual ~Span();
			//Accessor
			// void const &getNumber() const;
			//Member function
			void addNumber(unsigned int const &number);
			unsigned int longestSpan();
			unsigned int shortestSpan() const;
			//operator
			Span	&operator=(Span const &rhs);
	private:
		unsigned int				_size;
		std::vector<unsigned int>	_span;
		Span( void ); //constructeur par default
};

template<typename InputIterator>
void addRange(Span& span, InputIterator first, InputIterator last) {
    for (; first != last; ++first) {
        span.addNumber(*first);
    }
}

#endif
