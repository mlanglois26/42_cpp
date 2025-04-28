/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:04:03 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 09:38:51 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Default Animal") {
    
    std::cout << GREEN << "Constructor called for Animal" << RESET <<std::endl;
    return ;
}

Animal::Animal(const Animal& copy) : _type(copy._type) {
    
    std::cout << GREEN << "Copy Constructor called for Animal" << RESET <<std::endl;
    return ;
}

Animal& Animal::operator=(const Animal& other) {

    std::cout << GREEN << "Assignment Operator called for Animal" << RESET <<std::endl;
    if (this != &other) {
        this->_type = other._type;
    }
    return (*this);
}

Animal::~Animal() {
    
    std::cout << RED << "Destructor called for Animal" << RESET << std::endl;

    return ;
}

void Animal::setType(std::string type) {

    this->_type = type;
    return ;
}

std::string Animal::getType() const {

    return (this->_type);
}

void Animal::makeSound() const {

    std::cout << this->getType() << " says AHAHAHHAHAHA" << std::endl;
}

