/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:07:32 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 09:32:31 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    
    std::cout << YELLOW << "Constructor called for Cat" << RESET << std::endl;
    Animal::setType("Cat");
    return ;
}

Cat::Cat(const Cat& copy) : Animal(copy) {

    std::cout << YELLOW << "Copy Constructor called for Cat" << RESET <<std::endl;
    return ;
}

Cat& Cat::operator=(const Cat& other) {

    std::cout << YELLOW << "Assignment Operator called for Cat" << RESET <<std::endl;
    
    if (this != &other) {
        
        Animal::operator=(other);
    }
    return (*this);
}

Cat::~Cat() {
    
    std::cout << RED << "Destructor for Cat" << RESET << std::endl;
    return ;
}

void Cat::makeSound() const {

    std::cout << this->getType() << " says Miaou" << std::endl;
}