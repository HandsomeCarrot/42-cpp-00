/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:31:49 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/11 01:14:24 by vpoka            ###   ########.fr       */
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

		void		setFirstName(std::string s);
		std::string	getFirstName(void);

		void		setLastName(std::string s);
		std::string	getLastName(void);

		void		setNickname(std::string s);
		std::string	getNickname(void);

		void		setSecret(std::string s);
		std::string	getSecret(void);

		void		setPhoneNumber(std::string s);
		std::string	getPhoneNumber(void);


	private:

		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	secret;
		std::string	phoneNumber;
};

#endif
