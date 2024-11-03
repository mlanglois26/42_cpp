/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:15:16 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/03 12:58:54 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#pragma once

#include <iostream>
#include <cstring>

class Weapon;

class HumanA
{
    public:
        HumanA(std::string name, Weapon& weaponObj);
        ~HumanA();

        void setName(std::string name);
        std::string getName() const;
        void attack() const;
        
    private:
        Weapon& _weaponObj;
        std::string _name;
};

#endif
