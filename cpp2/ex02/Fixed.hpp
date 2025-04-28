/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:26:21 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/08 09:51:30 by malanglo         ###   ########.fr       */
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

        /* setters & getters */

        void setFixedPointValuefromInt(int const value);
        void setFixedPointValuefromFloat(float const value);
        int getFixedPointValueFromInt() const;
        float getFixedPointValueFromFloat() const;
        float toFloat( void ) const;
        
        /* comparing operators */

        bool operator==( const Fixed& other ) const;
        bool operator!=( const Fixed& other ) const;
        bool operator>( const Fixed& other ) const;
        bool operator<( const Fixed& other ) const;
        bool operator>=( const Fixed& other ) const;
        bool operator<=( const Fixed& other ) const;

        /* arithmetic operators */

        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;
        
        /* incremetatiom & decrementation operators */
        
        Fixed operator++(); // prefix
        Fixed operator++(int); // suffix; int n est pas utilise c est un indicateur pour le compilateur
        Fixed operator--();
        Fixed operator--(int);

        /* min-max functions */

        static Fixed min(Fixed& a, Fixed& b);
        static Fixed min(const Fixed& a, const Fixed& b);
        static Fixed max(Fixed& a, Fixed& b);
        static Fixed max(const Fixed& a, const Fixed& b);

    private:
        int _fixedValue;
        static const int _fracPart;
};

std::ostream& operator<<(std::ostream& o, const Fixed& rhs);

#endif

