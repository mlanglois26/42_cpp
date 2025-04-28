/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:17:25 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/20 09:04:56 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#pragma once

#include <iostream>
#include <exception>
#include "Form.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m" 

class Form;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
        
    public:
        Bureaucrat();
        Bureaucrat( const Bureaucrat& copy );
        Bureaucrat& operator=( const Bureaucrat& other );
        ~Bureaucrat();

        Bureaucrat( const std::string name, int grade );
        
        void setGrade(int grade);
        int getGrade() const;
        std::string getName() const;

        void incrementGrade( int n );
        void decrementGrade( int n );

        class GradeTooHighExecption : public std::exception 
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowExecption : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        
        void signForm( const Form& form );
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& rhs);

#endif
