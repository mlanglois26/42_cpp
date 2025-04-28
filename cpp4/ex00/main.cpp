/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:02:40 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 09:39:44 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    const WrongAnimal* a = new WrongAnimal();
    const WrongAnimal* b = new WrongCat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl; 
    std::cout << b->getType() << " " << std::endl;
    
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    b->makeSound();
    a->makeSound();
    

    delete meta;
    delete a;
    delete j;
    delete i;
    delete b;

    return 0;
}

// int main() {

//     Animal a;
//     Animal b(a);
//     Animal c;
//     c = b;

//     Cat d;
//     Cat e(d);
//     Cat f;
//     f = e;

//     Dog g;
//     Dog h(g);
//     Dog i;
//     i = h;
    
//     std::cout << c.getType() << std::endl;
//     std::cout << f.getType() << std::endl;
//     std::cout << i.getType() << std::endl;

//     c.makeSound();
//     f.makeSound();
//     i.makeSound();
    
//     return (0);
// }