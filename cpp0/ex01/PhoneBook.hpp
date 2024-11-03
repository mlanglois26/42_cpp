/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:46:52 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/01 12:55:07 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <iomanip>
# include <iostream>
# include <limits>

class PhoneBook
{
  public:
	PhoneBook();
	~PhoneBook();
	
	int getContactCount();
	void addContact();
	void displayContacts();
	void selectContact();

  private:
	static const int _MAX_CONTACT = 8;
	Contact _contacts[_MAX_CONTACT];
	int _contactCount;
	int _oldestContact;
	int _verifOnlyDigit( std::string str );
};

#endif
