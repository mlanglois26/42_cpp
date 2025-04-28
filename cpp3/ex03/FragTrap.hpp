/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:30:05 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/09 15:12:13 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#pragma once

#include <iostream>

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap();
        FragTrap( const FragTrap& copy );
        FragTrap& operator=( const FragTrap& other );
        ~FragTrap();
        FragTrap(std::string name);

        void highFivesGuys( void );
};

#endif
