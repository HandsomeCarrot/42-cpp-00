/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:46:20 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/10 23:48:57 by vpoka            ###   ########.fr       */
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
	phoneNumber(0)
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
void	Contact::set_firstName(std::string s)
{
	firstName = s;
}

/**
 * @brief returns the first name of the contact.
 */
std::string	Contact::get_firstName(void)
{
	return (firstName);
}

/**
 * @brief Sets the last name of the contact.
 * 
 * @param s The string representing the last name to set.
 */
void	Contact::set_lastName(std::string s)
{
	lastName = s;
}

/**
 * @brief returns the last name of the contact.
 */
std::string	Contact::get_lastName(void)
{
	return (lastName);
}

/**
 * @brief Sets the nickname of the contact.
 * 
 * @param s The string representing the nickname to set.
 */
void	Contact::set_nickname(std::string s)
{
	nickname = s;
}

/**
 * @brief returns the nickname of the contact.
 */
std::string	Contact::get_nickname(void)
{
	return (nickname);
}

/**
 * @brief Sets the secret of the contact.
 * 
 * @param s The string representing the secret to set.
 */
void	Contact::set_secret(std::string s)
{
	secret = s;
}

/**
 * @brief returns the darkest secret of the contact.
 */
std::string	Contact::get_secret(void)
{
	return (secret);
}

/**
 * @brief Sets the phone number of the contact.
 * 
 * @param i The integer representing the phone number to set.
 */
void	Contact::set_phoneNumber(unsigned int i)
{
	phoneNumber = i;
}

/**
 * @brief returns the phone number of the contact.
 */
unsigned int	Contact::get_phoneNumber(void)
{
	return (phoneNumber);
}
