/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:14:53 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/03 13:06:21 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#pragma once

#include <iostream>
#include <cstring>
#include "Weapon.hpp"

class Weapon;

class HumanB
{
    public:
        HumanB(std::string name);
        ~HumanB();

        void setName(std::string name);
        std::string getName() const;
        void attack() const ;
        void setWeapon(Weapon* weaponObj);
        std::string getWeapon();
        
    private:
        Weapon* _weaponObj;
        std::string _name;
};

#endif
