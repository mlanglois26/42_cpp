/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:23:07 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 12:39:26 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
#define AMATERIA_H

#pragma once

#include <iostream>
#include "ICharacter.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m" 

class ICharacter;

class AMateria
{
    protected:
        std::string _type;

    public:

        virtual ~AMateria(); 
        AMateria( std::string const & type);
        
        void setType(std::string type);
        std::string const & getType() const;
        
        virtual AMateria* clone() const = 0;
        virtual void use( ICharacter& target ) = 0;
};

#endif
