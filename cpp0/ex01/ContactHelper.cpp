/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactHelper.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:11:21 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/01 11:46:56 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int Contact::_blankCheck(std::string str) {
    
    if (str.empty())
        return (1);
    for (int i = 0; str[i] != 0; i++) {
        
        if (std::isalpha(str[i]))
            return (0);
    }
    return (1);
}

void Contact::_inputSecure(std::string &input) {
    
    while (1)
    {
        if (std::cin.eof())
            exit (0);
        if (Contact::_blankCheck(input) == 1) {
            
            std::cout << "Input must contain an alphabetic character." << std::endl;
            std::getline(std::cin, input);
        }
        else
            break ;
    }
}

int Contact::_alnumCheck(std::string str) {
    
    if (str.empty())
        return (1);
    for (int i = 0; str[i] != 0; i++) {
        
        if (std::isalnum(str[i]))
            return (0);
    }
    return (1);
}

void Contact::_inputSecureAlnum(std::string &input) {
    
    while (1) {
        
        if (std::cin.eof())
            exit (0);
        if (Contact::_alnumCheck(input) == 1) {
            
            std::cout << "Input must contain an alphanumeric character." << std::endl;
            std::getline(std::cin, input);
        }
        else
            break ;
    }
}

std::string	Contact::_resizing(std::string str) {
    
	if (str.size() > 10) {
        
		str.resize(10);
		str[9] = '.';
	}
	return (str);
}
