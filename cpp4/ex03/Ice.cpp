/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:28:45 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 14:05:02 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* canonic form */

Ice::Ice() : AMateria("ice") {
    
    std::cout << GREEN << "Default Constructor called for Ice" << RESET <<std::endl;
    return ;
}

Ice::Ice(const Ice& copy) : AMateria(copy) {

    *this = copy;
    std::cout << GREEN << "Copy Constructor called for Ice" << RESET <<std::endl;
    return ;
}

Ice& Ice::operator=(const Ice& other) {

    std::cout << GREEN << "Operator Assignment called for Ice" << RESET <<std::endl;

    if (this != &other) {

        AMateria::operator=(other);
    }
    return (*this);
}

Ice::~Ice() {
    
    std::cout << RED << "Destructor called for Ice" << RESET <<std::endl;
    return ;
}

/* functions */

AMateria* Ice::clone() const {
    
    return (new Ice(*this));
}

void Ice::use(ICharacter& target) {

    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}