/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:05:43 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 09:42:07 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    
    std::cout << YELLOW << "Constructor called for WrongCat" << RESET << std::endl;
    WrongAnimal::setType("WrongCat");
    return ;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) {

    std::cout << YELLOW << "Copy Constructor called for WrongCat" << RESET <<std::endl;
    return ;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {

    std::cout << YELLOW << "Assignment Operator called for WrongCat" << RESET <<std::endl;
    
    if (this != &other) {
        
        WrongAnimal::operator=(other);
    }
    return (*this);
}

WrongCat::~WrongCat() {
    
    std::cout << RED << "Destructor for WrongCat" << RESET << std::endl;
    return ;
}

void WrongCat::makeSound() const {

    std::cout << this->getType() << " says Wrong Miaou" << std::endl;
}