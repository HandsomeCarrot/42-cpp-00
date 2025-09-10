/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:27:22 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/10 23:42:04 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) :
	contacts_count(0),
	new_contact_index(0)
{
	std::cout << "empty phone book created" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "phone book cleared" << std::endl;
}

void	PhoneBook::add_contact
(
	std::string		new_firstName,
	std::string		new_lastName,
	std::string		new_nickname,
	std::string		new_secret,
	unsigned int	new_phoneNumber
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

std::string	PhoneBook::truncate_string(std::string s)
{
	if (s.length() <= 10)
		return (s);
	return (s.substr(0, 9) + '.');
}

template	<typename T>
void		PhoneBook::display_single_info(std::string info_type, T info)
{
	std::cout << std::setw(14) << info_type << ": " << info << std::endl;
}

void	PhoneBook::display_separator_line(unsigned int separations)
{
	unsigned int	i;

	std::cout << "|";
	i = 0;
	while (i <= separations)
	{
		std::cout << std::setfill('-') << std::setw(10) << "|";
		i++;
	}
	std::cout << std::endl;
}

template	<typename T>
void		PhoneBook::display_multi_info
(
	T index,
	std::string firstName,
	std::string lastName,
	std::string nickname
)
{
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << firstName;
	std::cout << "|" << std::setw(10) << lastName;
	std::cout << "|" << std::setw(10) << nickname;
	std::cout << "|" << std::endl;
}

void	PhoneBook::display_contact_list(void)
{
	unsigned int	i;

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
}

void	PhoneBook::display_contact(unsigned int contact_index)
{
	if (contact_index >= contacts_count)
	{
		std::cout << "invalid index" << std::endl;
		return;
	}
	display_single_info<std::string>("first name", contacts[contact_index].get_firstName());
	display_single_info<std::string>("last name", contacts[contact_index].get_lastName());
	display_single_info<std::string>("nickname", contacts[contact_index].get_nickname());
	display_single_info<int>("phone number", contacts[contact_index].get_phoneNumber());
	display_single_info<std::string>("darkest secret", contacts[contact_index].get_secret());
}
