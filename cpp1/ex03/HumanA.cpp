/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:14:03 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/03 13:08:03 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon& weaponObj) : _name(name), _weaponObj(weaponObj) {
    
    std::cout << GREEN << "Constructor de HumanA called." << RESET << std::endl;
    return ;
}

HumanA::~HumanA() {
    
    std::cout << RED << "Destructor de HumanA called." << RESET << std::endl;
    return ;
}

void HumanA::setName(std::string name) {
    
    this->_name = name;
}

std::string HumanA::getName() const {
    
    return (this->_name);
}

void HumanA::attack() const {
    
    std::cout << this->_name << " attacks with their " << BLUE << this->_weaponObj.getType() << RESET << std::endl;
}