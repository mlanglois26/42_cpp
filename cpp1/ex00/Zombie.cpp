/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:54:09 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/03 12:17:04 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
    
    std::cout << GREEN << "Constructeur called" << RESET << std::endl;
    return ;
}

Zombie::~Zombie() {
    
    std::cout << RED << "Destructeur called on an instance of the Zombie class that has the private attribute _name having for value " << this->getName() << RESET << std::endl;
    return ;
}

std::string Zombie::getName() const {
    
    return (this->_name);
}

void Zombie::annonce( void ) {
    
    std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl; 
}

Zombie* newZombie( std::string name ) {
    
    Zombie* zombiePtr = new Zombie(name);

    return (zombiePtr);
}

void randomChump( std::string name ) {
    
    Zombie stackZombie(name);
    
    stackZombie.annonce();
}

Zombie* randomChumpHeap( std::string name ) {
    
    Zombie* heapZombie = newZombie(name);
    
    std::cout << YELLOW << "Heap example for randomChump function: ";
    heapZombie->annonce();
    std::cout << RESET; 
    return (heapZombie);
}
