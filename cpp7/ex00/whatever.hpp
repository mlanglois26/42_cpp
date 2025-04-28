/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:57:29 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/26 15:57:34 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>
void swap( T & x, T & y ) {

    T tmp;

    tmp = x;
    x = y;
    y = tmp;
}

template<typename T>
T const & max( T const & x, T const & y ) {

    if (x == y)
        return (y);
    else
        return ((x > y) ? x : y);
}

template<typename T>
T const & min( T const & x, T const & y ) {

    if (x == y)
        return (y);
    else
        return ((x < y) ? x : y);
}