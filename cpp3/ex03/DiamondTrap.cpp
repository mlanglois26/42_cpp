/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:34:56 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/09 16:36:36 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

/* canonic form */

DiamondTrap::DiamondTrap() {
    
    this->_name = "Carl 3";
    ClapTrap::_name = _name + "_clap_name";
    FragTrap::_hitPoints = 100;
	ScavTrap::_energyPoints = 50;
	FragTrap::_attackDamage = 30;
    std::cout << GREEN << "Default constructor called for DiamondTrap class" << RESET << std::endl;
    return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) {
    
    this->_name = copy._name;
    ClapTrap::_name = copy._name + "_clap_name";
    this->_hitPoints = copy._hitPoints;
    this->_energyPoints = copy._energyPoints;
    this->_attackDamage = copy._attackDamage;

    std::cout << GREEN << "Copy Constructor called for DiamondTrap Class." << RESET << std::endl;
    return ;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {

    std::cout << GREEN << "Operator Assignment called for DiamondTrap Class." << RESET << std::endl;
    
    if (this != &other) {
        
        this->_name = other._name;
        ClapTrap::_name = other._name + "_clap_name";
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap() {
    
    std::cout << RED << "Destructor called for DiamondTrap class" << RESET << std::endl;
    return ;
}

DiamondTrap::DiamondTrap(std::string name) {
    
    this->_name = name;
    ClapTrap::_name = _name + "_clap_name";
    FragTrap::_hitPoints = 100;
	ScavTrap::_energyPoints = 50;
	FragTrap::_attackDamage = 30;
    std::cout << GREEN << "Name Constructor called for DiamondTrap Class." << RESET << std::endl;
    return ;
}

/* functions */

std::string DiamondTrap::getName() const {

    return (this->_name);
}

std::string DiamondTrap::getClapTrapName() const {

    return (ClapTrap::_name);
}

void DiamondTrap::whomAmI() {

    std::cout << BLUE << "Who am I? : my name is " << this->getName() << " and my ClassTrap Name is " << this->getClapTrapName() << RESET << std::endl; 
}
