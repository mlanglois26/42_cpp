/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:02:36 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 13:55:05 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {

    _name = "Default";
    _size = 0;
    for (int i = 0; i < 4; i++) {

        _array[i] = NULL;
    }
    std::cout << GREEN << "Default Constructor called for Character" << RESET <<std::endl;
    return ;
}

Character::Character(const Character& copy) {

    this->_name = copy._name;
    this->_size = copy._size;
    for (int i = 0; i < 4; i++) {

        if (copy._array[i])
            this->_array[i] = copy._array[i]->clone();
        else
            this->_array[i] = NULL;
    }
    std::cout << GREEN << "Copy Constructor called for Character" << RESET <<std::endl;
    return ;
}

Character& Character::operator=(const Character& other) {

    std::cout << GREEN << "Operator Assignment called for Character" << RESET <<std::endl;
    if (this != &other) {

        this->_name = other._name;
        this->_size = other._size;
        
        for (int i = 0; i < 4; i++) {

            if (other._array[i])
                this->_array[i] = other._array[i]->clone();
            else
                this->_array[i] = NULL;
    }
    }
    return (*this);
}

Character::~Character() {
    
    for (int i = 0; i < 4; i++) {

        if (_array[i])
            delete _array[i];
    }
    std::cout << RED << "Destructor called for Character" << RESET <<std::endl;
    return ;
}

/* Name Constructor */

Character::Character(std::string const & name) : _name(name), _size(0) {

    for (int i = 0; i < 4; i++) {

        _array[i] = NULL;
    }
    std::cout << GREEN << "Name Constructor called for Character" << RESET <<std::endl;
    return ;
}

/* functions */

void Character::use(int idx, ICharacter& target) {

    if (idx >= 0 && idx < this->_size && _array[idx] != NULL)
        this->_array[idx]->use(target);
    else
        std::cout << "Sorry but nothing can be done, check that you have a Materia on the right index" << std::endl;
}

void Character::equip(AMateria *m)
{

    if (this->_size < 4)
		this->_array[this->_size++] = m;
	else {

		std::cout << "Your stash of materia is full, " << m->getType() << " cannot be added" << std::endl;
    }
}

void Character::unequip(int idx) {

    if (idx > 3 || idx < 0 || !_array[idx])
        return ;
    this->_array[idx] = NULL;
    this->_size--;
}

std::string const & Character::getName() const {

    return (this->_name);
}