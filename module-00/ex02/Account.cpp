/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 21:45:18 by proberto          #+#    #+#             */
/*   Updated: 2022/08/13 00:06:51 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts			= 0;
int Account::_totalAmount			= 0;
int Account::_totalNbDeposits		= 0;
int Account::_totalNbWithdrawals	= 0;

Account::Account() {}

Account::Account(int initial_deposit) : _amount(initial_deposit){
	_accountIndex = _nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout
		<< "index:"		<< _accountIndex
		<< ";amount:"	<< checkAmount()
		<< ";created"	<< std::endl;
}

Account::~Account() {
	_displayTimestamp();
	std::cout
		<< "index:"		<< _accountIndex
		<< ";amount:"	<< checkAmount()
		<< ";closed"	<< std::endl;
}

int	Account::checkAmount(void) const {
	return _amount;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout
		<< "index:"			<< _accountIndex
		<< ";p_amount:"		<< checkAmount();
	if (deposit <= 0) {
		std::cout << ";deposit:refused" << std::endl;
		return;
	}
	_nbDeposits++;
	std::cout
		<< ";deposit:"		<< deposit
		<< ";amount:"		<< _amount + deposit
		<< ";nb_deposits:"	<< _nbDeposits
		<< std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout
		<< "index:"				<< _accountIndex
		<< ";p_amount:"			<< checkAmount();
	if (withdrawal > checkAmount()) {
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	_nbWithdrawals++;
	std::cout
		<< ";withdrawal:"		<< withdrawal
		<< ";amount:"			<< _amount - withdrawal
		<< ";nb_withdrawals:"	<< _nbWithdrawals
		<< std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return true;
}

int Account::getNbAccounts(void) {
	return _nbAccounts;
}

int Account::getTotalAmount(void) {
	return _totalAmount;
}

int Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void Account::_displayTimestamp(void) {
	std::time_t currentTime;
	std::tm *localtime;
	char buffer[16];
	
	std::time(&currentTime);
	localtime = std::localtime(&currentTime);
	std::strftime(buffer, 16, "%Y%m%d_%I%M%S", localtime);
	std::cout << "[" << buffer << "] ";
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout
		<< "accounts:"		<< getNbAccounts()
		<< ";total:"		<< getTotalAmount()
		<< ";deposits:"		<< getNbDeposits()
		<< ";withdrawals:"	<< getNbWithdrawals()
		<< std::endl;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout
		<< "index:"			<< _accountIndex
		<< ";amount:"		<< _amount
		<< ";deposits:"		<< _nbDeposits
		<< ";withdrawals:"	<< _nbWithdrawals
		<< std::endl;
}
