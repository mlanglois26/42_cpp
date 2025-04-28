/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 08:43:19 by malanglo          #+#    #+#             */
/*   Updated: 2025/01/23 08:43:20 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* Constructeurs - Destructeur */

template <typename Container>
PmergeMe<Container>::PmergeMe(std::string input) {
    std::istringstream iss(input);
    int value;

    while (iss >> value) {
        data.push_back(value);
    }
}

template <typename Container>
PmergeMe<Container>::PmergeMe() {
    pend.clear();
    main.clear();
};

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& copy) {
    this->data = copy.data;
    this->original_data = copy.original_data;
    this->aLabels = copy.aLabels;
    this->bLabels = copy.bLabels;
    this->rest = copy.rest;
    this->main = copy.main;
    this->pend = copy.pend;
};

template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe& other) {
    if (this != &other) {
        this->data = other.data;
        this->original_data = other.original_data;
        this->aLabels = other.aLabels;
        this->bLabels = other.bLabels;
        this->rest = other.rest;
        this->main = other.main;
        this->pend = other.pend;
    }
    return (*this);
}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {};

/* Parsing */

int parseInput(std::string input) {

    if (input.empty()) {
        std::cout << "Error, empty input" << std::endl;
    }
    for (int i = 0; input[i] != '\0'; i++) {
        if (std::isdigit(input[i]) == 0 && std::isspace(input[i]) == 0) {
            return (1);
        }
    }

    long long value = std::atoll(input.c_str());
    if (value > std::numeric_limits<int>::max()) {
        return (1);
    }

    return (0);
}

/* Helpers */

