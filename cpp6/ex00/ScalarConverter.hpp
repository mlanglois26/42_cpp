/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:56:49 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/26 14:48:28 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#pragma once

#include <iostream>
#include <string>
#include <climits>
#include <sstream>
#include <cstdlib>
#include<bits/stdc++.h> 

class ScalarConverter
{
    public:
        ~ScalarConverter();
        static void convert( const std::string& literal );

    private:
        ScalarConverter();
        ScalarConverter( const ScalarConverter& copy );
        ScalarConverter& operator=( const ScalarConverter& other );
};

#endif
