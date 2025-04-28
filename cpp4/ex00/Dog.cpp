/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:06:47 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 09:32:42 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    
    std::cout << BLUE << "Constructor called for Dog" << RESET << std::endl;
    Animal::setType("Dog");
    return ;
}

Dog::Dog(const Dog& copy) : Animal(copy) {

    std::cout << BLUE << "Copy Constructor called for Dog" << RESET << std::endl;
    return ;
}

Dog& Dog::operator=(const Dog& other) {

    std::cout << BLUE << "Assignment Operator called for Dog" << RESET << std::endl;

    if (this != &other) {
        
        Animal::operator=(other);
    }
    return (*this);
}

Dog::~Dog() {
    
    std::cout << RED << "Destructor for Dog called" << RESET << std::endl;
    return ;
}

void Dog::makeSound() const {

    std::cout << this->getType() << " says Wouf Wouf" << std::endl;
}