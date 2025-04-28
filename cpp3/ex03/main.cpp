/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:26:55 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/09 16:35:45 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {

    DiamondTrap a;
    DiamondTrap b("Denis");

    a.getPointsData();
    b.getPointsData();
    
    a.attack(b.getName());
    b.takeDamage(a.getAttackDamage());

    a.getPointsData();
    b.getPointsData();

    b.guardGate();
    b.highFivesGuys();
    b.whomAmI();

    return (0);
}