/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:12:59 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/09 16:09:39 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#pragma once

#include <iostream>

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap( const ScavTrap& copy );
        ScavTrap& operator=( const ScavTrap& other );
        ~ScavTrap();
        ScavTrap( std::string name );

        void attack(const std::string& target);
        void guardGate();
};

void attackActionA(ScavTrap& a, ScavTrap& b);
void attackActionB(ScavTrap& a, ScavTrap& b);

#endif
