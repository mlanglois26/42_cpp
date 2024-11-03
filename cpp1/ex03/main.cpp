/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:08:13 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/03 13:09:12 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        Weapon club = Weapon("axe");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("gun");
        bob.attack();
    }
    
    std::cout << std::endl << "------------------------------" << std::endl << std::endl;
    
    {
        Weapon club = Weapon("baseball bat");
        HumanB jim("Jim");
        jim.setWeapon(&club);
        jim.attack();
        club.setType("axe");
        jim.attack();
        jim.setWeapon(nullptr);
        jim.attack();
        jim.setWeapon(&club);
        jim.attack();
    }
    
    return (0);
}
