/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:46:20 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/10 17:56:12 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"


/**
 * @brief Default constructor for the Contact class.
 *
 * Initializes all member variables to their default values:
 * - firstName, lastName, nickname, and secret are set to empty strings.
 * - phoneNumber is set to 0.
 * Also outputs a message indicating that an empty contact has been created.
 */
Contact::Contact(void) :
	firstName(""),
	lastName(""),
	nickname(""),
	secret(""),
	phoneNumber(0)
{
	std::cout << "created an empty contact." << std::endl;
}

/**
 * @brief Constructs a new Contact object with the provided details.
 *
 * Initializes the contact's first name, last name, nickname, phone number, and secret.
 * Outputs a message to the standard output indicating the creation of the new contact.
 *
 * @param new_firstName The first name of the contact.
 * @param new_lastName The last name of the contact.
 * @param new_nickname The nickname of the contact.
 * @param new_secret The secret associated with the contact.
 * @param new_phoneNumber The phone number of the contact.
 */
Contact::Contact
(
	std::string	&new_firstName,
	std::string	&new_lastName,
	std::string	&new_nickname,
	std::string	&new_secret,
	int			new_phoneNumber
) :
	firstName(new_firstName),
	lastName(new_lastName),
	nickname(new_nickname),
	secret(new_secret),
	phoneNumber(new_phoneNumber)
{
	std::cout << "created new contact: ";
	std::cout << firstName << " " << lastName;
	std::cout << "(" << nickname << ")" << std::endl;
}

/**
 * @brief Destructor for the Contact class.
 *
 * Outputs a message to the standard output stream indicating that a Contact object
 * has been deleted. If the contact's first name, last name, and nickname are all set,
 * it prints the full name and nickname; otherwise, it prints "unknown".
 */
Contact::~Contact(void)
{
	std::cout << "deleted contact: ";
	if (firstName.size() > 0 && lastName.size() > 0 && nickname.size() > 0)
	{
		std::cout << firstName << " " << lastName;
		std::cout << "(" << nickname << ")";
	}
	else
		std::cout << "unknown";
	std::cout << std::endl;
}

Contact&	Contact::operator=(const Contact& other)
{
	firstName = other.firstName;
	lastName = other.lastName;
	nickname = other.nickname;
	secret = other.secret;
	phoneNumber = other.phoneNumber;
	return (*this);
}

/**
 * @brief returns the first name of the contact.
 */
std::string Contact::get_firstName(void)
{
	return (firstName);
}

/**
 * @brief returns the last name of the contact.
 */
std::string Contact::get_lastName(void)
{
	return (lastName);
}

/**
 * @brief returns the nickname of the contact.
 */
std::string Contact::get_nickname(void)
{
	return (nickname);
}

/**
 * @brief returns the darkest secret of the contact.
 */
std::string	Contact::get_secret(void)
{
	return (secret);
}

/**
 * @brief returns the phone number of the contact.
 */
int Contact::get_phoneNumber(void)
{
	return (phoneNumber);
}
