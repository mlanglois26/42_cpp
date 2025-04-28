/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:34:31 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/29 12:51:25 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void print(T& c){

    std::cout << c << std::endl;
}

template<typename T>
void add_five(T& c){

    std::cout << c + 10 << std::endl;
}

int main() {

    int arrayInt[5] = {1, 2, 3, 4, 5};
    
    ::iter(arrayInt, 5, &print<int>);
    
    std::cout << "\n";

    ::iter(arrayInt, 5, &add_five<int>);
    
    std::cout << "\n";

    float arrayFloat[5] = {1.15f, 2.0f, 3.3f, 4.1f, 5.36f};

    ::iter(arrayFloat, 5, &print<float>);

    std::cout << "\n";

    char arrayChar[5] = {'a', 'b', 'c', 'd', 'e'};
    
    ::iter(arrayChar, 5, &print<char>);

    std::string arrayString[5] = {"hello", "hola", "bonjour", "ciao", "hallo"};

    std::cout << "\n";
    
    ::iter(arrayString, 5, &print<std::string>);

    return (0);
}
