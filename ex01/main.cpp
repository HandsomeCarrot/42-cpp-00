/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:57:45 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/10 19:11:54 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	add_contact(PhoneBook *pb)
{
	(void)pb;
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