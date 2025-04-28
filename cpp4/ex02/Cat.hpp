/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:07:24 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 11:05:19 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
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
