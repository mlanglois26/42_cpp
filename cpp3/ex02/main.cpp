/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:26:55 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/09 16:08:28 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

    FragTrap test;
    FragTrap a("Joe");
    FragTrap b("Max");

    unsigned int v = 1;

    a.highFivesGuys();
    
    a.getPointsData();
    b.getPointsData();

    a.attack(b.getName());
    b.takeDamage(a.getAttackDamage());
    
    a.getPointsData();
    b.getPointsData();

    b.attack(a.getName());
    a.takeDamage(b.getAttackDamage());

    a.getPointsData();
    b.getPointsData();

    a.beRepaired(v);
    b.beRepaired(v);
    
    attackActionA(a, b);
    attackActionB(a, b);
    attackActionA(a, b);
    attackActionA(a, b);
    attackActionB(a, b);

    return (0);
}
