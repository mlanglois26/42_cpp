/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:53:06 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/01 11:44:34 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iomanip>
# include <iostream>
# include <cstring>

class Contact
{
  public:
	Contact();
	~Contact();

	void setFirstName( std::string firstName );
	void setLastName( std::string lastName );
	void setNickName( std::string nickName );
	void setPhoneNumber( std::string phoneNumber );
	void setDarkestSecret( std::string darkestSecret );

	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
	std::string getPhoneNumber();
	std::string getDarkestSecret();

	void createContact();
	void getContactData();
    void recapContactData();

  private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;
	
	int _blankCheck( std::string str );
	void _inputSecure( std::string &input );
	int _alnumCheck( std::string str );
	void _inputSecureAlnum( std::string &input );
	std::string	_resizing( std::string str );
};


#endif