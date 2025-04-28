/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:03:52 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/08 16:04:08 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#pragma once

#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m" 

class Animal
{
    public:
        Animal();
        Animal( const Animal& copy );
        Animal& operator=( const Animal& other );
        virtual ~Animal();

        void setType( std::string name );
        std::string getType() const;
        virtual void makeSound() const;

    private:
        std::string _type;

};

#endif
