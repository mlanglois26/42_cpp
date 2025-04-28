/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:42:00 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/28 09:43:37 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {

    if (argc == 2) {
        
        ScalarConverter::convert(argv[1]);
    }
    else {
        
        std::cout << "Usage: ./ex00 [arg]" << std::endl;
    }
    return (0);
}