/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:13:17 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 12:22:56 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#pragma once

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m" 

// je peux apprendre au max 4 materia
// lorsque j en create une je fais une deep copy avec un clone d une materia que materiasource connait deja

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource();
        MateriaSource( const MateriaSource& copy);
        MateriaSource& operator=( const MateriaSource& other );
        ~MateriaSource();

        virtual void learnMateria(AMateria* materia);
        virtual AMateria* createMateria(const std::string& type);

    private:
        AMateria *_materias[4];
        int _nb;
};

#endif
