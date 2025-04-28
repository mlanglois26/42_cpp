/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:56:41 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/28 10:36:17 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* Canonic Form */

ScalarConverter::ScalarConverter()
{
    std::cout << "Default constructor called for ScalarConvert class" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {

    *this = copy;
    std::cout << "Copy constructor called for ScalarConvert class" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {

    std::cout << "Operator Assignment called for ScalarConvert class" << std::endl;
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Destructor called for ScalarConvert class" << std::endl;
}

/* parse */

bool isAcceptableChar(const std::string& literal) {

    if (literal.empty())
        return (false);
    if (literal.length() != 1)
        return (false);
    if (!std::isdigit(literal[0]))
        return (true);
    return (false);
}

bool isAcceptableInt(const std::string& literal) {

    if (literal.empty())
        return (false);
    
    for (int i = 0; literal[i] != '\0'; i++) {

        if (std::isdigit(literal[i]) || literal[i] == '-' || literal[i] == '+') {

            if (literal[0] == '-' && literal[0] == '+')
                continue;
            if ((literal[i] == '-' || literal[i] == '+') && i != 0)
                return (false);        
        }
        else 
            return (false);
    }
    try {

        long long n = atol(literal.c_str());
        if (n >= INT_MIN && n <= INT_MAX)
            return (true);
    }
    catch (const std::out_of_range&) {

        return (false);
    }
    return (false);
}

bool isAcceptableFloat(const std::string& literal) {

    if (literal.empty())
        return (false);
    
    if (literal[literal.size() - 1] != 'f')
        return false;
    
    int count = 0;
    for (int i = 0; literal[i] != '\0'; i++) {
    
        if (std::isdigit(literal[i]) || literal[i] == '-' || literal[i] == '+' || literal[i] == '.' || literal[i] == 'f') {
             
            if (literal[0] == '-' && literal[0] == '+')
                continue;
            if ((literal[i] == '-' && i != 0) || (literal[i] == '+' && i != 0))
                return (false);
            if (literal[i] == '.') {
                
                count += 1;
            }
        }
        else
            return (false);
    }
    if (count != 1) {
        
        return (false);
    }
    try {

        float n = atof(literal.c_str());
        if (n >= -std::numeric_limits<float>::max() && n <= std::numeric_limits<float>::max())
            return (true);
    }
    catch (const std::out_of_range&) {

        return (false);
    }
    return (false);
}

bool isAcceptableDouble(const std::string& literal) {

    if (literal.empty())
        return (false);
    
    int count = 0;
    for (int i = 0; literal[i] != '\0'; i++) {
    
        if (std::isdigit(literal[i]) || literal[i] == '-' || literal[i] == '+' || literal[i] == '.') {
            
            if (literal[0] == '-' && literal[0] == '+')
                continue;
            if ((literal[i] == '-' || literal[i] == '+') && i != 0)
                return (false);
            if (literal[i] == '.')
                count += 1;
        }
        else 
            return (false);
    }
    if (count != 1)
        return (false);
    try {

        std::stringstream ss(literal);
        double d;
        ss >> d;
        if (d >= -std::numeric_limits<double>::max() && d <= std::numeric_limits<double>::max())
            return (true);
    }
    catch (const std::out_of_range&) {

        return (false);
    }
    return (true);
}

// printers

void convertFromChar(const std::string& literal) {

    char c = literal[0];
    
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f "<< std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void convertFromInt(const std::string& literal) {

    int n = atoi(literal.c_str());
    
    if (n > 32 && n < 127)
        std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << n << std::endl;
    std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
}

void convertFromFloat(const std::string& literal) {

    float f = atof(literal.c_str());
    
    if (f > 32 && f < 127)
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    
    std::cout << "int: " << static_cast<int>(f) << std::endl;

    if (literal[literal.size() - 2] == '0')
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    
    if (literal[literal.size() - 2] == '0')
        std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void convertFromDouble(const std::string& literal) {

    std::stringstream ss(literal);
    double d;
    ss >> d;

    if (d > 32 && d < 127)
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << static_cast<int>(d)  << std::endl;
    
    if (literal[literal.size() - 1] == '0')
        std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    
    if (literal[literal.size() - 1] == '0')
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

/* exceptions */

void neg_output() {

    std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: Non displayable" << std::endl;
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
}

void pos_output() {

    std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: Non displayable" << std::endl;
    std::cout << "float: +inff" << std::endl;
    std::cout << "double: +inf" << std::endl;
}

void other_output() {

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}

// convert function

void ScalarConverter::convert(const std::string& literal) {

    std::string exception[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
    
    if (literal == exception[0] || literal == exception[3]) {

        neg_output();
        return ;
    }
    if (literal == exception[1] || literal == exception[4]) {

        pos_output();
        return ;
    }
    
    if (literal == exception[2] || literal == exception[5]) {

        other_output();
        return ;
    }
    
    if (isAcceptableChar(literal)) {

        convertFromChar(literal);
    }
    else if (isAcceptableFloat(literal)) {

        convertFromFloat(literal);
    }
    else if (isAcceptableDouble(literal)) {
        
        convertFromDouble(literal);
    }
    else if (isAcceptableInt(literal)) {

        convertFromInt(literal);
    }
    else
        std::cout << "Invalid input" << std::endl;
}

// static cast: compile time type conversion and mainly used for explicit conversions that 
// are considered safe by the compiler