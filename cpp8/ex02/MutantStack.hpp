/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:30:05 by malanglo          #+#    #+#             */
/*   Updated: 2025/01/13 12:30:06 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <cctype>
#include <cstring>
#include <bits/stdc++.h>
#include <exception>
#include <ctime>
#include <stack>
#include <deque>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

template <typename T, class Container=std::deque<T> >
class MutantStack : public std::stack<T, Container> {

    public:

        MutantStack() : std::stack<T, Container>() {};
        ~MutantStack() {};
        MutantStack(const MutantStack& copy) : std::stack<T, Container>(copy) {};
        MutantStack& operator=(const MutantStack& other) {
            if (this != &other) {
                std::stack<T, Container>::operator=(other);
            }
            return (*this);
        };

        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;
        typedef typename Container::reverse_iterator reverse_iterator;
        typedef typename Container::const_reverse_iterator const_reverse_iterator;
        
        iterator begin() {
            return this->c.begin();
        }
        iterator end() {
            return this->c.end();
        }

        const_iterator begin() const {
            return this->c.begin();
        }
        const_iterator end() const {
            return this->c.end();
        }

        reverse_iterator rbegin() {
            return this->c.rbegin();
        }
        reverse_iterator rend() {
            return this->c.rend();
        }

        const_reverse_iterator rbegin() const {
            return this->c.rbegin();
        }
        const_reverse_iterator rend() const {
            return this->c.rend();
        }
};

#endif