/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:06:58 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 10:00:25 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog( const Dog& copy );
        Dog& operator=( const Dog& other );
        ~Dog();

        virtual void makeSound() const;
        Dog* clone() const;

    private:
        Brain* _brain;
};

#endif
