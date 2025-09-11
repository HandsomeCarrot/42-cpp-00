/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:27:22 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/11 02:00:13 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/**
 * @brief Default constructor for the PhoneBook class.
 * 
 * Initializes a new PhoneBook instance with no contacts.
 * Sets the contacts count and new contact index to zero.
 * Outputs a message indicating that an empty phone book has been created.
 */
PhoneBook::PhoneBook(void) :
	contactsCount(0),
	newContactIndex(0)
{
	std::cout << "empty phone book created" << std::endl;
}

/**
 * @brief Destructor for the PhoneBook class.
 * 
 * This destructor is responsible for cleaning up resources associated with the PhoneBook object.
 * It outputs a message to the console indicating that the phone book has been cleared.
 */
PhoneBook::~PhoneBook(void)
{
	std::cout << "phone book cleared" << std::endl;
}

/**
 * @brief Retrieves the current number of contacts stored in the phone book.
 * 
 * This method returns the total count of contacts that have been added to the PhoneBook instance.
 * 
 * @return The number of contacts as an unsigned integer.
 */
unsigned int	PhoneBook::getContactsCount(void) const
{
	return (contactsCount);
}

/**
 * @brief Adds a new contact to the phone book.
 *
 * This method creates a new contact entry using the provided details and stores it
 * in the contacts array at the current newContactIndex. If the index reaches MAX_CONTACTS - 1,
 * it wraps around to 0, effectively overwriting the oldest contact when the phone
 * book is full. The contactsCount is incremented up to MAX_CONTACTS.
 *
 * @param new_firstName The first name of the new contact.
 * @param new_lastName The last name of the new contact.
 * @param new_nickname The nickname of the new contact.
 * @param new_secret The darkest secret of the new contact.
 * @param new_phoneNumber The phone number of the new contact.
 */
void	PhoneBook::addContact
(
	const std::string	&new_firstName,
	const std::string	&new_lastName,
	const std::string	&new_nickname,
	const std::string	&new_secret,
	const std::string	&new_phoneNumber
)
{
	contacts[newContactIndex].setFirstName(new_firstName);
	contacts[newContactIndex].setLastName(new_lastName);
	contacts[newContactIndex].setNickname(new_nickname);
	contacts[newContactIndex].setSecret(new_secret);
	contacts[newContactIndex].setPhoneNumber(new_phoneNumber);
	
	if (newContactIndex == MAX_CONTACTS - 1)
		newContactIndex = 0;
	else
		newContactIndex++;
	if (contactsCount < MAX_CONTACTS)
		contactsCount++;
}

/**
 * @brief Truncates a string to a maximum length of 10 characters.
 * 
 * If the input string's length is 10 or less, it is returned unchanged.
 * If the string is longer than 10 characters, it is truncated to the first 9 characters
 * and a period (.) is appended to indicate truncation.
 * 
 * @param s The input string to be truncated.
 * @return A new string that is either the original (if <= 10 chars) or truncated to 10 chars with a '.'.
 */
std::string	PhoneBook::truncateString(const std::string &s)
{
	if (s.length() <= SHORT_STR_WIDTH)
		return (s);
	return (s.substr(0, SHORT_STR_WIDTH - 1) + '.');
}

/**
 * @brief Displays a single piece of information with its type label, formatted to a width of 14 characters.
 * 
 * This function outputs the provided info_type followed by a colon and the info value, 
 * ensuring the info_type is right-aligned in a field of width 14 for consistent formatting.
 * 
 * @tparam T The type of the information to be displayed (e.g., std::string, int).
 * @param info_type A string representing the type or label of the information (e.g., "First Name").
 * @param info The actual information value to be displayed.
 */
void		PhoneBook::displaySingleInfo(std::string info_type, std::string info)
{
	std::cout.setf (std::ios::left);
	std::cout << std::setfill(' ') << std::setw(14) << info_type << ": " << info << std::endl;
}

/**
 * @brief Displays a separator line for the phone book table.
 * 
 * This function prints a horizontal separator line consisting of vertical bars ('|') 
 * and dashes ('-') to visually separate sections in the phone book display. The number 
 * of separations determines how many 10-character wide segments are printed, each 
 * filled with dashes and ended with a '|'.
 * 
 * @param separations The number of separator segments to display. Each segment is 
 *                    10 characters wide, filled with dashes, and bounded by '|'.
 */
void	PhoneBook::displaySeparatorLine(unsigned int separations)
{
	unsigned int	i;

	std::cout << "|";
	i = 0;
	while (i < separations)
	{
		std::cout << std::setfill('-') << std::setw(11) << "|";
		i++;
	}
	std::cout << std::endl;
}

/**
 * @brief Displays the list of contacts in the phone book.
 *
 * This function iterates through the stored contacts and prints them in a formatted table.
 * It includes an index, first name, last name, and nickname for each contact.
 * The output is surrounded by separator lines for better readability.
 * Only contacts up to the current count are displayed.
 *
 * @note The names are truncated if they exceed a certain length for display purposes.
 * @note This function does not modify any data; it only prints to the console.
 */
void	PhoneBook::displayContactList(void)
{
	unsigned int	i;

	if (contactsCount == 0)
	{
		std::cout << "ERROR: no contacts saved" << std::endl;
		return;
	}
	std::cout << std::endl;
	displaySeparatorLine(4);
	displayMultiInfo<std::string>("INDEX", "FIRST NAME", "LAST NAME", "NICKNAME");
	displaySeparatorLine(4);
	i = 0;
	while (i < contactsCount)
	{
		displayMultiInfo<int>
		(
			i,
			truncateString(contacts[i].getFirstName()),
			truncateString(contacts[i].getLastName()),
			truncateString(contacts[i].getNickname())
		);
		displaySeparatorLine(4);
		i++;
	}
	std::cout << std::endl;
}

/**
 * @brief Displays the details of a specific contact in the phone book.
 * 
 * This function takes a contact index and prints out the first name, last name,
 * nickname, phone number, and darkest secret of the contact at that index.
 * If the provided index is out of bounds (greater than or equal to the current
 * number of contacts), it outputs an "invalid index" message and returns early.
 * 
 * @param contact_index The zero-based index of the contact to display.
 *                      Must be less than the total number of contacts stored.
 */
void	PhoneBook::displayContact(unsigned int contact_index)
{
	std::cout << std::endl;
	if (contact_index >= contactsCount)
	{
		std::cout << "invalid index" << std::endl;
		return;
	}
	displaySingleInfo("first name", contacts[contact_index].getFirstName());
	displaySingleInfo("last name", contacts[contact_index].getLastName());
	displaySingleInfo("nickname", contacts[contact_index].getNickname());
	displaySingleInfo("phone number", contacts[contact_index].getPhoneNumber());
	displaySingleInfo("darkest secret", contacts[contact_index].getSecret());
	std::cout << std::endl;
}
