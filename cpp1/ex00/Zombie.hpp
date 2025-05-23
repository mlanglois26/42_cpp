/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:54:03 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/03 18:03:32 by malanglo         ###   ########.fr       */
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
#define YELLOW  "\033[33m"

class Zombie
{
    public:
        Zombie(std::string name);
        ~Zombie();

        std::string getName() const ;
        void annonce( void );

    private:
        std::string _name;
};

void    randomChump( std::string name );
Zombie* newZombie( std::string name );
Zombie* randomChumpHeap( std::string name );

#endif
