/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:46:20 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/10 23:36:50 by vpoka            ###   ########.fr       */
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
