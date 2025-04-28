/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:21:46 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/27 18:26:05 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
#define SERIALIZER_H

#pragma once

#include <iostream>
#include <stdint.h>

struct Data {
  
    std::string name;
    int age;
};

class Serializer
{
    public:
        ~Serializer();

        static uintptr_t serialize( Data* ptr); // ( pour recuperer une valeur brute de type unintptr_t, pour stocker une addresse memoire brute)
        static Data* deserialize( uintptr_t raw );

    private:
        Serializer();
        Serializer( const Serializer& copy );
        Serializer& operator=( const Serializer& other );
};

#endif

// un uintptr_t c est un entier non signe capable de contenir un pointeur vers void
// serialize va etre utile pour passer une addresse memoire sous une forme plus generique