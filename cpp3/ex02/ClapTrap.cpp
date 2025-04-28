/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:37:23 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/09 16:07:57 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* canonic form */

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    
    std::cout << GREEN << "Default Constructor called for ClapTrap Class." << RESET << std::endl;
    return ;
}

ClapTrap::ClapTrap(const ClapTrap& copy) : _name(copy._name),
                                           _hitPoints(copy._hitPoints), 
                                           _energyPoints(copy._energyPoints), 
                                           _attackDamage(copy._attackDamage) {
    
    std::cout << GREEN << "Copy Constructor called for ClapTrap Class." << RESET << std::endl;
    return ;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    
    std::cout << GREEN << "Assignment Operator called for ClapTrap Class." << RESET << std::endl;
    
    if (this != &other) {
        
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap() {
    
    std::cout << RED << "Destructor called for ClapTrap Class instance's with the name of " << this->getName() << RESET << std::endl;
    return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    
    std::cout << GREEN << "Name Constructor called for ClapTrap Class." << RESET << std::endl;
    return ;
}

/* setters & getters */

void ClapTrap::setAttackDamage(unsigned int damagePoints) {
    
    this->_attackDamage = damagePoints;
}

std::string ClapTrap::getName() const {

    return (this->_name);
}

int ClapTrap::getHitPoints() const {

    return (this->_hitPoints);
}

int ClapTrap::getEnergyPoints() const {

    return (this->_energyPoints);
}

int ClapTrap::getAttackDamage() const {

    return (this->_attackDamage);
}

/* functions */

void ClapTrap::attack(const std::string& target) {

    std::cout << YELLOW << this->getName() << " attacks " << target  << " causing " << this->getAttackDamage() << " points of damage!" << RESET << std::endl;
    this->_energyPoints -= 1;
}


void ClapTrap::takeDamage(unsigned int amount) {

    std::cout << MAGENTA << "Oh no " << this->getName() << " just got attacked... He looses " << amount << " point" << RESET << std::endl;
    this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {

    std::cout << BLUE << this->getName() << " needs assitance. He is getting repared. He looses 1 energy point and regains " << amount << " hit points." << RESET << std::endl;
    this->_hitPoints += amount;
    this->_energyPoints -= 1;
}

void ClapTrap::getPointsData() {

    std::cout << "Name = " << this->getName() << std::endl;
    std::cout << "Hit Points = " << this->getHitPoints() << std::endl;
    std::cout << "Energy Points = " << this->getEnergyPoints() << std::endl;
    std::cout << "Attack Damage = " << this->getAttackDamage() << std::endl << std::endl;
}

bool ClapTrap::healthy() {

    if (this->_hitPoints <= 0) {
        
        std::cout << GREEN << this->getName() << " has no hit points, he must be repaired." << RESET << std::endl;
        return (1);
    }
    return (0);
}

bool ClapTrap::dead() {

    if (this->_energyPoints <= 0) {
        
        std::cout << GREEN << this->getName() << " has no energy points, he must be repaired." << RESET << std::endl;
        return (1);
    }
    return (0);
}

/* wrappers */

void attackActionA(ClapTrap& a, ClapTrap& b) {

    if (a.dead() == 0 && a.healthy() == 0) {
        
        a.attack(b.getName());
        b.takeDamage(a.getAttackDamage());

        a.getPointsData();
        b.getPointsData();
    }
}

void attackActionB(ClapTrap& a, ClapTrap& b) {

    if (b.dead() == 0 && b.healthy() == 0) {

        b.attack(a.getName());
        a.takeDamage(b.getAttackDamage());

        a.getPointsData();
        b.getPointsData();
    }
}