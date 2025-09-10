/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:27:22 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/11 00:51:16 by vpoka            ###   ########.fr       */
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
	contacts_count(0),
	new_contact_index(0)
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
 * @brief Adds a new contact to the phone book.
 *
 * This method creates a new contact entry using the provided details and stores it
 * in the contacts array at the current new_contact_index. If the index reaches 7,
 * it wraps around to 0, effectively overwriting the oldest contact when the phone
 * book is full (maximum 8 contacts). The contacts_count is incremented up to 8.
 *
 * @param new_firstName The first name of the new contact.
 * @param new_lastName The last name of the new contact.
 * @param new_nickname The nickname of the new contact.
 * @param new_secret The darkest secret of the new contact.
 * @param new_phoneNumber The phone number of the new contact.
 */
void	PhoneBook::add_contact
(
	std::string	new_firstName,
	std::string	new_lastName,
	std::string	new_nickname,
	std::string	new_secret,
	std::string	new_phoneNumber
)
{
	contacts[new_contact_index].set_firstName(new_firstName);
	contacts[new_contact_index].set_lastName(new_lastName);
	contacts[new_contact_index].set_nickname(new_nickname);
	contacts[new_contact_index].set_secret(new_secret);
	contacts[new_contact_index].set_phoneNumber(new_phoneNumber);
	
	if (new_contact_index == 7)
		new_contact_index = 0;
	else
		new_contact_index++;
	if (contacts_count < 8)
		contacts_count++;
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
std::string	PhoneBook::truncate_string(std::string s)
{
	if (s.length() <= 10)
		return (s);
	return (s.substr(0, 9) + '.');
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
void		PhoneBook::display_single_info(std::string info_type, std::string info)
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
void	PhoneBook::display_separator_line(unsigned int separations)
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

template	<typename T>
/**
 * @brief Displays a formatted row of contact information in the phone book.
 * 
 * This function outputs a single row of contact details, including the index,
 * first name, last name, and nickname, formatted as a table row with fixed-width
 * columns separated by pipes. It is used to present multiple contacts in a
 * tabular format for easy viewing.
 * 
 * @param index The index number of the contact in the phone book.
 * @param firstName The first name of the contact.
 * @param lastName The last name of the contact.
 * @param nickname The nickname of the contact.
 * 
 * @note The output is sent to std::cout and includes a newline at the end.
 *       Each field is left-aligned and padded to 10 characters.
 */
void		PhoneBook::display_multi_info(T index, std::string firstName, std::string lastName, std::string nickname)
{
	std::cout.setf (std::ios::right);
	std::cout << "|" << std::setfill(' ') << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << firstName;
	std::cout << "|" << std::setw(10) << lastName;
	std::cout << "|" << std::setw(10) << nickname;
	std::cout << "|" << std::endl;
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
void	PhoneBook::display_contact_list(void)
{
	unsigned int	i;

	std::cout << std::endl;
	if (contacts_count == 0)
	{
		std::cout << "ERROR: no contacts saved" << std::endl;
		return;
	}
	display_separator_line(4);
	display_multi_info<std::string>("INDEX", "FIRST NAME", "LAST NAME", "NICKNAME");
	display_separator_line(4);
	i = 0;
	while (i < contacts_count)
	{
		display_multi_info<int>
		(
			i,
			truncate_string(contacts[i].get_firstName()),
			truncate_string(contacts[i].get_lastName()),
			truncate_string(contacts[i].get_nickname())
		);
		display_separator_line(4);
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
void	PhoneBook::display_contact(unsigned int contact_index)
{
	std::cout << std::endl;
	if (contact_index >= contacts_count)
	{
		std::cout << "invalid index" << std::endl;
		return;
	}
	display_single_info("first name", contacts[contact_index].get_firstName());
	display_single_info("last name", contacts[contact_index].get_lastName());
	display_single_info("nickname", contacts[contact_index].get_nickname());
	display_single_info("phone number", contacts[contact_index].get_phoneNumber());
	display_single_info("darkest secret", contacts[contact_index].get_secret());
	std::cout << std::endl;
}