template <typename Container>
void PmergeMe<Container>::printData() const {
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
void PmergeMe<Container>::printMessage(long finalVectorTime, long finalDequeTime) {
    std::cout << "Before: ";
    printOriginalData();
    std::cout << "After: ";
    printData();
    std::cout << "Time to process a range of " << getDataSize() << " elements with std::vector " << std::fixed << std::setprecision(6) << (finalVectorTime / 1000.0) << " ms." << std::endl;
    std::cout << "Time to process a range of " << getDataSize() << " elements with std::deque " << std::fixed << std::setprecision(6) << (finalDequeTime / 1000.0)  << " ms." << std::endl;
}

template <typename Container>
void PmergeMe<Container>::addData(std::string input) {
    std::istringstream iss(input);
    int value;
    while (iss >> value) {
        data.push_back(value);
    }
    original_data = data;
}

template <typename Container>
void PmergeMe<Container>::printOriginalData() const {
  for (size_t i = 0; i < original_data.size(); ++i) {
        std::cout << original_data[i] << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
int PmergeMe<Container>::getDataSize() const {
    return this->data.size();
}

long getTimeInMicro() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}

template <typename Container>
long PmergeMe<Container>::getTimeAndProcess(int argc, char **argv) {

    long beginHandleData = getTimeInMicro();
    for (int i = 1; i < argc; i++) {
      if (parseInput(argv[i]) == 0) {
          addData(argv[i]);
      } else
          return -1;
    }
    long endHandleData = getTimeInMicro();
    long first = (long)(endHandleData - beginHandleData);

    long beginSort = getTimeInMicro();
    groupAndSort(1);
    long endSort = getTimeInMicro();

    long second = (long)(endSort - beginSort);
    long finalVectorTime = first + second;

    return (finalVectorTime);
}

/* Algo - Part 1 */

template <typename Container>
void PmergeMe<Container>::groupAndSort(int groupSize) {

    if (recursionStop(groupSize) == 1)
        return ;

    for (int i = 0; i < getDataSize(); i += groupSize) {

        int end = std::min(i + groupSize, getDataSize());

        Container group(data.begin() + i, data.begin() + end);

        if (group.size() >= 2) {

            compareMidAndLast(group);

            for (int j = 0; j < (int)group.size(); ++j) {
                data[i + j] = group[j];
            }
        }
    }

    if (groupSize == 1)
        groupSize += 1;
    else
        groupSize *= 2;
    groupAndSort(groupSize);
}

template <typename Container>
int PmergeMe<Container>::recursionStop(int groupSize) {

    if (groupSize > getDataSize()) {
        groupSize /= 2;

        while (groupSize >= 1) {

            if (groupSize > getDataSize()) {
                groupSize /= 2;
            }
            else {
                while (groupSize >= 1) {

                    labelGroupsForMerge(groupSize);
                    groupSize /= 2;
                }
                return (1);
            }
        }
        return (1);
    }
    return (0);
}

template <typename Container>
void PmergeMe<Container>::compareMidAndLast(Container& group) {
    int mid = (group.size() / 2) - 1;
    int last = group.size() - 1;

    if (group[mid] > group[last]) {
        for (int i = 0; i <= mid; i++) {
            std::swap(group[i], group[mid + i + 1]);
        }
    }
}

/* Algo - Part 2 */

template <typename Container>
void PmergeMe<Container>::labelGroupsForMerge(int groupSize) {

    if (groupSize <= 1)
        return ;

    clearAllContainers();
    int bLabel = 1, aLabel = 1;
    Container remainder;

    for (size_t i = 0; i < data.size(); i += groupSize) {

        int end = std::min((int)i + groupSize, (int)data.size());
        Container group(data.begin() + i, data.begin() + end);

        if ((int)(data.size() - i) < groupSize) {
            remainder.assign(data.begin() + i, data.end());
            break;
        }

        labelGroups(group, bLabel, aLabel);
        bLabel++;
        aLabel++;
    }

    if (!remainder.empty()) {
        while ((int)remainder.size() >= groupSize / 2) {
            Container newBGroup(remainder.begin(), remainder.begin() + groupSize / 2);
            remainder.erase(remainder.begin(), remainder.begin() + groupSize / 2);
            bLabels.push_back(newBGroup);
            bLabel++;
        }
    }

    if (!remainder.empty()) {
        for (int i = 0; i < (int)remainder.size(); ++i) {
            rest.push_back(remainder[i]);
        }
    }

    if (!bLabels.empty()) {
        main.push_back(bLabels[0]);
    }

    for (size_t i = 0; i < aLabels.size(); ++i) {
        main.push_back(aLabels[i]);
    }

    for (size_t i = 1; i < bLabels.size(); ++i) {
        pend.push_back(bLabels[i]);
    }

    mergePendIntoMain();
}

template <typename Container>
void PmergeMe<Container>::clearAllContainers() {
    main.clear();
    pend.clear();
    aLabels.clear();
    bLabels.clear();
    rest.clear();
}

template <typename Container>
void PmergeMe<Container>::labelGroups(Container& group, int bLabel, int aLabel) {

    if (group.size() <= 1) {
        return;
    }

    if ((int)bLabels.size() < bLabel)
        bLabels.resize(bLabel);
    if ((int)aLabels.size() < aLabel)
        aLabels.resize(aLabel);

    if (group.size() == 2) {
        bLabels[bLabel - 1].push_back(group[0]);
        aLabels[aLabel - 1].push_back(group[1]);
    } else {

        int mid = (group.size() / 2) - 1;
        Container beforeMid(group.begin(), group.begin() + mid + 1);
        Container afterMid(group.begin() + mid + 1, group.end());

        for (int i = 0; i < (int)beforeMid.size(); i++) {
            bLabels[bLabel - 1].push_back(beforeMid[i]);
        }

        for (int i = 0; i < (int)afterMid.size(); i++) {
            aLabels[aLabel - 1].push_back(afterMid[i]);
        }
    }
}

template <typename Container>
void PmergeMe<Container>::mergeWithoutJacobsthal() {
    for (size_t i = 0; i < pend.size(); ++i) {
        bool inserted = false;

        for (size_t j = 0; j < main.size(); ++j) {

            if (pend[i].back() > main[j].back())
                continue ;
            else
            {
                main.insert(main.begin() + j, pend[i]);
                inserted = true;
                break;
            }
        }

        if (!inserted) {
            main.push_back(pend[i]);
        }
    }
}

template <typename Container>
void PmergeMe<Container>::mergeWithJacobsthal() {
    Container jacobsthalIdx;
    int n = 0;
    while (true) {
        int idx = jacobsthal(n++);
        if (idx >= (int)pend.size())
            break;
        jacobsthalIdx.push_back(idx);
    }

    std::vector<bool> inserted(pend.size(), false);

    for (size_t i = 1; i < jacobsthalIdx.size(); ++i) {
        int start = jacobsthalIdx[i - 1];
        int end = std::min(jacobsthalIdx[i], (int)pend.size());

        for (int j = end - 1; j >= start; --j) {
            if (inserted[j]) continue;

            bool insertedElement = false;
            for (size_t k = 0; k < main.size(); ++k) {
                if (pend[j].back() > main[k].back())
                    continue;
                else {
                    main.insert(main.begin() + k, pend[j]);
                    inserted[j] = true;
                    insertedElement = true;
                    break;
                }
            }

            if (!insertedElement) {
                main.push_back(pend[j]);
                inserted[j] = true;
            }
        }
    }

    for (size_t i = 0; i < pend.size(); ++i) {
        if (inserted[i]) continue;

        bool insertedElement = false;
        for (size_t j = 0; j < main.size(); ++j) {
            if (pend[i].back() > main[j].back())
                continue;
            else {
                main.insert(main.begin() + j, pend[i]);
                insertedElement = true;
                break;
            }
        }

        if (!insertedElement) {
            main.push_back(pend[i]);
        }
    }
}

template <typename Container>
void PmergeMe<Container>::mergePendIntoMain() {

    if (pend.size() <= 3) {
        mergeWithoutJacobsthal();
    }
    else {
        mergeWithJacobsthal();
    }

    data.clear();

    for (size_t i = 0; i < main.size(); ++i) {
        data.insert(data.end(), main[i].begin(), main[i].end());
    }
    if (!rest.empty())
        data.insert(data.end(), rest.begin(), rest.end());
}

int jacobsthal(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

template <typename Container>
void PmergeMe<Container>::jacobsthalIndices() {

    Container jacobsthalIdx;

    int i = 0;

    while (i < (int)pend.size()) {
        jacobsthalIdx.push_back(jacobsthal(i));
        i++;
    }

    for (size_t i = 0; i < jacobsthalIdx.size(); i++) {
    }
}
