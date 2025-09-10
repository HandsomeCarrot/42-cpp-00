/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:58:38 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/08 17:30:39 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	print_uppercase(std::string s)
{
	unsigned long	pos;

	pos = 0;
	while (pos < s.length())
	{
		s[pos] = std::toupper(s[pos]);
		pos++;
	}
	std::cout << s;
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		i = 2;
		while (i <= argc)
		{
			print_uppercase(argv[i - 1]);
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}
