/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:54:03 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/01 17:45:18 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <cctype>
#include <cstring>

#pragma once

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"

class Zombie
{
    public:
        Zombie();
        ~Zombie();

        void setName( std::string name );
        std::string getName() const ;
        void annonce( void );

    private:
        std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
