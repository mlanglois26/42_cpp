/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:25:28 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/01 12:55:51 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contactCount(0), _oldestContact(0) {};

PhoneBook::~PhoneBook(){};

void PhoneBook::addContact() {
	
	if (this->_contactCount < _MAX_CONTACT) {
		
		_contacts[this->_contactCount].createContact();
		this->_contactCount += 1;
	}
	else {
		
		std::cout << "The PhoneBook is full. Adding this contact will overwrite on the 8th one." << std::endl;
		_contacts[_oldestContact].createContact();

		_oldestContact = (_oldestContact + 1) % _MAX_CONTACT;
	}
}

void PhoneBook::displayContacts() {
	
	if (this->_contactCount == 0) {
		
		std::cout << "The PhoneBook is empty." << std::endl;
		return ;
	}
	
	std::cout << std::endl;
	std::cout << std::setw(10) << std::right << "ID";
	std::cout << " | ";
	std::cout << std::setw(10) << std::right << "First Name";
	std::cout << " | ";
	std::cout << std::setw(10) << std::right << "Last Name";
	std::cout << " | ";
	std::cout << std::setw(10) << std::right << "Nick Name" << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
	for (int i = 0; i < this->_contactCount; i++) {
		
        std::cout << std::setw(10) << std::right << (i + 1);
		std::cout << " | ";
		_contacts[i].getContactData();
	}
	std::cout << "-----------------------------------------------------" << std::endl << std::endl;
}

void PhoneBook::selectContact() {
	
	std::string input;
    int idx;
    
	std::cout << "Please, select Contact index to access its data = ";
	std::getline(std::cin, input);

    if (std::cin.eof())
        exit (0);
    
    if (_verifOnlyDigit(input) == 1) {
		
        std::cout << "Please select a contact using its index." << std::endl;
        return ;
    }
        
    idx = std::stoi(input);
    if (idx < 1 || idx > 8) {
		
        std::cout << "This is not a valid index. Select a digit from 1 to 8." << std::endl;
        return ;
    }
    idx -= 1;
	_contacts[idx].recapContactData();
}
