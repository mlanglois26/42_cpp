/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:07:24 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 10:00:13 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat( const Cat& copy );
        Cat& operator=( const Cat& other );
        ~Cat();

        virtual void makeSound() const;
        Cat* clone() const;

    private:
        Brain* _brain;
};

#endif
