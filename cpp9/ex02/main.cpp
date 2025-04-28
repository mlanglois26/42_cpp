/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 08:42:55 by malanglo          #+#    #+#             */
/*   Updated: 2025/01/23 08:42:56 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {

    if (argc < 2 || argc > 3001) {
        std::cerr << "Please provide some input." << std::endl;
        return -1;
    }

    PmergeMe<std::vector<int> > vectorInstance;
    PmergeMe<std::deque<int> > dequeInstance;

    long vectorTime = vectorInstance.getTimeAndProcess(argc, argv);
    long dequeTime = dequeInstance.getTimeAndProcess(argc, argv);

    if (vectorTime == -1 || dequeTime == -1) {
      std::cerr << "Error: Invalid input" << std::endl;
      return -1;
    }
    vectorInstance.printMessage(vectorTime, dequeTime);
    return 0;
}
