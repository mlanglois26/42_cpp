/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:07:24 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/08 16:01:49 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat( const Cat& copy );
        Cat& operator=( const Cat& other );
        virtual ~Cat();

        virtual void makeSound() const;
};

#endif
