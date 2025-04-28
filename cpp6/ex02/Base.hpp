/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:42:33 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/28 10:35:09 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
#define BASE_H

#pragma once

#include <iostream>
#include <cstdlib>
#include <unistd.h>

class Base
{
    public:
        virtual ~Base();
};

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif
