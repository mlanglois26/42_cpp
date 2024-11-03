/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:58:20 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/01 17:57:51 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstring>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"

int main( void ) {
    
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << GREEN << &str << " | " << stringPTR << " | " << &stringREF << std::endl;
    std::cout << str << " | " << *stringPTR << " | " << stringREF << RESET << std::endl;

    return (0);
}
