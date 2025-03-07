/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:31:49 by muteza            #+#    #+#             */
/*   Updated: 2024/08/07 12:56:24 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <exception>
#include <algorithm> // std::sort
#include <vector>
#include <deque>
#include <list>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	// Constructor
	MutantStack() : std::stack<T>() {}

	// Copy constructor
	MutantStack(const MutantStack& src) : std::stack<T>(src) {}

	// Destructor
	virtual ~MutantStack() {}

	// Assignment operator
	MutantStack& operator=(const MutantStack& rhs) {
		if (this != &rhs) {
			std::stack<T>::operator=(rhs);
		}
		return *this;
	}

	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;
	typedef typename std::deque<T>::reverse_iterator reverse_iterator;
	typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

	// Iterator functions
	iterator begin() {
		return this->c.begin();
	}

	iterator end() {
		return this->c.end();
	}

	const_iterator begin() const {
		return this->c.begin();
	}

	const_iterator end() const {
		return this->c.end();
	}

	reverse_iterator rbegin() {
		return this->c.rbegin();
	}

	reverse_iterator rend() {
		return this->c.rend();
	}

	const_reverse_iterator rbegin() const {
		return this->c.rbegin();
	}

	const_reverse_iterator rend() const {
		return this->c.rend();
	}

private:
	using std::stack<T>::c;
};

#endif

