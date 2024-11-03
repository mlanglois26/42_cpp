/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:53:55 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/01 11:43:58 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(int argc, char **argv) {
    
    PhoneBook repObj;
    std::string instruction;
    
    if (argc == 1) {
        
        std::cout << "What do yo want to do? (ADD, SEARCH or EXIT): ";
        while (std::getline(std::cin, instruction)) {
            
            if (instruction == "ADD") {
                
                repObj.addContact();
            }
            else if (instruction == "SEARCH") {
                
                repObj.displayContacts();
                if (repObj.getContactCount() > 0)
                    repObj.selectContact();
            }
            else if (instruction == "EXIT")
                return (0);
            else {
                
                std::cout << "Invalid choice. Please try again.\n";
            }
            std::cout << "What do yo want to do? (ADD, SEARCH or EXIT): ";
        }
    }
    return (0);
}
