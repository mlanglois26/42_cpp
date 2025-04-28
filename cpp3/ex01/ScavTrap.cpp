/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:12:53 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/09 16:06:41 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

/* canonic form */

ScavTrap::ScavTrap() : ClapTrap() {
    
    this->_name = "Carl 1";
    this->_hitPoints = 100;
    this->_energyPoints = 50; 
    this->_attackDamage = 20;
    
    std::cout << GREEN << "Default Constructor called for ScavTrap Class." << RESET << std::endl;
    return ;
}


ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {

    std::cout << GREEN << "Copy Constructor called for SvacTrap Class." << RESET << std::endl;
    return ;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {

    std::cout << GREEN << "Assignment Operator called for ScavTrap Class." << RESET << std::endl;

    if (this != &other) {
        
        ClapTrap::operator=(other);
    }
    return (*this);
}

ScavTrap::~ScavTrap() {
    
    std::cout << RED << "Destructor called for ScavTrap Class." << RESET << std::endl;
    return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    
    this->_hitPoints = 100;
    this->_energyPoints = 50; 
    this->_attackDamage = 20;
    
    std::cout << GREEN << "Name Constructor called for ScavTrap Class." << RESET << std::endl;
    return ;
}

/* functions */

void ScavTrap::attack(const std::string& target) {

    std::cout << YELLOW << "!!!! Special message !!!! " << this->getName() << " attacks " << target  << " causing " << this->getAttackDamage() << " points of damage!" << RESET << std::endl;
    this->_energyPoints -= 1;
}

void ScavTrap::guardGate() {

    std::cout << BLUE << this->getName() << " ScavTrap is in Gate keeper mode." << RESET << std::endl;
    return ; 
}

/* wrappers */

void attackActionA(ScavTrap& a, ScavTrap& b) {

    if (a.dead() == 0 && a.healthy() == 0) {
        
        a.attack(b.getName());
        b.takeDamage(a.getAttackDamage());

        a.getPointsData();
        b.getPointsData();
    }
}

void attackActionB(ScavTrap& a, ScavTrap& b) {

    if (b.dead() == 0 && b.healthy() == 0) {

        b.attack(a.getName());
        a.takeDamage(b.getAttackDamage());

        a.getPointsData();
        b.getPointsData();
    }
}