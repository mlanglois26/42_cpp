/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:18:04 by malanglo          #+#    #+#             */
/*   Updated: 2024/12/11 13:18:05 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* Canonic Form */

Span::Span() : _maxStock(3) {

    std::cout << GREEN << "Default Constructor called with a maxStock of " <<this->_maxStock << RESET << std::endl;
    return ;
}

Span::~Span() {

    std::cout << RED << "Destructor called" << RESET << std::endl;
    return ;
}

Span::Span(const Span& copy) : _maxStock(copy._maxStock) {

    std::cout << GREEN << "Copy Constructor called" << RESET << std::endl;
    return ;
}

Span& Span::operator=(const Span& other) {

    std::cout << GREEN << "Operator Assignment called" << RESET << std::endl;
    if (this != &other) 
        this->_maxStock = other._maxStock;
    return (*this);
}

/* Unsigned int constructor */

Span::Span(unsigned int maxStock) : _maxStock(maxStock) {

    std::cout << GREEN << "Unsigned int Constructor called with a maxStock of " <<this->_maxStock << RESET << std::endl;
    return ;
}

/* helpers */

void Span::printNums() {

    if (this->_array.size() == 0)
        std::cout << "The array is empty" << std::endl;
    for (unsigned int i = 0; i < this->_array.size(); i++)
        std::cout << this->_array[i] << " ";
    std::cout << std::endl;
}

int Span::getSize() {

    return (this->_array.size());
}

/* addNumber function */

void Span::addNumber(int n) {

    if (this->_array.size() >= this->_maxStock) {

        throw MaxReached();
    } else {

        this->_array.push_back(n);
    }
}

/* addNumber function improved */

void Span::improvedAddNumber(int n) {

    if (n < 0) {
        std::cout << "Please provide a positive number" << std::endl;
        return ;
    }

    int newSize = this->_array.size();
    
    srand(time(0));
    for (int i = this->_array.size(); i < n; i++) {

        if (newSize >= (int)this->_maxStock) {
            throw MaxReached();
            return ;
        }
        this->_array.push_back((rand() % 100) + 1);
        newSize += 1;
    }
}

/* exceptions */

const char* Span::MaxReached::what() const throw() {
    return ("Sorry but you've reached max capacity of storage");
}

const char* Span::NoDistanceCanbeFound::what() const throw() {
    return ("Sorry but no distance can be found");
}

/* shortest and longest span */

unsigned int Span::shortestSpan() {

    if (this->getSize() == 0 || this->getSize() == 1)
        throw NoDistanceCanbeFound();

    std::sort(this->_array.begin(), this->_array.end());
    
    unsigned int tmpMin = INT_MAX;
    unsigned int res;

    for (int i = 0; i + 1 < this->getSize(); i++) {

        res = this->_array[i + 1] - this->_array[i];
        if (res < tmpMin)
            tmpMin = res;
    } 
    return (tmpMin);
}

unsigned int Span::longestSpan() {

    if (this->getSize() == 0 || this->getSize() == 1)
        throw NoDistanceCanbeFound();

    unsigned int min;
    unsigned int max;

    min = *min_element(this->_array.begin(), this->_array.end());
    max = *max_element(this->_array.begin(), this->_array.end());

    unsigned res;

    res = max - min;
    return res;
}
