/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:59:02 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/19 13:03:34 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m" 

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _grade_to_sign;
        const int _grade_to_exec;
        
    public:
        Form();
        Form( const Form& copy );
        Form& operator=( const Form& other );
        ~Form();
        
        Form( const std::string& name, const int grade_to_sign, const int grade_to_exec );

        std::string getName() const;
        
        void setStatus( bool is_signed );
        bool getStatus() const;
        
        void setGrade(int grade);
        int getGradeToSign() const;
        int getGradeToExec() const;

        void beSigned( const Bureaucrat& bureaucrat );

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& o, const Form& rhs);

#endif
