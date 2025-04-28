/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:05:34 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 10:58:03 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#pragma once

#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m" 

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal( const WrongAnimal& copy );
        WrongAnimal& operator=( const WrongAnimal& other );
        virtual ~WrongAnimal();

        void setType( std::string name );
        std::string getType() const;
        void makeSound() const;

    private:
        std::string _type;

};
#endif
