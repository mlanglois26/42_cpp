/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:30:11 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/09 14:52:03 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

/* canonic form */

FragTrap::FragTrap() : ClapTrap() {
    
    this->_name = "Carl 2";
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;

    std::cout << GREEN << "Default Constructor called for FragTrap Class." << RESET << std::endl;
    return ;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
    
    std::cout << GREEN << "Copy Constructor called for FragTrap Class." << RESET << std::endl;
    return ;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    
    std::cout << GREEN << "Operator Assignment called for FragTrap Class." << RESET << std::endl;
    
    if (this != &other) {
        
        ClapTrap::operator=(other);
    }
    return (*this);
}

FragTrap::~FragTrap() {
    
    std::cout << RED << "Destructor called for FragTrap Class." << RESET << std::endl;
    return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;

    std::cout << GREEN << "Name Constructor called for FragTrap Class." << RESET << std::endl;
    return ;
}

/* functions */

void FragTrap::highFivesGuys( void ) {

    std::cout << BLUE << this->getName() << " says: High fives guys!" << RESET << std::endl;
}