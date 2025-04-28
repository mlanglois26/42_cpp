/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:13:12 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 13:28:53 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    
    this->_nb = 0;
    for (int i = 0; i < 4; i++) {
        
        this->_materias[i] = NULL;
    }
    std::cout << GREEN << "Default Constructor called for MateriaSource" << RESET << std::endl;
    return ;
}

MateriaSource::MateriaSource(const MateriaSource& copy) {
    
    this->_nb = copy._nb;
    for (int i = 0; i < 4; i++) {
        
        if (copy._materias[i])
            this->_materias[i] = copy._materias[i]->clone();
        else
            this->_materias[i] = NULL;
    }
    std::cout << GREEN << "Copy Constructor called for MateriaSource" << RESET << std::endl;
    return ;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    
    std::cout << GREEN << "Operator Assignment called for MateriaSource" << RESET << std::endl;
    
    if (this != &other) {
        
        for (int i = 0; i < 4; i++) {
        
            delete this->_materias[i];
        }
        
        this->_nb = other._nb;
        for (int i = 0; i < 4; i++) {
        
            if (other._materias[i])
                this->_materias[i] = other._materias[i]->clone();
            else
                this->_materias[i] = NULL;
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource() {

    for (int i = 0; i < this->_nb; i++) {

        delete this->_materias[i];
    }
    std::cout << RED << "Destructor called for MateriaSource" << RESET << std::endl;
    return ;
}

/* functions */

void MateriaSource::learnMateria(AMateria *materia) {
    
    if (this->_nb >= 4) {
        
        std::cout << "Sorry, you cannot learn more than 4 Materia" << std::endl;
        delete materia;
    }
    else {

        this->_materias[_nb] = materia;
        this->_nb++;
        std::cout << "Learning new materia: " << materia->getType() << std::endl;
    }
}

AMateria* MateriaSource::createMateria(const std::string& type) {
    
    for (int i = 0; i < 4; i++) {

        if (this->_materias[i] && type == this->_materias[i]->getType()) {

            std::cout << "Creating materia: " << _materias[i]->getType() << std::endl;
            return (this->_materias[i]->clone());
        }
    }
    return (NULL);
}
