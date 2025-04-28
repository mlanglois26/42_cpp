/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:42:47 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/09 16:04:31 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {

    ClapTrap p;
    ClapTrap a("Marc");
    ClapTrap b(a);
    ClapTrap c("Denis");
    c = b;
    
    ClapTrap d("Joe");
    
    unsigned int m = 3;
    unsigned int n = 2;
    unsigned int v = 1;
    
    c.getPointsData();
    d.getPointsData();
    
    c.setAttackDamage(m);
    d.setAttackDamage(n);
    
    c.getPointsData();
    d.getPointsData();
    
    attackActionA(c, d);
    attackActionB(c, d);

    c.beRepaired(v);
    d.beRepaired(v);
    
    c.getPointsData();
    d.getPointsData();

    attackActionA(c, d);
    attackActionA(c, d);
    attackActionB(c, d);
    attackActionB(c, d);
    attackActionA(c, d);
    attackActionB(c, d);
    
    d.beRepaired(v);
    d.beRepaired(v);

    attackActionB(c, d);
    attackActionA(c, d);
    attackActionB(c, d);

    attackActionA(c, d);
    attackActionA(c, d);
    attackActionA(c, d);
    attackActionA(c, d);
    attackActionA(c, d);

    return (0);
}
