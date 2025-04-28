/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:32:06 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/29 11:53:06 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#pragma once

#include <iostream>
#include <stdlib.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m" 

template<typename T>
class Array {

    private:
        T*   _content;
        unsigned int _size;

    public:
        Array<T>() : _content(NULL), _size(0) { std::cout << GREEN << "Default Constructor called for Template Class Array" << RESET << std::endl; };

        Array<T>(unsigned int n) {

            this->_content = new T[n];
            this->_size = n;
            std::cout << GREEN << "Unsigned Int Constructor called for Template Class Array" << RESET << std::endl;
        }

        Array<T>( const Array<T>& copy ) {

            this->_content = new T[copy._size];
            this->_size = copy._size;

            for (unsigned int i = 0; i < this->_size; i++) {

                this->_content[i] = copy._content[i];
            }
            std::cout << GREEN << "Copy Constructor called for Template Class Array" << RESET << std::endl;
        };

        virtual ~Array<T>() { 

            delete[] this->_content;    
            std::cout << RED << "Destructor called for Template Class Array" << RESET << std::endl; 
        };
 
        /* surcharge */
        
        Array<T> operator=( const Array<T>& other ) {

            if (this != &other) {

                delete this->_content;
                this->_size = other._size;
                this->_content = new T[other._size];
                for (unsigned int i = 0; i < this->_size; i++) {

                this->_content[i] = other._content[i];
            }
            }
            std::cout << GREEN << "Operator Assignment called for Template Class" << RESET << std::endl;
            return (*this);
        };

        T &operator[](unsigned int i) {

            if (i >= this->_size) {
                
                throw Array<T>::OutOfBounds();
            }
            else {

                return (this->_content[i]);
            }
        }

        /* mandatory function  */

        unsigned int size() { return _size; };

        /* exception */

        class OutOfBounds : public std::exception {

            public:
                virtual const char *what() const throw() { return "Index is out of bounds"; };
        };
        
};

#endif
