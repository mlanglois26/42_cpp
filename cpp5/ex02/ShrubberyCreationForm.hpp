/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:57:39 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/20 10:59:47 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#pragma once

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm( const ShrubberyCreationForm& copy );
        ShrubberyCreationForm& operator=( const ShrubberyCreationForm& other );
        ~ShrubberyCreationForm();

        ShrubberyCreationForm( const std::string& target);

        virtual std::string getTarget() const;
        virtual void execute( const Bureaucrat& bureaucrat ) const;

    private:
        std::string _target;
};

#endif
