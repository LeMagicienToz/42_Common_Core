/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:17:52 by muteza            #+#    #+#             */
/*   Updated: 2023/10/25 15:42:54 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/****	Constructor && destructor	****/

Form::Form() : _name("Default") , _gradeSign(5), _gradeExec(6), _signed(false)
{
	return;
}

Form::Form(std::string const name, int const gradeSign, int const gradeExec) : _name(name) , _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false)
{
	this->exceptionCheck();
}

Form::Form(Form const &src) : _name(src._name), _gradeSign(src._gradeSign), _gradeExec(src._gradeSign), _signed(src._signed)
{
	this->exceptionCheck();
	return ;
}

Form::~Form()
{
	return ;
}


/****	Operator	****/

Form    &Form::operator=( Form const &rhs ) {

	if (this != &rhs)
		this->_signed = rhs._signed;

	return (*this);
}

/****	Accessor	****/

std::string const &Form::getName() const
{
	return (this->_name);
}

bool const &Form::getSigned() const
{
	return(this->_signed);
}

int const  &Form::getGradeSign() const
{
	return (this->_gradeSign);
}


int const  &Form::getGradeExec() const
{
	return (this->_gradeExec);
}

/****	Exception	****/

void	Form::exceptionCheck( void ) const {

	if (this->_gradeSign > 150 || this->_gradeExec > 150)
		throw GradeTooLowException();
	if ( this->_gradeSign < 1 || this->_gradeExec < 1)
		throw GradeTooHighException();
}

const char * Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too High !");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too Low !");
}

/****	Member function	****/

void	Form::beSigned( Bureaucrat const &employee ) {

	if (employee.getGrade() > this->_gradeSign)
		throw GradeTooLowException();
	if (this->_signed != true)
		this->_signed = true;
}

/****	Stream out	****/

std::ostream & operator<<(std::ostream & o, Form const & i)
{
	o << i.getName();
	o << " grade is ";
	o << i.getGradeSign();
	return (o);
}