/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Getters.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:01:06 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/01 11:48:50 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFirstName() {
    
    return (this->_firstName);
}

std::string Contact::getLastName() {

    return (this->_lastName);
}

std::string Contact::getNickName() {
    
    return (this->_nickName);
}

std::string Contact::getPhoneNumber() {

    return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret() {
    
    return (this->_darkestSecret);
}
