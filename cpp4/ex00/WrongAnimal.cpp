/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:05:26 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 09:41:52 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Default Wrong Animal") {
    
    std::cout << GREEN << "Constructor called for Animal" << RESET <<std::endl;
    return ;
}


WrongAnimal::WrongAnimal(const WrongAnimal& copy) : _type(copy._type) {
    
    std::cout << GREEN << "Copy Constructor called for WrongAnimal" << RESET <<std::endl;
    return ;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {

    std::cout << GREEN << "Assignment Operator called for WrongAnimal" << RESET <<std::endl;
    if (this != &other) {
        this->_type = other._type;
    }
    return (*this);
}

WrongAnimal::~WrongAnimal() {
    
    std::cout << RED << "Destructor called for WrongAnimal" << RESET << std::endl;
    return ;
}

void WrongAnimal::setType(std::string type) {

    this->_type = type;
    return ;
}

std::string WrongAnimal::getType() const {

    return (this->_type);
}

void WrongAnimal::makeSound() const {

    std::cout << this->getType() << " says OHOHOHOOHOHOH" << std::endl;
}