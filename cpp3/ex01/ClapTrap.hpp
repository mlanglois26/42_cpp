/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:37:07 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/09 16:05:57 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#pragma once

#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m" 

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap( const ClapTrap& copy );
        ClapTrap& operator=( const ClapTrap& surcharge );
        ~ClapTrap();
        ClapTrap( std::string name );

        /* setters & getters */

        void setName(std::string name);
        void setAttackDamage(unsigned int damagePoints);

        std::string getName() const;
        int getHitPoints() const;
        int getEnergyPoints() const;
        int getAttackDamage() const;

        /* actions */
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        void getPointsData();
        bool healthy();
        bool dead();

    protected:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;

};

void attackActionA(ClapTrap& a, ClapTrap& b);
void attackActionB(ClapTrap& a, ClapTrap& b);

#endif
