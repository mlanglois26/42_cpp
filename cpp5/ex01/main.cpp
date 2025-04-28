/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:16:28 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/20 09:18:36 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

    std::cout << MAGENTA << "Canonic From \n" << RESET << std::endl;
    
    Form a;
    Form b(a);
    Form c;
    c = a;

    std::cout << BLUE << a << RESET << std::endl;

    std::cout << MAGENTA << "Try Creating Forms with an out of range grade\n" << RESET << std::endl;

    try {

        Form e("my form", 1, 151);
    }
    catch (const Form::GradeTooHighException& e) {
        
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }
    catch (const Form::GradeTooLowException& e) {

        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    try {

        Form e("my form", 0, 150);
    }
    catch (const Form::GradeTooHighException& e) {
        
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }
    catch (const Form::GradeTooLowException& e) {

        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }
    
    std::cout << MAGENTA << "\nBeSigned function\n" << RESET << std::endl;
    
    Bureaucrat marc("Marc", 30);
    Form form;
    
    std::cout << BLUE << marc << RESET << std::endl;
    std::cout << BLUE << form << RESET << std::endl;
    
    try {
        
        form.beSigned(marc);
    }
    catch (const Form::GradeTooLowException& e) {

        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << BLUE << form << RESET << std::endl;

    Bureaucrat bob("Bob", 100);
    Form form2;
    
    std::cout << BLUE << bob << RESET << std::endl;
    std::cout << BLUE << form2 << RESET << std::endl;
   
    try {
        
        form2.beSigned(bob);
    }
    catch (const Form::GradeTooLowException& e) {

        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << BLUE << form2 << RESET << std::endl;
    
    std::cout << MAGENTA << "\nSignFrom function\n" << RESET << std::endl;

    marc.signForm(form);
    bob.signForm(form2);
    
    return (0);
}
