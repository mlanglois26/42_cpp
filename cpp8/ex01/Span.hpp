/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:17:42 by malanglo          #+#    #+#             */
/*   Updated: 2024/12/11 13:17:43 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <cctype>
#include <cstring>
#include <bits/stdc++.h>
#include <exception>
#include <ctime>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

class Span 
{
    public:
        Span(unsigned int maxStock);
        Span();
        Span( const Span& copy );
        Span& operator=( const Span& other );
        ~Span();

        void addNumber( int n );
        void improvedAddNumber( int n );
 
        void printNums();
        int getSize();

        unsigned int shortestSpan();
        unsigned int longestSpan();

        class MaxReached : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class NoDistanceCanbeFound : public std::exception {
            public:
                virtual const char *what() const throw();
        };

    private:
        unsigned int _maxStock;
        std::vector<int> _array;
};


#endif