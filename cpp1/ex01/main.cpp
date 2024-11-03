/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:54:26 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/03 12:32:19 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
    int N = 10;
    std::string name = "Joe";

    Zombie* zombies = zombieHorde(N, name);

    for (int i = 0; i < N; i++) {
        
        std::cout << BLUE << i + 1 << RESET;
        zombies[i].annonce();
    }

    delete [] zombies;

    return (0);
}