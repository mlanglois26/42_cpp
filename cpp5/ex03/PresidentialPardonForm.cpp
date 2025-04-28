/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:07:37 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/20 11:01:19 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

/* canonic form */

PresidentialPardonForm::PresidentialPardonForm() : AForm("MyPresidentialForm", 25, 5), _target("Target") {

    // std::cout << GREEN << "Default Constructor called for " << this->getName() << RESET << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy), _target(copy._target) {
 
    // std::cout << GREEN << "Copy Constructor called for " << this->getName() << RESET << std::endl;
    return ;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {

    if (this != &other) {

       this->_target = other._target;
       AForm::operator=(other);
    }
    
    // std::cout << GREEN << "Operator Assignment called for " << this->getName() << RESET << std::endl;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
    
    // std::cout << RED << "Destructor called for " << this->getName() << RESET << std::endl;
    return ;
}

/* target constructor */

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("MyPresidentialFrom", 25, 5), _target(target) {

    // std::cout << GREEN << "Target Constructor called for " << this->getName() << RESET << std::endl;
    return ;
}

/* function */

std::string PresidentialPardonForm::getTarget() const {

    return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {

    if (this->getStatus() == 1 && executor.getGrade() <= this->getGradeToExec()) {

        std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblerox" << std::endl;
    } 
    else {

        throw AForm::GradeTooLowExecption();
    }
    
}