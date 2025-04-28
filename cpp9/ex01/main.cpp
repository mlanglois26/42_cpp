/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:04:41 by malanglo          #+#    #+#             */
/*   Updated: 2025/01/17 17:04:42 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// peut etre probleme: doit rendre des floats?

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Please provide a string as entry" << std::endl;
    }
    else {

        if (acceptableChar(argv[1]) == 1 || acceptableDigit(argv[1]) == 1)
            return (-1);
        else {

            RPN a;

            a.fillStack(argv[1]);
            int result = a.calculate();
            if (result != -1) {
                std::cout << "Result: " << result << std::endl;
            }
        }
    }
    return (0);
}
