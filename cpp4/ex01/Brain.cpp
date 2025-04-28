/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:19:58 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 09:55:10 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {

    for (int i = 0; i < 100; i++) {
        setIdeas("Default Idea", i);
    }
    std::cout << GREEN << "Constructor called for Brain" << RESET << std::endl;
    return ;
};

Brain::Brain(const Brain& copy) {
    
    *this = copy;
    std::cout << GREEN << "Copy Constructor called for Brain" << RESET << std::endl;
    return;
}

Brain& Brain::operator=(const Brain& other) {

    std::cout << GREEN << "Assignment Operator called for Brain" << RESET << std::endl;

    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            _ideas[i] = other._ideas[i];
        }
    }
    return (*this);
}

Brain::~Brain() {

    std::cout << RED << "Destructor called for Brain" << RESET << std::endl;
    return ;
};


void Brain::setIdeas(const std::string& idea, int index) {
    if (index >= 0 && index < 100) {
        this->_ideas[index] = idea; 
    }
}

std::string Brain::getIdeas(int index) const {
    if (index >= 0 && index < 100) {  
        return this->_ideas[index];
    }
    return "";
}

void Brain::printIdeas() const {
    for (int i = 0; i < 100; i++) {
        std::cout << "Idea " << i << ": " << _ideas[i] << std::endl;
    }
}

Brain* Brain::clone() const {

    std::cout << "Clone for Brain called" << std::endl;
    return (new Brain(*this));
}
