/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:31:49 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/11 01:38:09 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	public:

		Contact(void);
		~Contact(void);

		void		setFirstName(const std::string &s);
		std::string	getFirstName(void) const;

		void		setLastName(const std::string &s);
		std::string	getLastName(void) const;

		void		setNickname(const std::string &s);
		std::string	getNickname(void) const;

		void		setSecret(const std::string &s);
		std::string	getSecret(void) const;

		void		setPhoneNumber(const std::string &s);
		std::string	getPhoneNumber(void) const;


	private:

		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	secret;
		std::string	phoneNumber;
};

#endif
