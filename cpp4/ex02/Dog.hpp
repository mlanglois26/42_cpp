/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:06:58 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 11:06:56 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
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
