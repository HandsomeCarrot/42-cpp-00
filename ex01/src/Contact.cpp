/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:46:20 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/11 01:38:15 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	phoneNumber("")
{
	std::cout << "created an empty contact." << std::endl;
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


/**
 * @brief Sets the first name of the contact.
 * 
 * @param s The string representing the first name to set.
 */
void	Contact::setFirstName(const std::string &s)
{
	firstName = s;
}

/**
 * @brief returns the first name of the contact.
 */
std::string	Contact::getFirstName(void) const
{
	return (firstName);
}

/**
 * @brief Sets the last name of the contact.
 *
 * @param s The string representing the last name to set.
 */
void	Contact::setLastName(const std::string &s)
{
	lastName = s;
}

/**
 * @brief returns the last name of the contact.
 */
std::string	Contact::getLastName(void) const
{
	return (lastName);
}

/**
 * @brief Sets the nickname of the contact.
 *
 * @param s The string representing the nickname to set.
 */
void	Contact::setNickname(const std::string &s)
{
	nickname = s;
}

/**
 * @brief returns the nickname of the contact.
 */
std::string	Contact::getNickname(void) const
{
	return (nickname);
}

/**
 * @brief Sets the secret of the contact.
 *
 * @param s The string representing the secret to set.
 */
void	Contact::setSecret(const std::string &s)
{
	secret = s;
}

/**
 * @brief returns the darkest secret of the contact.
 */
std::string	Contact::getSecret(void) const
{
	return (secret);
}

/**
 * @brief Sets the phone number of the contact.
 *
 * @param i The integer representing the phone number to set.
 */
void	Contact::setPhoneNumber(const std::string &s)
{
	phoneNumber = s;
}

/**
 * @brief returns the phone number of the contact.
 */
std::string	Contact::getPhoneNumber(void) const
{
	return (phoneNumber);
}
