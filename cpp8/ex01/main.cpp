/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:17:19 by malanglo          #+#    #+#             */
/*   Updated: 2024/12/11 13:17:21 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {

    {
        Span a;
        Span b(a);
        
        Span c;
        c = a;
        
        std::cout << "a.size() = " << a.getSize() << std::endl;
        a.printNums();
    }

    std::cout << std::endl;
    
    {
        Span mySpan(4);
        std::cout << "mySpan.size() = " << mySpan.getSize() << std::endl;
        mySpan.printNums();
    
        try {
            mySpan.addNumber(12);
        }
        catch (std::exception& e) {
            std::cout << YELLOW << "Execption: " << e.what() << RESET << std::endl;
        }
        std::cout << "mySpan.size() = " << mySpan.getSize() << std::endl;
        mySpan.printNums();

        try {
            mySpan.addNumber(-7);
            mySpan.addNumber(0);
            mySpan.addNumber(14);
        }
        catch (std::exception& e) {
            std::cout << YELLOW << "Execption: " << e.what() << RESET << std::endl;
        }
        std::cout << "mySpan.size() = " << mySpan.getSize() << std::endl;
        mySpan.printNums();

        try {
            mySpan.addNumber(58);
        }
        catch (std::exception& e) {
            std::cout << YELLOW << "Execption: " << e.what() << RESET << std::endl;
        }
        std::cout << "mySpan.size() = " << mySpan.getSize() << std::endl;
        mySpan.printNums();
    }

    std::cout << std::endl;

    {
        Span mySpan(16);
        std::cout << "mySpan.size() = " << mySpan.getSize() << std::endl;
        mySpan.printNums();
        try {
            mySpan.improvedAddNumber(16);
        }
        catch (std::exception& e) {
            std::cout << YELLOW << "Execption: " << e.what() << RESET << std::endl;
        }
        mySpan.printNums();
        try {
            std::cout << mySpan.shortestSpan() << std::endl;
        }
        catch (std::exception& e) {
            std::cout << YELLOW << "Execption: " << e.what() << RESET << std::endl;
        }
        try {
            std::cout << mySpan.longestSpan() << std::endl;
        }
        catch (std::exception& e) {
            std::cout << YELLOW << "Execption: " << e.what() << RESET << std::endl;
        }
    }

    std::cout << std::endl;

    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        sp.printNums();
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    return 0;
}
