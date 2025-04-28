/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:07:13 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/20 11:01:36 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

/* canonic form */

RobotomyRequestForm::RobotomyRequestForm() : AForm("MyRobotomyForm", 72, 45), _target("Target") {

    // std::cout << GREEN << "Default Constructor called for " << this->getName() << RESET << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy), _target(copy._target) {

    // std::cout << GREEN << "Copy Constructor called for " << this->getName() << RESET << std::endl;
    return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {

    if (this != &other) {

        this->_target = other._target;
        AForm::operator=(other);
    }
    // std::cout << GREEN << "Operator Assignment called for " << this->getName() << RESET << std::endl;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {

    // std::cout << RED << "Destructor called for " << this->getName() << RESET << std::endl;
    return ;
}

/* target constructor */

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("MyRobotomyForm", 145, 137), _target(target) {

    // std::cout << GREEN << "Target Constructor called for " << this->getName() << RESET << std::endl;
    return ;
}

/* function */

std::string RobotomyRequestForm::getTarget() const {

    return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {

    if (this->getStatus() == 1 && executor.getGrade() <= this->getGradeToExec()) {

        std::cout << "Drilling noises" << std::endl;
        std::srand(std::time(NULL));
        if (std::rand() % 2 == 0) {

            std::cout << this->getTarget() << " has been robotomized" << std::endl;
        } 
        else {

            std::cout << this->getTarget() << " has not been robotomized" << std::endl;
        }
    } 
    else {

        throw AForm::GradeTooLowExecption();
    }
}