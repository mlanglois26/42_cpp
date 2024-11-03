/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:50:36 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/01 12:08:19 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    
    _accountIndex = _nbAccounts++;
    _totalAmount += initial_deposit;

    Account::_displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
};

Account::~Account() {
    
    Account::_displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
};

void Account::_displayTimestamp( void ) {
    
    std::time_t now = std::time(NULL);
    std::tm* localTime = std::localtime(&now);
    std::cout << "[" 
              << (localTime->tm_year + 1900)          
              << std::setw(2) << std::setfill('0') << localTime->tm_mon + 1  
              << std::setw(2) << std::setfill('0') << localTime->tm_mday  
              << "_" 
              << std::setw(2) << std::setfill('0') << localTime->tm_hour     
              << std::setw(2) << std::setfill('0') << localTime->tm_min      
              << std::setw(2) << std::setfill('0') << localTime->tm_sec    
              << "]";
}

void Account::displayAccountsInfos()  {
    
    Account::_displayTimestamp();
    std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus() const {
    
    Account::_displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
    
    Account::_displayTimestamp();
    if (deposit < 0)
        deposit = 0;
    _totalAmount += deposit;
    if (deposit > 0) {
        
        _nbDeposits += 1;
        _totalNbDeposits += 1;
    }
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";amount:" << _amount + deposit << ";nb_deposits:" << _nbDeposits << std::endl;
    _amount += deposit;
}

bool Account::makeWithdrawal(int withdrawal) {
    
    Account::_displayTimestamp();
    if (withdrawal < 0 || withdrawal > _amount) {  
        
        withdrawal = 0;
        std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
    }
    else {
        
        _nbWithdrawals += 1;
        std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal << ";amount:" << _amount - withdrawal << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        _totalNbWithdrawals += 1;
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
    }
    return (0);
}
