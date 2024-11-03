/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Setters.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:58:03 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/01 11:51:36 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(std::string firstName) {
	
	this->_firstName = firstName;
}

void Contact::setLastName(std::string lastName) {

	this->_lastName = lastName;
}

void Contact::setNickName(std::string nickName) {
	
	this->_nickName = nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
	
	this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
	
	this->_darkestSecret = darkestSecret;
}
