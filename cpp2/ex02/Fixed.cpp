/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:26:12 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/09 10:04:04 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* init */

const int Fixed::_fracPart = 8;

/* Canonic Form */

Fixed::Fixed() : _fixedValue(0) {
    
    return ;
}

Fixed::Fixed(const Fixed& copy) : _fixedValue(copy._fixedValue) {
    
    return ;
}

Fixed& Fixed::operator=(const Fixed& surcharge) {
    
    if (this != &surcharge)
    {
        this->_fixedValue = surcharge._fixedValue;
    }
    return (*this);
}

Fixed::~Fixed() {}

/* Constructors with int and float as arguments */

Fixed::Fixed(int const value) {
    
    setFixedPointValuefromInt(value);
}

Fixed::Fixed(float const value) {
    
    setFixedPointValuefromFloat(value);
}

/* setters & getters */

void Fixed::setFixedPointValuefromInt(int const value) {

    this->_fixedValue = value << this->_fracPart;
}

void Fixed::setFixedPointValuefromFloat(float const value) {

    this->_fixedValue = (int)(roundf(value * ( 1 << _fracPart)));
}

int Fixed::getFixedPointValueFromInt() const {
    
    return (this->_fixedValue);
}

float Fixed::getFixedPointValueFromFloat() const {
    
    return ((float)this->_fixedValue);
}

float Fixed::toFloat(void) const {

    return (this->getFixedPointValueFromFloat() / (1 << _fracPart));
}

/* surcharge de l operateur d insertion */

std::ostream& operator<<(std::ostream& os, const Fixed& rhs) {
    
    os << rhs.toFloat();
    return (os);
}

/* comparing operators */

bool Fixed::operator==(const Fixed& other) const {

    if (this->toFloat() == other.toFloat())
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed& other) const {

    if (this->toFloat() != other.toFloat())
        return (true);
    return (false);
}

bool Fixed::operator>(const Fixed& other) const {

    if (this->toFloat() > other.toFloat())
        return (true);
    return (false);
}

bool Fixed::operator<(const Fixed& other) const {

    if (this->toFloat() < other.toFloat())
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed& other) const {

    if (this->toFloat() >= other.toFloat())
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed& other) const {

    if (this->toFloat() <= other.toFloat())
        return (true);
    return (false);
}

/* arithmetic operators */

Fixed Fixed::operator+(const Fixed& other) const {

    Fixed res;

    res = this->toFloat() + other.toFloat();
    return (res);
}

Fixed Fixed::operator-(const Fixed& other) const {

    Fixed res;

    res = this->toFloat() - other.toFloat();
    return (res);
}

Fixed Fixed::operator*(const Fixed& other) const {

    Fixed res;

    res = this->toFloat() * other.toFloat();
    return (res);
}

Fixed Fixed::operator/(const Fixed& other) const {

    Fixed res;

    res = this->toFloat() / other.toFloat();
    return (res);
}

/* increment & decrement operators */

Fixed Fixed::operator++() {

    this->_fixedValue++;
    return (*this);
}

Fixed Fixed::operator++(int) {

    Fixed tmp(*this);
    
    this->_fixedValue++;
    return (tmp);
}

Fixed Fixed::operator--() {

    this->_fixedValue--;
    return (*this);
}

Fixed Fixed::operator--(int) {

    Fixed tmp(*this);
    
    this->_fixedValue--;
    return (tmp);
}

/* min max functions */

Fixed Fixed::min(Fixed& a, Fixed &b) {
    
    Fixed res;
    
    if (a < b)
        res = a;
    else
        res = b;
    return (res);
}

Fixed Fixed::min(const Fixed& a, const Fixed &b) {
    
    Fixed res;
    
    if (a < b)
        res = a;
    else
        res = b;
    return (res);
}

Fixed Fixed::max(Fixed& a, Fixed &b) {
    
    Fixed res;
    
    if (a > b)
        res = a;
    else
        res = b;
    return (res);
}

Fixed Fixed::max(const Fixed& a, const Fixed &b) {
    
    Fixed res;
    
    if (a > b)
        res = a;
    else
        res = b;
    return (res);
}