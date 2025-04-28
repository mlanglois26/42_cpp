/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:35:59 by malanglo          #+#    #+#             */
/*   Updated: 2024/12/02 14:05:22 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T, typename U>
void iter(T* array, int size, void(*ft)(U & c)) {
    
    for (int i = 0; i < size; i++) {

        ft(array[i]);
    }
}
