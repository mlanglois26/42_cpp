/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:36:56 by malanglo          #+#    #+#             */
/*   Updated: 2024/12/11 13:09:26 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void) {

    {
        std::vector<int> array;

        array.push_back(1);
        array.push_back(2);
        array.push_back(3);
        array.push_back(4);
        array.push_back(5);

        int target = 5;

        easyfind(array, target);
    }

    {
        std::vector<int> array;
        
        array.push_back(1);
        array.push_back(2);
        array.push_back(3);
        array.push_back(4);
        array.push_back(0);
        array.push_back(2);

        int target = 5;

        easyfind(array, target);
    }

    {
        std::vector<int> array;
        
        array.push_back(1);
        array.push_back(2);
        array.push_back(3);
        array.push_back(4);
        array.push_back(0);
        array.push_back(2);

        int target = 2;

        easyfind(array, target);
    }

    return (0);
}
