/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:57:45 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/10 23:39:56 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>

static std::string	get_str_input(std::string prompt)
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

static unsigned int	get_int_input(std::string prompt)
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

static void	add_contact(PhoneBook *pb)
{
	std::cout << "Adding new contact to the phone book." << std::endl;
	pb->add_contact
	(
		get_str_input("First name"),
		get_str_input("Last name"),
		get_str_input("Nickname"),
		get_str_input("Darkest secret"),
		get_int_input("Phone number")
	);
}

static void	search_contact(PhoneBook *pb)
{
	(void)pb;
}

int	main(void)
{
	PhoneBook	pb;
	std::string	command;

	while (true)
	{
		std::cout << "PhoneBook>> ";
		std::cin >> command;
		if (command == "ADD")
			add_contact(&pb);
		else if (command == "SEARCH")
			search_contact(&pb);
		else if (command == "EXIT")
			break;
		else
			std::cout << "ERROR: only accept these commands: ADD/SEARCH/EXIT" << std::endl;
	}
	return (0);
}