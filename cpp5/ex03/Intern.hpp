/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:09:20 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/19 13:54:27 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#pragma once

#include <iostream>
#include "AForm.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m" 

class Intern
{
    public:
        Intern();
        Intern( const Intern& copy );
        Intern& operator=( const Intern& other );
        ~Intern();

        AForm* makeForm( std::string formName, std::string formTarget );
};

#endif
