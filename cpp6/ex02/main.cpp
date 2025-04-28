/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:53:11 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/28 09:41:43 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {

   int t = rand() % 3;
   switch (t) {

        case 0: {

            return (new A());
        }
        case 1: {

            return (new B());
        }
        case 2: {

            return (new C());
        }
        default: {

            std::cout << "Oups... Something went wrong" << std::endl;
            return (NULL);
        }
    }
}

void identify(Base* p) {
    
    std::cout << "Identify with pointer: ";
    if (dynamic_cast<A*>(p) != NULL) {

        std::cout << "Object pointed is of type A" << std::endl;
    }
    else if (dynamic_cast<B*>(p) != NULL) {
        
        std::cout << "Object pointed is of type B" << std::endl;
    }
    else if (dynamic_cast<C*>(p) != NULL) {

        std::cout << "Object pointed is of type C" << std::endl;
    }
    else
        std::cout << "Oups... Cannot identify the type of the object pointed" << std::endl;
}

void identify(Base& p) {

    std::cout << "Identify with reference: ";
    try {
        
        A a = dynamic_cast<A&>(p);
        std::cout << "Object refered to is of type A" << std::endl;
        return ;
    }
    catch (const std::exception& e) {

        (void)e;
    }
    try {
        
        B b = dynamic_cast<B&>(p);
        std::cout << "Object refered to is of type B" << std::endl;
        return ;
    }
    catch (const std::exception& e) {

        (void)e;
    }
    try {
        
        C c = dynamic_cast<C&>(p);
        std::cout << "Object refered to is of type C" << std::endl;
        return ;
    }
    catch (const std::exception& e) {

        (void)e;
    }
}

int main() {

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {

        std::cout << "i = " << i + 1 << std::endl;
        
        Base* base = generate();

        identify(base);
        identify(*base);

        usleep(1000000);
    }
    return (0);
}

// dynamic cast c est quand je ne connais pas le type de mon objet