/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:58:56 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/20 09:11:57 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* canonic form */

Form::Form() : _name("MyForm"), _signed(0), _grade_to_sign(75), _grade_to_exec(10) {
    
    std::cout << GREEN << "Default Constructor called for " << this->getName() << RESET << std::endl;
    return ;
}

Form::Form(const Form& copy) : _name(copy._name), _signed(copy._signed), _grade_to_sign(copy._grade_to_sign), _grade_to_exec(copy._grade_to_exec) {
    
    std::cout << GREEN << "Copy Constructor called for " << this->getName() << RESET << std::endl;
    return ;
}

Form& Form::operator=(const Form& other) {

    if (this != & other) {

        this->_signed = other._signed;
    }
    std::cout << GREEN << "Operator Assignment called for " << this->getName() << RESET << std::endl;
    return (*this);
}

Form::~Form() {

    std::cout << RED << "Destructor called for " << this->getName() << RESET << std::endl;
    return ;
}

/* Name & Grades Constructor */

Form::Form(const std::string& name, const int grade_to_sign, const int grade_to_exec) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec) {

    if (grade_to_sign < 1) {

        throw GradeTooHighException();
    }
    else if (grade_to_sign > 150) {
        
        throw GradeTooLowException();
    }
    
    if (grade_to_exec < 1) {

        throw GradeTooHighException();
    }
    else if (grade_to_exec > 150) {
        
        throw GradeTooLowException();
    }

    std::cout << GREEN << "Name & Grade Constructor called for " << this->getName() << " with grade " << this->getGradeToSign() << " & " << this->getGradeToExec() << RESET << std::endl;
    return ;
}

/* surcharge de l operateur d insertion */

std::ostream& operator<<(std::ostream& os, const Form& rhs) {
    
    os << "Form's name: " << rhs.getName() << std::endl; 
    os << "Form's status: " << rhs.getStatus() << std::endl; 
    os << "Form's grade required to sign: " << rhs.getGradeToSign() << std::endl; 
    os << "Form's grade required to exec: " << rhs.getGradeToExec() << std::endl; 

    return (os);
}

/* setters & getters */

void Form::setStatus(bool status) {

    this->_signed = status;
}

std::string Form::getName() const {

    return (this->_name);
}

bool Form::getStatus() const {

    return (this->_signed);
}

int Form::getGradeToSign() const {

    return (this->_grade_to_sign);
}

int Form::getGradeToExec() const {

    return (this->_grade_to_exec);
}

/* functions */

void Form::beSigned(const Bureaucrat& bureaucrat) {

    if (bureaucrat.getGrade() <= this->getGradeToSign()) {
        
        setStatus(1);
    }
    else {

        throw Form::GradeTooLowException();
    }
}

/* virtual what messages */

const char* Form::GradeTooLowException::what() const throw() {

    return ("Form cannot be signed: the grade received to sign or execute it is too LOW");
}

const char* Form::GradeTooHighException::what() const throw() {

    return ("Form cannot be signed: the grade received to sign or execute it is too HIGH");
}