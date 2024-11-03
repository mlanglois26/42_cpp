/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookHelper.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:12:42 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/01 11:50:39 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int PhoneBook::getContactCount()
{
	return (this->_contactCount);
}

int PhoneBook::_verifOnlyDigit(std::string str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (!std::isdigit(str[i]))
            return (1);
    }
    return (0);
}
