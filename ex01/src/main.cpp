/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:57:45 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/11 01:20:40 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>


/**
 * @brief Prompts the user for a non-empty string input from standard input.
 * 
 * This function repeatedly prompts the user with the given prompt string until a non-empty input is provided.
 * It uses std::getline to read the entire line from std::cin, ensuring that whitespace is preserved.
 * If the input is empty, it displays an error message and prompts again.
 * 
 * @param prompt The string to display as the prompt for user input.
 * @return A non-empty std::string containing the user's input.
 */
static std::string	getStrInput(std::string prompt)
{
	std::string	input;

	while (true)
	{
		std::cout << prompt << ": ";
		std::getline(std::cin, input);
		if (!input.empty())
			break;
		std::cout << "Invalid input. Try again!" << std::endl;
	}
	return (input);
}

/**
 * @brief Prompts the user for an unsigned integer input and validates it.
 * 
 * This function repeatedly prompts the user with the given string until a valid
 * unsigned integer is entered. It handles invalid inputs by clearing the error
 * state and ignoring the rest of the input line to prevent infinite loops.
 * 
 * @param prompt The string to display as the prompt for user input.
 * @return The valid unsigned integer entered by the user.
 */
static unsigned int	getIntInput(std::string prompt)
{
	unsigned int	input;

	while (true)
	{
		std::cout << prompt << ": ";
		if (std::cin >> input)
			break;
		std::cout << "Invalid input. Field only accepts numbers. Try again!" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (input);
}

/**
 * @brief Adds a new contact to the phone book by prompting the user for input details.
 * 
 * This function collects user input for first name, last name, nickname, darkest secret, 
 * and phone number, then adds the new contact to the provided PhoneBook instance.
 * 
 * @param pb Pointer to the PhoneBook object where the contact will be added.
 */
static void	add(PhoneBook *pb)
{
	std::cout << "Adding new contact to the phone book." << std::endl;
	pb->addContact
	(
		getStrInput("First name"),
		getStrInput("Last name"),
		getStrInput("Nickname"),
		getStrInput("Darkest secret"),
		getStrInput("Phone number")
	);
}

/**
 * @brief Searches and displays a contact from the phone book based on user input index.
 * 
 * This function first displays the list of contacts in the phone book. If there are no contacts,
 * it returns immediately. Otherwise, it prompts the user to enter an index and validates it.
 * If the index is valid (between 0 and contactsCount - 1), it displays the contact at that index.
 * If invalid, it prompts again until a valid index is provided.
 * 
 * @param pb A pointer to the PhoneBook object containing the contacts.
 */
static void	search(PhoneBook *pb)
{
	unsigned int	contactsCount;
	unsigned int	index;

	pb->displayContactList();
	contactsCount = pb->getContactsCount();
	if (contactsCount == 0)
		return;
	while (true)
	{
		index = getIntInput("Enter index to display contact");
		if (index < contactsCount)
			break;
		std::cout << "Invalid index. Choose a index between 0 and " << contactsCount - 1;
		std::cout << std::endl;
	}
	pb->displayContact(index);
}

int	main(void)
{
	PhoneBook	pb;
	std::string	command;

	while (true)
	{
		std::cout << "PhoneBook>> ";
		getline(std::cin, command);
		if (command == "ADD")
			add(&pb);
		else if (command == "SEARCH")
			search(&pb);
		else if (command == "EXIT")
			break;
		else
			std::cout << "ERROR: only accept these commands: ADD/SEARCH/EXIT" << std::endl;
	}
	return (0);
}