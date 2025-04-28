/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 08:43:10 by malanglo          #+#    #+#             */
/*   Updated: 2025/01/23 08:43:11 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <time.h>
#include <deque>
#include <limits>
#include <sys/time.h>
#include <iomanip>

template <typename Container>
class PmergeMe {

    private:
        Container data;
        Container original_data;

        std::vector<Container > aLabels;
        std::vector<Container > bLabels;
        std::vector<int> rest;
        std::vector<Container > main;
        std::vector<Container > pend;

    public:
        PmergeMe();
        PmergeMe(std::string input);
        PmergeMe(const PmergeMe& copy);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void printData() const;
        void printOriginalData() const;
        void addData(std::string input);
        int getDataSize() const;
        void printMessage(long finalVectorTime, long finalDequeTime);
        long getTimeAndProcess(int argc, char **argv);

        /* algo */

        void groupAndSort(int groupSize);
        int recursionStop(int groupSize);
        void compareMidAndLast(Container& group);
        void labelGroups(Container& group, int bLabel, int aLabel);
        void mergePendIntoMain();
        void labelGroupsForMerge(int groupSize);
        void clearAllContainers();
        void jacobsthalIndices();
        void mergeWithJacobsthal();
        void mergeWithoutJacobsthal();
};

int parseInput(std::string input);
int jacobsthal(int n);

#include "PmergeMe.cpp"

#endif
