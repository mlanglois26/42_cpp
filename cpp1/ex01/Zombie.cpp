/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:54:09 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/03 12:24:09 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
    
    std::cout << GREEN << "Constructeur called" << RESET << std::endl;
    return ;
}

Zombie::~Zombie() {
    
    std::cout << RED << "Destructeur called on an instance of the Zombie class that has the private attribute _name having for value " << this->getName() << RESET << std::endl;
    return ;
}

void Zombie::setName(std::string name) {
    this->_name = name;
}

std::string Zombie::getName() const {
    
    return (this->_name);
}

void Zombie::annonce() {
    
    std::cout << " " << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl; 
}
