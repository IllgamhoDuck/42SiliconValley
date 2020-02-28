/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:51:35 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 18:09:19 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.class.hpp"

//Constructor
Account::Account( int initial_deposit ) {
	// Initialize the account
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	// Class variable
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;

	// Print the timestamp
	Account::_displayTimestamp();

	// Print the log related to account
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

//Destructor
Account::~Account( void ) {

	// Reduce the account number
	Account::_nbAccounts -= 1;

	// Print the timestamp
	Account::_displayTimestamp();

	// Print the log related to account
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
	return ;
}

// static variables initialize
int			Account::_nbAccounts = 0;
int			Account::_totalAmount = 0;
int			Account::_totalNbDeposits = 0;
int			Account::_totalNbWithdrawals = 0;

int			Account::nbCheckAmountCalled = 0; // bonus
int			&Account::rnbCheckAmountCalled = Account::nbCheckAmountCalled;

// Static functions
int			Account::getNbAccounts( void ) {

	return Account::_nbAccounts;
}

int			Account::getTotalAmount( void ) {

	return Account::_totalAmount;
}

int			Account::getNbDeposits( void ) {

	return Account::_totalNbDeposits;
}

int			Account::getNbWithdrawals( void ) {

	return Account::_totalNbWithdrawals;
}

// timestamp
void		Account::_displayTimestamp( void ) {

	std::time_t now = time(0);
	tm *ltm = localtime(&now);

	std::cout << "[";
	std::cout << 1900 + ltm->tm_year;
	std::cout << std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon;
	std::cout << std::setw(2) << std::setfill('0') << ltm->tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0') << 1 + ltm->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << 1 + ltm->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << 1 + ltm->tm_sec;
	std::cout << "]";
}


// account infos

void		Account::displayAccountsInfos( void ) {

	// Print the timestamp
	Account::_displayTimestamp();

	// Print the log related to account
	std::cout << " accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals();
	std::cout << std::endl;
	return ;
}

// functions modify account deposit and withdrawal
void		Account::makeDeposit( int deposit ) {

	// Print the timestamp
	Account::_displayTimestamp();

	// Print the log before deposit
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->checkAmount() << ";";

	// Print the amount of deposit that user will make this moment
	std::cout << "deposit:" << deposit << ";";

	// Change the class variable
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;

	// Change instance variable
	this->_nbDeposits += 1;
	this->_amount += deposit;

	// Print the log after deposit
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
	return ;
}

bool		Account::makeWithdrawal( int withdrawal ) {

	// Print the timestamp
	Account::_displayTimestamp();

	// Print the log before withdrawal
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->checkAmount() << ";";

	// check is it possible to withdraw
	if (this->checkAmount() < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}

	// Print the amount of deposit that user will make this moment
	std::cout << "withdrawal:" << withdrawal << ";";

	// Change the class variable
	Account::_totalNbWithdrawals += 1;
	Account::_totalAmount -= withdrawal;

	// Change instance variable
	this->_nbWithdrawals += 1;
	this->_amount -= withdrawal;

	// Print the log after successful withdrawal
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

int			Account::checkAmount( void ) const {

	Account::rnbCheckAmountCalled += 1;
	return this->_amount;
}

void		Account::displayStatus( void ) const {

	// Print the timestamp
	Account::_displayTimestamp();

	// Print the log related to account
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
	return ;
}

