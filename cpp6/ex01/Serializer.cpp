/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:21:38 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/28 09:42:55 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* Canonic From */

Serializer::Serializer()
{
    std::cout << "Default constructor called for Serializer class" << std::endl;
}

Serializer::Serializer(const Serializer& copy) {

    std::cout << "Copy constructor called for Serializer class" << std::endl;
    *this = copy;
}

Serializer& Serializer::operator=(const Serializer& other) {

    (void)other;
    std::cout << "Operator Assignment called for Serializer class" << std::endl;
    return (*this);
}

Serializer::~Serializer()
{
    std::cout << "Destructor called for Serializer class" << std::endl;
}

/* methods */

uintptr_t Serializer::serialize(Data* ptr) {

    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {

    return (reinterpret_cast<Data*>(raw));
}

// reinterpret_cast est utilise pour convertir un pointer en autre type de pointer 
// par exemple je ne peux pas utiliser static_cast car ce n est pas une conversion safe + c est pour les conversions de type
// reinterpret_cast c est bien pour les conversion a bas niveau