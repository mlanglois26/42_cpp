/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:32:05 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/28 09:42:33 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {

    Data* ptr = new Data;

    ptr->name = "marie";
    ptr->age = 27;

    std::cout << "ptr address = " << ptr << std::endl;
    std::cout << "name: " << ptr->name << std::endl;
    std::cout << "age: " << ptr->age << std::endl;
    
    uintptr_t res = 0;

    res = Serializer::serialize(ptr);
    std::cout << "serialize value = " << res << std::endl;

    Data* ptr2;

    ptr2 = Serializer::deserialize(res);    
    std::cout << "ptr2 address = " << ptr2 << std::endl;
    
    std::cout << "name: " << ptr2->name << std::endl;
    std::cout << "age: " << ptr2->age << std::endl;

    return (0);
}

