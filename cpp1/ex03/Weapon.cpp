/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:09:50 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/03 13:08:32 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
    
    std::cout << GREEN << "Constructor de Weapon called." << RESET << std::endl;
};

Weapon::~Weapon() {
    
    std::cout << RED << "Destructor de Weapon " << this->getType() << " called." << RESET << std::endl;

}

void Weapon::setType(std::string type) {
    
    this->_type = type;
}


const std::string& Weapon::getType() const {
    
    return (this->_type);
}