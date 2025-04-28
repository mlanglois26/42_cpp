/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:24:00 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/20 09:29:49 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {

    Intern a;
    Intern b(a);
    Intern c;
    c = a;

    AForm* form;

    try {
            
        form = c.makeForm("MyShrubberyForm", "target");
        delete form;
    }
    catch (const std::exception& e) {

        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
            
        form = c.makeForm("MyRobotomyForm", "target");
        delete form;
    }
    catch (const std::exception& e) {

        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
            
        form = c.makeForm("MyPresidentialForm", "target");
        delete form;
    }
    catch (const std::exception& e) {

        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
            
        form = c.makeForm("Form", "target");
        delete form;
    }
    catch (const std::exception& e) {

        std::cout << "Error: " << e.what() << std::endl;
    }

    return (0);
}

