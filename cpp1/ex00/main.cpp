/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:54:26 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/03 12:19:35 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
    Zombie instanceA("Marc");
    Zombie* instanceB = newZombie("Jim");

    instanceA.annonce();
    instanceB->annonce();
    randomChump("Denis");
    
    Zombie* instanceD = randomChumpHeap("Georges");
    
    delete instanceD;
    delete instanceB;
 
    return (0);
}