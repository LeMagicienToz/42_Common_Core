/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:59:01 by muteza            #+#    #+#             */
/*   Updated: 2023/10/25 15:42:49 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/****	Constructor && destructor	****/

Bureaucrat::Bureaucrat() : _name("Default") , _grade(75)
{
	return;
}

Bureaucrat::Bureaucrat(int const grade, std::string const name) : _name(name) , _grade(grade)
{
	this->exceptionCheck();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	*this = src;
	return ;
}

Bureaucrat::~Bureaucrat()
{
	return ;
}


/****	Operator	****/

Bureaucrat    &Bureaucrat::operator=( Bureaucrat const &rhs ) {

	if (this != &rhs)
		this->_grade = rhs._grade;

	return (*this);
}

/****	Accessor	****/

std::string const &Bureaucrat::getName() const
{
	return (this->_name);
}

int const  &Bureaucrat::getGrade() const
{
	return (this->_grade);
}

/****	Exception	****/

void	Bureaucrat::exceptionCheck( void ) const {

	if (this->_grade > 150)
		throw GradeTooLowException();
	if (this->_grade < 1)
		throw GradeTooHighException();
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too High !");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too Low !");
}

/****	Member function	****/

void	Bureaucrat::upGrade()
{
	this->_grade--;
	this->exceptionCheck();

}


void	Bureaucrat::downGrade()
{
	this->_grade++;
	this->exceptionCheck();
}


void	Bureaucrat::signForm(Form & f)
{
	if (f.getSigned())
	{
		std::cout << "This Form is already signed." << std::endl;
		return;
	}
	if (this->_grade <= f.getGradeSign() )
	{
		std::cout << this->_name << " signed " << f.getName() << std::endl;
		f.beSigned( *this );
	}
	else
	{
		std::cout << this->_name << " couldn't sign " << f.getName() << " because the grade is not reach." << std::endl;
		throw GradeTooLowException();
	}
}

/****	Stream out	****/

std::ostream & operator<<(std::ostream & o, Bureaucrat const & i)
{
	o << i.getName();
	o << " grade is ";
	o << i.getGrade();
	return (o);
}