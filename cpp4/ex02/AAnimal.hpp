/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:03:52 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/11 08:58:44 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
#define AANIMAL_H

#pragma once

#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m" 

class AAnimal
{
    public:
        void setType( std::string name );
        std::string getType() const;
        virtual void makeSound() const = 0;

    protected:
        AAnimal();
        AAnimal( const AAnimal& copy );
        AAnimal& operator=( const AAnimal& other );
        virtual ~AAnimal();
        std::string _type;
};

#endif
