/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:06:19 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/01 11:47:22 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){};

Contact::~Contact(){};

void Contact::createContact() {
    
	std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
    
    std::cout << "Please, enter your First Name = " << std::endl;
    std::getline(std::cin, firstName);
    _inputSecure(firstName);
    setFirstName(firstName);
	std::cout << "Please, enter your Last Name = " << std::endl;
    std::getline(std::cin, lastName);
    _inputSecure(lastName);
    setLastName(lastName);
	std::cout << "Please, enter your Nickname = " << std::endl;
    std::getline(std::cin, nickName);
    _inputSecure(nickName);
    setNickName(nickName);
	std::cout << "Please, enter your Phone Number = " << std::endl;
    std::getline(std::cin, phoneNumber);
    _inputSecureAlnum(phoneNumber);
    setPhoneNumber(phoneNumber);
	std::cout << "Please, enter your Darkest Secret = " << std::endl;
    std::getline(std::cin, darkestSecret);
    _inputSecureAlnum(darkestSecret);
    setDarkestSecret(darkestSecret);
}

void Contact::getContactData() {
    
	std::cout << std::setw(10) << std::right << _resizing(this->getFirstName());
	std::cout << " | ";
	std::cout << std::setw(10) << std::right << _resizing(this->getLastName());
	std::cout << " | ";
	std::cout << std::setw(10) << std::right << _resizing(this->getNickName()) << std::endl;
}

void Contact::recapContactData() {
    
    std::cout << std::endl;
    std::cout << "First name = " << this->getFirstName() << std::endl;
    std::cout << "Last name = " << this->getLastName() << std::endl;
    std::cout << "Nick name = " << this->getNickName() << std::endl;
    std::cout << "Phone number = " << this->getPhoneNumber() << std::endl;
    std::cout << "Darkest secret = " << this->getDarkestSecret() << std::endl << std::endl;
}
