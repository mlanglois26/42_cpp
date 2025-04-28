/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:07:19 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/20 11:02:16 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#pragma once

#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm( const RobotomyRequestForm& copy );
        RobotomyRequestForm& operator=( const RobotomyRequestForm& other );
        ~RobotomyRequestForm();

        RobotomyRequestForm( const std::string& target);

        virtual std::string getTarget() const;
        virtual void execute( const Bureaucrat& bureaucrat ) const;
    
    private:
        std::string _target;
};

#endif
