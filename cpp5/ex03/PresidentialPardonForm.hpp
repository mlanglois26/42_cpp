/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:07:44 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/20 11:02:10 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm( const PresidentialPardonForm& copy );
        PresidentialPardonForm& operator=( const PresidentialPardonForm& other );
        ~PresidentialPardonForm();
        
        PresidentialPardonForm( const std::string& target);
        
        virtual std::string getTarget() const;
        virtual void execute( const Bureaucrat& bureaucrat ) const;
    
    private:
        std::string _target;
};



#endif
