/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:59:02 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/20 11:04:25 by malanglo         ###   ########.fr       */
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

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _grade_to_sign;
        const int _grade_to_exec;
    
    public:
        AForm(const std::string &name, const int &grade_to_sign, const int &grade_to_exec);
        AForm( const AForm& copy );
        AForm& operator=( const AForm& other );
        virtual ~AForm();
        
        std::string getName() const;
        void setStatus( bool is_signed );
        bool getStatus() const;
        void setGrade(int grade);
        int getGradeToSign() const;
        int getGradeToExec() const;
        virtual std::string getTarget() const = 0;

        void beSigned( const Bureaucrat& bureaucrat );

        class GradeTooLowExecption : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        virtual void execute( Bureaucrat const & executor ) const = 0; 
};

std::ostream& operator<<(std::ostream& o, const AForm& rhs);

#endif
