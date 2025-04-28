/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:20:33 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/29 12:32:36 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {

    {
        std::cout << YELLOW << "Creating empty array, i.e calling default constructor" << RESET << std::endl;
        
        Array<int> intArray;
        Array<std::string> stringArray;
    }

    std::cout << std::endl;

    {
        std::cout << YELLOW << "Required test" << RESET << std::endl;

        int* a = new int();

        std::cout << *a << std::endl;

        delete a;
    }
    

    std::cout << std::endl;

    {
        std::cout << YELLOW << "Check on Constructor that takes an unisgned int parameter" << RESET << std::endl;

        Array<int> intArray(4);
        std::cout << intArray.size() << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << YELLOW << "Check canonic Form with Int" << RESET << std::endl;

        Array<int> intArray(11);
        Array<int> intArrayCopy(intArray); 

        std::cout << intArray.size() << std::endl;
        std::cout << intArrayCopy.size() << std::endl;

        Array<int> other;

        other = intArray;
        std::cout << other.size() << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << YELLOW << "Check canonic Form with Strings" << RESET << std::endl;

        Array<std::string> stringArray;
        Array<std::string> anotherStringArray(9);
        Array<std::string> stringArrayCopy(anotherStringArray); 

        std::cout << stringArray.size() << std::endl;
        std::cout << anotherStringArray.size() << std::endl;
        std::cout << stringArrayCopy.size() << std::endl;

        Array<std::string> other;

        other = stringArray;
        std::cout << other.size() << std::endl;
    }
    
    std::cout << std::endl;

    {
        std::cout << YELLOW << "Accessing INT elements" << RESET << std::endl;
        
        Array<int> test(10);

        std::cout << "Init array with the 10 digits" << std::endl;

        for (int i = 0; i < 10; i++) {

            test[i] = i;
            std::cout << test[i] << std::endl;
        }

        Array<int> test2(10);

        std::cout << "Init array with the 11 digits" << std::endl;

        try {
            
            for (int i = 0; i < 15; i++) {

                test[i] = i;
                std::cout << test[i] << std::endl;
            }
        }
        catch (const Array<int>::OutOfBounds& e) {

            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    std::cout << std::endl;

    {
        std::cout << YELLOW << "Accessing STRING elements" << RESET << std::endl;
        
        Array<std::string> test(4);

        std::cout << "Init array with 4 strings" << std::endl;

        for (int i = 0; i < 4; i++) {

            if (i == 0)
                test[i] = "coucou";
            else if (i == 1)
                test[i] = "hey";
            else if (i == 2)
                test[i] = "hola";
            else if (i == 3)
                test[i] = "hallo";
            std::cout << test[i] << std::endl;
        }

        Array<std::string> test2(4);

        std::cout << "Init array with the 5 strings" << std::endl;

        try {
            
            for (int i = 0; i < 5; i++) {

                if (i == 0)
                    test[i] = "coucou";
                else if (i == 1)
                    test[i] = "hey";
                else if (i == 2)
                    test[i] = "hola";
                else if (i == 3)
                    test[i] = "hallo";
                else
                    test[i] = "default";
                std::cout << test[i] << std::endl;
            }
        }
        catch (const Array<std::string>::OutOfBounds& e) {

            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    return (0);
}