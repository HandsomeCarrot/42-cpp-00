/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:31:49 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/10 17:54:52 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	public:
		Contact(void);
		Contact
		(
			std::string	&new_firstName,
			std::string	&new_lastName,
			std::string	&new_nickname,
			std::string	&new_secret,
			int			new_phoneNumber
		);
		~Contact(void);
		Contact&	operator=(const Contact& other);
		std::string	get_firstName(void);
		std::string	get_lastName(void);
		std::string	get_nickname(void);
		std::string	get_secret(void);
		int			get_phoneNumber(void);

	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	secret;
		int			phoneNumber;
};

#endif
