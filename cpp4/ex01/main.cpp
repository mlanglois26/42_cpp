/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:55:29 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/17 11:14:44 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

// int main() {

//     Brain a;
//     Brain b(a);
//     Brain c;

//     c = a;

//     c.printIdeas();

//     return (0);
// }


int main()
{
    const Animal* array[6] = { new Dog(), new Dog(), new Dog(), new Cat(), new Cat(), new Cat() };

    for (int i = 0; i < 6; i++) {
        
        delete array[i]; 
    }

    std::cout << "--------------------------------" << std::endl;

    Brain* a = new Brain();
    a->printIdeas();
    
    std::cout << "--------------------------------" << std::endl;
    
    a->setIdeas("I am hungry", 5);
    a->setIdeas("I am thinking", 55);
    a->setIdeas("I am happy", 95);
    a->printIdeas();

    Brain* b = a->clone();
    b->printIdeas();

    delete a;
    delete b;
    
    std::cout << "--------------------------------" << std::endl;

    const Cat* catty = new Cat();    
    const Cat* cattycopy(catty);
    const Cat* other;
    
    other = cattycopy;

    delete other;

    Cat* cat = new Cat();
    Cat* copycat = cat->clone();
    
    delete cat;
    delete copycat;

    Dog* dog = new Dog();
    Dog* copydog = dog->clone();
    
    delete dog;
    delete copydog;

    return 0;
}
