/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:06:47 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 10:50:49 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    
    std::cout << BLUE << "Constructor called for Dog" << RESET << std::endl;
    Animal::setType("Dog");
    _brain = new Brain();
    return ;
}

Dog::Dog(const Dog& copy) : Animal(copy) {

    this->_brain = new Brain(*copy._brain);
    std::cout << BLUE << "Copy Constructor called for Dog" << RESET << std::endl;
    return ;
}

Dog& Dog::operator=(const Dog& other) {

    std::cout << BLUE << "Assignment Operator called for Dog" << RESET << std::endl;

    if (this != &other) {
        
        Animal::operator=(other);
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return (*this);
}

Dog::~Dog() {
    
    delete this->_brain;
    std::cout << RED << "Destructor for Dog called" << RESET << std::endl;
    return ;
}

void Dog::makeSound() const {

    std::cout << this->getType() << " says Wouf Wouf" << std::endl;
}

Dog* Dog::clone() const {

    std::cout << "Clone for Dog called" << std::endl;
    return (new Dog(*this));
}
