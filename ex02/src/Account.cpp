/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:55:34 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/11 17:13:56 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

static void	displayInfo(std::string desc, int info, int sep)
{
	std::cout << desc << ":" << info;
	if (sep)
		std::cout << ";";
}

Account::Account(int initial_deposit) :
	_accountIndex(_nbAccounts),
	_amount(initial_deposit)
{
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	displayInfo("index", _accountIndex, 1);
	displayInfo("amount", _amount, 1);
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
	_displayTimestamp();
	displayInfo("index", _accountIndex, 1);
	displayInfo("amount", _amount, 1);
	std::cout << "closed" << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t		*timestamp;
	struct std::tm	*datetime;
	char			output[17];

	std::time(timestamp);
	datetime = std::localtime(timestamp);
	std::strftime(output, 17, "[%Y%m%d_%H%M%S] ", datetime);
	std::cout << output;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	displayInfo("accounts", _nbAccounts, 1);
	displayInfo("total", _totalAmount, 1);
	displayInfo("deposits", _totalNbDeposits, 1);
	displayInfo("withdrawals", _totalNbWithdrawals, 0);
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	displayInfo("index", _accountIndex, 1);
	displayInfo("p_amount", _amount, 1);
	displayInfo("deposit", deposit, 1);
	_amount += deposit;
	displayInfo("amount", _amount, 1);
	_nbDeposits++;
	displayInfo("nb_deposits", _nbDeposits, 0);
	std::cout << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	displayInfo("index", _accountIndex, 1);
	displayInfo("p_amount", _amount, 1);
	if (_amount < withdrawal)
	{
		std::cout << "withdrawal:" << "refused" << std::endl;
		return (false);
	}
	displayInfo("withdrawal", withdrawal, 1);
	_amount -= withdrawal;
	displayInfo("amount", _amount, 1);
	_nbWithdrawals++;
	displayInfo("", _nbWithdrawals, 0);
	std::cout << std::endl;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}
int		Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	displayInfo("index", _accountIndex, 1);
	displayInfo("amount", _amount, 1);
	displayInfo("deposits", _nbDeposits, 1);
	displayInfo("withdrawals", _nbWithdrawals, 0);
	std::cout << std::endl;
}
