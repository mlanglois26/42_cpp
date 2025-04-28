/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:57:28 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/20 11:01:57 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

/* canonic form */

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("MyShrubberyForm", 145, 137), _target("Target") {
    
    // std::cout << GREEN << "Default Constructor called for " << this->getName() << RESET << std::endl;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), _target(copy._target) {
    
    // std::cout << GREEN << "Copy Constructor called for " << this->getName() << RESET << std::endl;
    return ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    
    if (this != &other) {

        this->_target = other._target;
        AForm::operator=(other);
    }
    // std::cout << GREEN << "Operator Assignment called for " << this->getName() << RESET << std::endl;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    
    // std::cout << RED << "Destructor called for " << this->getName() << RESET << std::endl;
    return ;
}

/* target constructor */

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("MyShrubberyForm", 145, 137), _target(target) {

    // std::cout << GREEN << "Target Constructor called for " << this->getName() << RESET << std::endl;
    return ;
}

/* function */

std::string ShrubberyCreationForm::getTarget() const {

    return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {

    if (this->getStatus() == 1 && executor.getGrade() <= this->getGradeToExec()) {

        std::ofstream	outfile;
        
        outfile.open((this->getTarget() + "_shrubbery").c_str());
        if (outfile.fail())
        {
            std::cout << "Could not open file" << std::endl;
            return ;
        }
        outfile << "        ccee44&&          " << std::endl;
		outfile << "  C4&4&4Q4P&&b &4&&      " << std::endl;
		outfile << " d&B69Q&4PdU&pug&&9bD    " << std::endl;
		outfile << "CddgbU4&U q&p q&d&U&dcb  " << std::endl;
		outfile << "   6&uU  pp u gc&U&dpP   " << std::endl;
		outfile << "      \\\\//  /d&uUP      " << std::endl;
		outfile << "        \\\\////         " << std::endl;
		outfile << "         |||/\\          " << std::endl;
		outfile << "         |||\\/          " << std::endl;
		outfile << "         |||||           " << std::endl;
		outfile << "   .....//||||\\....     " << std::endl;
        outfile.close();
        std::cout << executor.getName() << " successfully executed " << this->getName() << std::endl;
    } 
    else {

        throw AForm::GradeTooLowExecption();
    }
}