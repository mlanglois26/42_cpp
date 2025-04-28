/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:35:10 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/09 16:33:36 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#pragma once

#include <iostream>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m" 

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap();
        DiamondTrap( const DiamondTrap& copy );
        DiamondTrap& operator=( const DiamondTrap& other );
        ~DiamondTrap();
        DiamondTrap( std::string name );

        std::string getName() const;
        std::string getClapTrapName() const;

        void whomAmI();
    
    private:
        std::string _name;
};

#endif
