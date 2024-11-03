/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:01:36 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/03 18:03:21 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){};

Harl::~Harl(){};

void Harl::_debug( void ) {

    std::cout << GREEN << "[ DEBUG ] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << RESET << std::endl;
}

void Harl::_info( void ) {

    std::cout << BLUE << "[ INFO ] I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << RESET << std::endl;
}

void Harl::_warning( void ) {

    std::cout << YELLOW << "[ WARNING ] I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << RESET << std::endl;
}

void Harl::_error( void ) {
    
    std::cout << RED << "[ ERROR ] This is unacceptable ! I want to speak to the manager now." << RESET << std::endl;
}

void Harl::_default( void ) {
    
    std::cout << "[ DEFAULT ] Probably complaining about insignificant problems." << std::endl;
}

int Harl::assignCode(std::string level ) {

    int code = 0;
    std::string assignLevels[4] { "DEBUG", "INFO", "WARNING", "ERROR" };
    
    for (int i = 0; i < 4; i++) {
        
        if (assignLevels[i] == level) {
            code = i + 1;
        return (code);
        }
    }
    code = 5;
    return (code);
}

void Harl::complainFilter(std::string level) {
    
    void (Harl::*ptr[4])() = { &Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error };
    int code = assignCode(level);
    
    switch (code)
    {
        case 1:
        {
            (this->*ptr[0])();
            (this->*ptr[1])();
            (this->*ptr[2])();
            (this->*ptr[3])();
            break ;
        }
        case 2:
        {
            (this->*ptr[1])();
            (this->*ptr[2])();
            (this->*ptr[3])();
            break ;  
        }
        case 3:
        {
            (this->*ptr[2])();
            (this->*ptr[3])();
            break ;
        }
        case 4:
            (this->*ptr[3])();
            break ;
        case 5:
            this->_default();
    }
}