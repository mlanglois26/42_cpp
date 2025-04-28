/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:09:13 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/19 14:48:20 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/* canonic form */

Intern::Intern()
{
    std::cout << GREEN << "Default constructor called on Intern Class" << RESET << std::endl;
    return ;
}

Intern::Intern(const Intern& copy)
{
    *this = copy;
    std::cout << GREEN << "Copy constructor called on Intern Class" << RESET << std::endl;
    return ;
}

Intern& Intern::operator=(const Intern& other) {

    (void)other;
    std::cout << GREEN << "Operator Assignment called on Intern Class" << RESET << std::endl;
    return (*this);
}

Intern::~Intern()
{
    std::cout << RED << "Destructor called on Intern Class" << RESET << std::endl;
    return ;
}

/* functions */

AForm* Intern::makeForm(std::string formName, std::string formTarget) {

    std::string array[3] = {"MyShrubberyForm", "MyRobotomyForm", "MyPresidentialForm"};
    AForm* forms[3]= { new ShrubberyCreationForm(formTarget), new RobotomyRequestForm(formTarget), new PresidentialPardonForm(formTarget) };
    
    for (int i = 0; i < 3; i++) {
        
        if (formName == array[i]) {

            for (int j = 0; j < 3; j++) {

                if (j != i)
                    delete (forms[j]);
            }
            std::cout << "Intern creates " << formName << std::endl;
            return (forms[i]);
        }
    }
    for (int j = 0; j < 3; j++) {

        delete (forms[j]);
    }
    throw std::invalid_argument("Form name does not match any known forms");
}





