/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:58:56 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/20 10:43:00 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* canonic form */

AForm::AForm(const std::string &name, const int &grade_to_sign, const int &grade_to_exec) : _name(name), _signed(0), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec) {
    
    std::cout << GREEN << "Constructor called for AForm" << RESET << std::endl;
    return ;
}

AForm::AForm(const AForm& copy) : _name(copy._name), _signed(copy._signed), _grade_to_sign(copy._grade_to_sign), _grade_to_exec(copy._grade_to_exec) {
    
    std::cout << GREEN << "Copy Constructor called for AForm" << RESET << std::endl;
    return ;
}

AForm& AForm::operator=(const AForm& other) {

    if (this != & other) {

        this->_signed = other._signed;
    }
    std::cout << GREEN << "Operator Assignment called for AForm" << RESET << std::endl;
    return (*this);
}

AForm::~AForm() {

    std::cout << RED << "Destructor called for AForm" << RESET << std::endl;
    return ;
}

/* surcharge de l operateur d insertion */

std::ostream& operator<<(std::ostream& os, const AForm& rhs) {
    
    os << "Form's name: " << rhs.getName() << std::endl; 
    os << "Form's status: " << rhs.getStatus() << std::endl; 
    os << "Form's grade required to sign: " << rhs.getGradeToSign() << std::endl; 
    os << "Form's grade required to exec: " << rhs.getGradeToExec() << std::endl; 
    os << "Form's target: " << rhs.getTarget() << std::endl; 

    return (os);
}

/* setters & getters */

void AForm::setStatus(bool status) {

    this->_signed = status;
}

std::string AForm::getName() const {

    return (this->_name);
}

bool AForm::getStatus() const {

    return (this->_signed);
}

int AForm::getGradeToSign() const {

    return (this->_grade_to_sign);
}

int AForm::getGradeToExec() const {

    return (this->_grade_to_exec);
}

/* functions */

void AForm::beSigned(const Bureaucrat& bureaucrat) {

    if (bureaucrat.getGrade() < this->getGradeToSign())
        setStatus(1);
    else {

        throw AForm::GradeTooLowExecption();
    }
}

/* virtual what messages */

const char* AForm::GradeTooLowExecption::what() const throw() {

    return ("Form cannot be signed or executed");
}

/* functions added */

// void AForm::execute(Bureaucrat const & executor) const {

//     if (this->getStatus() == 1 && executor.getGrade() <= this->getGradeToExec()) {

//         std::cout << executor.getName() << " is allowed to perform an action on " << this->getName() << std::endl;
//     } 
//     else {

//         throw AForm::GradeTooLowExecption();
//     }
    
// }

