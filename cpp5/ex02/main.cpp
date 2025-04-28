/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:16:28 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/20 11:09:12 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    
    std::cout << MAGENTA << "Canonic From \n" << RESET << std::endl;

    ShrubberyCreationForm form;
    ShrubberyCreationForm b(form);
    ShrubberyCreationForm c;
    c = form;

    ShrubberyCreationForm myform("my_shrubbery_target");
    
    std::cout << std::endl;
    std::cout << BLUE << myform << RESET << std::endl;
    
    Bureaucrat marc("Marc", 100);
    Bureaucrat bob("Bob", 138);

    std::cout << BLUE << marc << RESET << std::endl;
    std::cout << BLUE << bob << RESET << std::endl;

    try {
        
        myform.beSigned(bob);
    }
    catch (const AForm::GradeTooLowExecption& e) {

        std::cout << "Error: " << e.what() << std::endl;
    }
    bob.signForm(myform);
    std::cout << BLUE << myform << RESET << std::endl;

    std::cout << MAGENTA << "Execute Function\n" << RESET << std::endl;

    try {
            
        myform.execute(bob);
    }
    catch (const AForm::GradeTooLowExecption& e) {

        std::cout << "Error from From: " << e.what() << std::endl;
    }
    try {
        
        form.execute(marc);
    }
    catch (const AForm::GradeTooLowExecption& e) {

        std::cout << "Error from From: " << e.what() << std::endl;
    }
    try {
        
        myform.execute(marc);
    }
    catch (const AForm::GradeTooLowExecption& e) {

        std::cout << "Error from From: " << e.what() << std::endl;
    }

    std::cout << MAGENTA << "\nExecuteForm Function\n" << RESET << std::endl;

    try {
        
        bob.executeForm(myform);
    }
    catch (const Bureaucrat::GradeTooLowExecption& e) {

        std::cout << "Error from Bureaucrat: " << e.what() << std::endl;
    }
    try {
        
        marc.executeForm(form);
    }
    catch (const Bureaucrat::GradeTooLowExecption& e) {

        std::cout << "Error from Bureaucrat: " << e.what() << std::endl;
    }
    try {
        
        marc.executeForm(myform);
    }
    catch (const Bureaucrat::GradeTooLowExecption& e) {

        std::cout << "Error from Bureaucrat: " << e.what() << std::endl;
    }

    return (0);
}

// int main() {

//     std::cout << MAGENTA << "Canonic From \n" << RESET << std::endl;

//     RobotomyRequestForm form;
//     RobotomyRequestForm b(form);
//     RobotomyRequestForm c;
//     c = form;

//     RobotomyRequestForm myform("my_robotomy_target");
    
//     std::cout << std::endl;
//     std::cout << BLUE << myform << RESET << std::endl;
    
//     Bureaucrat marc("Marc", 45);
//     Bureaucrat bob("Bob", 70);

//     std::cout << BLUE << marc << RESET << std::endl;
//     std::cout << BLUE << bob << RESET << std::endl;

//     try {
        
//         myform.beSigned(bob);
//     }
//     catch (const AForm::GradeTooLowExecption& e) {

//         std::cout << "Error: " << e.what() << std::endl;
//     }
//     bob.signForm(myform);
//     std::cout << BLUE << myform << RESET << std::endl;

//     std::cout << MAGENTA << "Execute Function\n" << RESET << std::endl;

//     try {
            
//         myform.execute(bob);
//     }
//     catch (const AForm::GradeTooLowExecption& e) {

//         std::cout << "Error from From: " << e.what() << std::endl;
//     }
//     try {
        
//         form.execute(marc);
//     }
//     catch (const AForm::GradeTooLowExecption& e) {

//         std::cout << "Error from From: " << e.what() << std::endl;
//     }
//     try {
        
//         myform.execute(marc);
//     }
//     catch (const AForm::GradeTooLowExecption& e) {

//         std::cout << "Error from From: " << e.what() << std::endl;
//     }

//     std::cout << MAGENTA << "\nExecuteForm Function\n" << RESET << std::endl;

//     try {
        
//         bob.executeForm(myform);
//     }
//     catch (const Bureaucrat::GradeTooLowExecption& e) {

//         std::cout << "Error from Bureaucrat: " << e.what() << std::endl;
//     }
//     try {
        
//         marc.executeForm(myform);
//     }
//     catch (const Bureaucrat::GradeTooLowExecption& e) {

//         std::cout << "Error from Bureaucrat: " << e.what() << std::endl;
//     }

//     return (0);
// }

// int main() {

//     std::cout << MAGENTA << "Canonic From \n" << RESET << std::endl;

//     PresidentialPardonForm form;
//     PresidentialPardonForm b(form);
//     PresidentialPardonForm c;
//     c = form;

//     PresidentialPardonForm myform("my_presidential_target");
    
//     std::cout << std::endl;
//     std::cout << BLUE << myform << RESET << std::endl;
    
//     Bureaucrat marc("Marc", 1);
//     Bureaucrat bob("Bob", 12);

//     std::cout << BLUE << marc << RESET << std::endl;
//     std::cout << BLUE << bob << RESET << std::endl;

//     try {
        
//         myform.beSigned(bob);
//     }
//     catch (const AForm::GradeTooLowExecption& e) {

//         std::cout << "Error: " << e.what() << std::endl;
//     }
//     bob.signForm(myform);
//     std::cout << BLUE << myform << RESET << std::endl;

//     std::cout << MAGENTA << "Execute Function\n" << RESET << std::endl;

//     try {
            
//         myform.execute(bob);
//     }
//     catch (const AForm::GradeTooLowExecption& e) {

//         std::cout << "Error from From: " << e.what() << std::endl;
//     }
//     try {
        
//         form.execute(marc);
//     }
//     catch (const AForm::GradeTooLowExecption& e) {

//         std::cout << "Error from From: " << e.what() << std::endl;
//     }
//     try {
        
//         myform.execute(marc);
//     }
//     catch (const AForm::GradeTooLowExecption& e) {

//         std::cout << "Error from From: " << e.what() << std::endl;
//     }

//     std::cout << MAGENTA << "\nExecuteForm Function\n" << RESET << std::endl;

//     try {
        
//         bob.executeForm(myform);
//     }
//     catch (const Bureaucrat::GradeTooLowExecption& e) {

//         std::cout << "Error from Bureaucrat: " << e.what() << std::endl;
//     }
//     try {
        
//         marc.executeForm(myform);
//     }
//     catch (const Bureaucrat::GradeTooLowExecption& e) {

//         std::cout << "Error from Bureaucrat: " << e.what() << std::endl;
//     }

//     return (0);
// }
