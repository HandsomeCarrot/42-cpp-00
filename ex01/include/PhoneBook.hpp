/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:26:28 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/10 23:29:43 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add_contact
		(
			std::string		new_firstName,
			std::string		new_lastName,
			std::string		new_nickname,
			std::string		new_secret,
			unsigned int	new_phoneNumber
		);
		void	display_contact_list(void);
		void	display_contact(unsigned int contact_index);
	private:
		Contact	contacts[8];
		unsigned int	contacts_count;
		unsigned int	new_contact_index;

		std::string		truncate_string(std::string s);
		template		<typename T>
		void			display_single_info(std::string info_type, T info);
		void			display_separator_line(unsigned int separations);
		template		<typename T>
		void			display_multi_info
		(
			T index,
			std::string firstName,
			std::string lastName,
			std::string nickname
		);
};

#endif