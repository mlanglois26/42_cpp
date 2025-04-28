/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:04:37 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/05 19:09:24 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#pragma once

#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed&);
        Fixed& operator=( const Fixed& surcharge );
        ~Fixed();

        void setRawBits( int const raw );
        int getRawBits( void ) const;

    private:
        int _fixedValue;
        static const int _fracPart;
};

#endif
