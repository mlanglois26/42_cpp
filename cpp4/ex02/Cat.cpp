/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:07:32 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 11:04:01 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    
    AAnimal::setType("Cat");
    _brain = new Brain();
    std::cout << YELLOW << "Default Constructor called for Cat" << RESET << std::endl;
    return ;
}

Cat::Cat(const Cat& copy) : AAnimal(copy) {

    this->_brain = new Brain(*copy._brain);
    std::cout << YELLOW << "Copy Constructor called for Cat" << RESET <<std::endl;
    return ;
}

Cat& Cat::operator=(const Cat& other) {

    std::cout << YELLOW << "Assignment Operator called for Cat" << RESET <<std::endl;
    
    if (this != &other) {
        
        AAnimal::operator=(other);
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return (*this);
}

Cat::~Cat() {
    
    delete this->_brain;
    std::cout << RED << "Destructor for Cat" << RESET << std::endl;
    return ;
}

void Cat::makeSound() const {

    std::cout << this->getType() << " says: 'Miaou'" << std::endl;
}

Cat* Cat::clone() const {

    std::cout << "Clone for Cat called" << std::endl;
    return (new Cat(*this));
}