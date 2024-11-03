/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:02:13 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/03 12:51:47 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
    
    Harl instance;

    if (argc == 2) {
        
        instance.complainFilter(argv[1]);
    }
    else {
        
        std::cout << "Usage: ./HarlFilter level" << std::endl;
    }

    return (0);
}

