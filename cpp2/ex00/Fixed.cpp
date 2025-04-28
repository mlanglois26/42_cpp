/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:04:28 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/08 08:38:41 by malanglo         ###   ########.fr       */
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
    
    std::cout << GREEN << "Copy assignment operator called" << RESET << std::endl;
    if (this != &surcharge)
    {
        this->_fixedValue = surcharge._fixedValue;
    }
    return (*this); 
}

Fixed::~Fixed() {
    
    std::cout << RED << "Destructor called" << RESET << std::endl;
    return ;
}

/* setters & getters */

void Fixed::setRawBits(int const raw) {
    
    std::cout << YELLOW << "setRawBits member function called" << RESET << std::endl;
    this->_fixedValue = raw;
}

int Fixed::getRawBits() const {
    
    std::cout << YELLOW << "getRawBits member function called" << RESET << std::endl;
    return (this->_fixedValue);
}