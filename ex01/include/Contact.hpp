/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:31:49 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/11 00:47:01 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	public:

		Contact(void);
		~Contact(void);

		void		set_firstName(std::string s);
		std::string	get_firstName(void);

		void		set_lastName(std::string s);
		std::string	get_lastName(void);

		void		set_nickname(std::string s);
		std::string	get_nickname(void);

		void		set_secret(std::string s);
		std::string	get_secret(void);

		void		set_phoneNumber(std::string s);
		std::string	get_phoneNumber(void);


	private:

		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	secret;
		std::string	phoneNumber;
};

#endif
