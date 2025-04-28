/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:26:21 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/08 09:07:05 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#pragma once

#include <iostream>
#include <cmath>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

class Fixed
{
    public:
        Fixed( void );
        Fixed( const Fixed& copy);
        Fixed& operator=( const Fixed& surcharge );
        Fixed( int const value );
        Fixed( float const value );
        ~Fixed();

        void setRawBits( int const raw );
        int getRawBits( void ) const;
        
        void setFixedPointValuefromInt(int const value);
        void setFixedPointValuefromFloat(float const value);
        int getFixedPointValueFromInt() const;
        float getFixedPointValueFromFloat() const;

        int toInt( void ) const;
        float toFloat( void ) const;

    private:
        int _fixedValue;
        static const int _fracPart;
};

std::ostream& operator<<(std::ostream& o, const Fixed& rhs);

#endif

