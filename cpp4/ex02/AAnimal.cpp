/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:04:03 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/11 08:47:37 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {
    
    std::cout << GREEN << "Default Constructor called for AAnimal" << RESET <<std::endl;
    return ;
}

AAnimal::AAnimal(const AAnimal& copy) : _type(copy._type) {
    
    std::cout << GREEN << "Copy Constructor called for AAnimal" << RESET <<std::endl;
    return ;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {

    std::cout << GREEN << "Assignment Operator called for AAnimal" << RESET <<std::endl;
    if (this != &other) {
        this->_type = other._type;
    }
    return (*this);
}

AAnimal::~AAnimal() {
    
    std::cout << RED << "Destructor called for AAnimal" << RESET << std::endl;

    return ;
}

void AAnimal::setType(std::string type) {

    this->_type = type;
    return ;
}

std::string AAnimal::getType() const {

    return (this->_type);
}

// void AAnimal::makeSound() const {

//     std::cout << "The Default AAnimal sound is: 'AHAHAHA'" << std::endl;
// }

