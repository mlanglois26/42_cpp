/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:22:45 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 12:42:37 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::~AMateria() {
    
    std::cout << RED << "Destructor called for AMateria" << RESET <<std::endl;
    return ;
}

/* Name Constructor */

AMateria::AMateria(std::string const & type) : _type(type) {

    std::cout << GREEN << "Type Constructor called for AMateria" << RESET <<std::endl;
    return ;
}

/* setters & getters */

void AMateria::setType(std::string type) {

    this->_type = type;
}

std::string const & AMateria::getType() const {

    return (this->_type);
}

/* functions */

void AMateria::use(ICharacter& target) {

    std::cout << "Amateria " << this->getType() << " has been used on " << target.getName() << std::endl;
}