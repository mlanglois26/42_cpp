/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:14:13 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/03 13:08:56 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : _name(name), _weaponObj(nullptr) {
    
    std::cout << GREEN << "Constructor de HumanB called." << RESET << std::endl;
    return ;
}

HumanB::~HumanB() {

    std::cout << RED << "Destructor de HumanB called." << RESET << std::endl;
    return ;
}

void HumanB::setName(std::string name) {
    
    this->_name = name;
}

std::string HumanB::getName() const {
    
    return (this->_name);
}

void HumanB::setWeapon(Weapon* weaponObj) {
    
    this->_weaponObj = weaponObj;
}

std::string HumanB::getWeapon() {
    
    return (this->_weaponObj->getType());
}

void HumanB::attack() const {
    
    if (this->_weaponObj == nullptr) {
        
        std::cout << this->getName() << " is fighting with their " << YELLOW << "bare hands." << RESET << std::endl;
    }
    else {
        
        std::cout << this->getName() << " attacks with their " <<  BLUE << this->_weaponObj->getType() << RESET << std::endl;
    }
}
