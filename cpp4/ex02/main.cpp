/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:02:40 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 11:08:39 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {

    // AAnimal a;
    // AAnimal b(a);
    // AAnimal c;
    // c = b;

    Cat d;
    Cat e(d);
    Cat f;
    f = e;

    Dog g;
    Dog h(g);
    Dog i;
    i = h;

    f.makeSound();
    i.makeSound();
    
    return (0);
}
