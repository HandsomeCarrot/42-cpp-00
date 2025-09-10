/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:26:28 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/11 00:51:53 by vpoka            ###   ########.fr       */
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
		
		unsigned int	contacts_count;

		void	add_contact
		(
			std::string	new_firstName,
			std::string	new_lastName,
			std::string	new_nickname,
			std::string	new_secret,
			std::string	new_phoneNumber
		);

		void	display_contact_list(void);
		void	display_contact(unsigned int contact_index);

	private:

		Contact	contacts[8];
		unsigned int	new_contact_index;

		std::string		truncate_string(std::string s);
		void			display_single_info(std::string info_type, std::string info);
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