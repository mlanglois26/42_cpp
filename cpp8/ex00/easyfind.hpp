/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:37:24 by malanglo          #+#    #+#             */
/*   Updated: 2024/12/11 13:06:46 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
void easyfind(T& data, int n) {

    typename T::iterator it = std::find(data.begin(), data.end(), n);

    if (it != data.end()) {
        
        std::cout << "Target " << n << " found at position " << std::distance(data.begin(), it) << std::endl;
    }
    else
        std::cout << "Target " << n << " not found" << std::endl;
}
