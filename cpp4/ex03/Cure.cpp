/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:28:34 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 14:04:50 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* canonic form */

Cure::Cure() : AMateria("cure") {
    
    std::cout << GREEN << "Default Constructor called for Cure" << RESET <<std::endl;
    return ;
}

Cure::Cure(const Cure& copy) : AMateria(copy) {

    *this = copy;
    std::cout << GREEN << "Copy Constructor called for Cure" << RESET <<std::endl;
    return ;
}

Cure& Cure::operator=(const Cure& other) {

    std::cout << GREEN << "Operator Assignment called for Cure" << RESET <<std::endl;

    if (this != &other) {

        AMateria::operator=(other);
    }
    return (*this);
}

Cure::~Cure() {
    
    std::cout << RED << "Destructor called for Cure" << RESET <<std::endl;
    return ;
}

/* functions */

AMateria *Cure::clone() const {
    
    return (new Cure(*this));
}

void Cure::use(ICharacter& target) {

    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

