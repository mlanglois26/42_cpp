/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:39:20 by malanglo          #+#    #+#             */
/*   Updated: 2025/01/17 12:39:22 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
    }
    else {
        BitcoinExchange btc;

        btc.loadDatabase("data.csv");
        btc.loadInputFile(argv[1]);
        btc.compareBothFiles();
    }
    return (0);
}