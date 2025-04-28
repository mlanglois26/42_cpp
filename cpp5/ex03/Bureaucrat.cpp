/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:17:32 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/20 11:09:35 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* canonic form */

Bureaucrat::Bureaucrat() : _name("Marc"), _grade(150) {

    std::cout << GREEN << "Default Constructor called for " << this->getName() << " with grade " << this->getGrade() << RESET << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade) {

    std::cout << GREEN << "Copy Constructor called for " << this->getName() << " with grade " << this->getGrade() << RESET << std::endl;
    return ;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {

    std::cout << GREEN << "Operator Assignment called for " << this->getName() << " with grade " << this->getGrade() << RESET << std::endl;
    if (this != &other) {

        this->_grade = other._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {
    
    std::cout << RED << "Destructor called for " << this->getName() << " with grade " << this->getGrade() << RESET << std::endl;
    return ;
}

/* Name & Grade Constructor */

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {

    if (grade < 1) {

        throw GradeTooHighExecption();
    }
    else if (grade > 150) {
        
        throw GradeTooLowExecption();
    }
    std::cout << GREEN << "Name & Grade Constructor called for " << this->getName() << " with grade " << this->getGrade() << RESET << std::endl;
    return ;
}

/* setters & getters */

void Bureaucrat::setGrade(int grade) {

    if (grade < 1) {
        
        throw GradeTooHighExecption();
    }
    else if (grade > 150) {
        
        throw GradeTooLowExecption();
    }
    
    this->_grade = grade;
}

/* setters & getters */

int Bureaucrat::getGrade() const {

    return (this->_grade);
}

std::string Bureaucrat::getName() const {

    return (this->_name);
}

/* surcharge de l operateur d insertion */

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs) {
    
    os << rhs.getName(); 
    os << ", bureaucrat grade ";
    os << rhs.getGrade();
    
    return (os);
}

/* increment & decrement functions */

void Bureaucrat::incrementGrade(int n ) {

    int cur_grade = this->getGrade();
    
    setGrade(cur_grade - n);
}

void Bureaucrat::decrementGrade(int n ) {

    int cur_grade = this->getGrade();
    
    setGrade(cur_grade + n);
}

/* virtual what messages */

const char* Bureaucrat::GradeTooHighExecption::what() const throw() {

    return ("Your Grade is too HIGH");
}

const char* Bureaucrat::GradeTooLowExecption::what() const throw() {

    return ("Your Grade is too LOW");
}

/* added function */

void Bureaucrat::signForm(const AForm& form) {

    if (form.getStatus() == 1)
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    else
        std::cout << this->getName() << " couldn't sign " << form.getName() << " because his " << Bureaucrat::GradeTooLowExecption().what() << std::endl;

}

void Bureaucrat::executeForm(AForm const & form) {

    if (form.getStatus() == 1 && this->getGrade() <= form.getGradeToExec()) {
        
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    else if (form.getStatus() == 0 && this->getGrade() <= form.getGradeToExec()) {
        
        std::cout << "Form cannot be executed since that is has not been signed" << std::endl;
    }
    else {

        std::cout << "Sorry, but " << this->getName() << " does not have permissions to execute " << form.getName() << std::endl;
    }
}