/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:01:44 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/03 12:50:38 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <iostream>
#include <cstring>

#pragma once

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

class Harl
{
    public:
        Harl();
        ~Harl();
        void complainFilter( const std::string level );

    private:
        int assignCode(std::string level );
        void _debug( void );
        void _info( void );
        void _warning( void );
        void _error( void );
        void _default( void );
};

#endif
