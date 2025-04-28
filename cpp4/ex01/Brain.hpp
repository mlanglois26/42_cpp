/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:20:05 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 09:55:22 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#pragma once

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m" 

#include <iostream>

class Brain
{
    public:
        Brain();
        Brain( const Brain& copy );
        Brain& operator=( const Brain& other);
        ~Brain();

        void setIdeas( const std::string& idea, int index );
        std::string getIdeas( int index ) const;
        void printIdeas() const;
        Brain* clone() const;

    private:
        std::string _ideas[100];
};

#endif
