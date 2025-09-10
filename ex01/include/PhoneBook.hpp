/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:26:28 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/11 01:58:43 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>

# define MAX_CONTACTS 8
# define SHORT_STR_WIDTH 10

class PhoneBook
{
	public:

		PhoneBook(void);
		~PhoneBook(void);

		unsigned int	getContactsCount(void) const;

		void	addContact
		(
			const std::string	&newFirstName,
			const std::string	&newLastName,
			const std::string	&newNickname,
			const std::string	&newSecret,
			const std::string	&newPhoneNumber
		);
		
		void	displayContactList(void);
		void	displayContact(unsigned int contact_index);
		
		private:
		
		Contact			contacts[MAX_CONTACTS];
		unsigned int	contactsCount;
		unsigned int	newContactIndex;

		std::string	truncateString(const std::string &s);
		void		displaySingleInfo(std::string info_type, std::string info);
		void		displaySeparatorLine(unsigned int separations);

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
		template	<typename T>
		void		displayMultiInfo(T index, std::string firstName, std::string lastName, std::string nickname)
		{
			std::cout.setf (std::ios::right);
			std::cout << "|" << std::setfill(' ') << std::setw(10) << index;
			std::cout << "|" << std::setw(10) << firstName;
			std::cout << "|" << std::setw(10) << lastName;
			std::cout << "|" << std::setw(10) << nickname;
			std::cout << "|" << std::endl;
		}
};

#endif