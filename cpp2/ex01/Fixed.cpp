/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:05:00 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/08 09:05:59 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* init */

const int Fixed::_fracPart = 8;

/* Canonic Form */

Fixed::Fixed() : _fixedValue(0) {
    
    std::cout << GREEN << "Default constructor called" << RESET << std::endl;
    return ;
}

Fixed::Fixed(const Fixed& copy) : _fixedValue(copy._fixedValue) {
    
    std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
    return ;
}

Fixed& Fixed::operator=(const Fixed& surcharge) {
    
    std::cout << GREEN << "Assignment operator called" << RESET << std::endl;
    if (this != &surcharge)
    {
        this->_fixedValue = surcharge._fixedValue;
    }
    return (*this);
}

Fixed::~Fixed() {
    
    std::cout << RED << "Destructor called" << RESET << std::endl;
}

/* Constructors with int and float as arguments */

Fixed::Fixed(int const value) {
    
    setFixedPointValuefromInt(value);
    std::cout << BLUE << "Int constructor called" << RESET << std::endl;
}

Fixed::Fixed(float const value) {
    
    setFixedPointValuefromFloat(value);
    std::cout << BLUE << "Float constructor called" << RESET << std::endl;
}

/* surcharge de l operateur d insertion */

std::ostream& operator<<(std::ostream& os, const Fixed& rhs) {
    
    os << rhs.toFloat();
    return (os);
}

/* setters & getters */

void Fixed::setRawBits(int const raw) {
    
    this->_fixedValue = raw;
}

int Fixed::getRawBits() const {
    
    return (this->_fixedValue);
}

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
    
    return (this->_fixedValue);
}

/* toInt and toFloat */

int Fixed::toInt(void) const {
    
    return (this->getFixedPointValueFromInt() >> _fracPart);
}

float Fixed::toFloat(void) const {

    return (this->getFixedPointValueFromFloat() / (1 << _fracPart));
}



