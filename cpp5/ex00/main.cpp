/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:16:28 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/20 09:02:41 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {

    std::cout << MAGENTA << "Canonic From \n" << RESET << std::endl;

    Bureaucrat a;
    Bureaucrat b(a);
    Bureaucrat c;
    c = b;
    
    Bureaucrat d("Denis", 14);
    
    std::cout << BLUE << d << RESET << std::endl;
    
    std::cout << MAGENTA << "\nTry Creating Bureaucrates with an out of range grade\n" << RESET << std::endl;
    
    try {
        
        Bureaucrat d("Marie", 0);
    }
    catch (const Bureaucrat::GradeTooHighExecption& e) {

        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowExecption& e) {

        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    } 

    try {
        
        Bureaucrat d("Marie", 160);
    }
    catch (const Bureaucrat::GradeTooHighExecption& e) {

        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowExecption& e) {

        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    } 
    
    std::cout << MAGENTA << "\nTry incrementing & decrementing grades with an out of range grade\n" << RESET << std::endl;
    
    try {

        d.incrementGrade(14);
    }
    catch (const Bureaucrat::GradeTooHighExecption& e)
    {
        std::cout << RED << "Error: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowExecption& e)
    {
        std::cout << RED << "Error: " << e.what() << std::endl;
    }
    std::cout << BLUE << d << RESET << std::endl;
    
    try {

        d.decrementGrade(140);
    }
    catch (const Bureaucrat::GradeTooHighExecption& e)
    {
        std::cout << RED << "Error: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowExecption& e)
    {
        std::cout << RED << "Error: " << e.what() << std::endl;
    }
    std::cout << BLUE << d << RESET << std::endl;

    try {

        d.decrementGrade(130);
    }
    catch (const Bureaucrat::GradeTooHighExecption& e)
    {
        std::cout << RED << "Error: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowExecption& e)
    {
        std::cout << RED << "Error: " << e.what() << std::endl;
    }
    std::cout << BLUE << d << RESET << std::endl;

    return (0);
}
