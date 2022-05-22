#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ): _amount(initial_deposit)
{
    this->_accountIndex = _nbAccounts;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _nbAccounts++;
    _totalAmount += this->_amount;
    _displayTimestamp();
    std::cout << " ";
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;
};

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << " ";
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << std::endl;
};

int Account::getNbAccounts( void )
{
    return (_nbAccounts);
};

int Account::getTotalAmount( void )
{
    return (_totalAmount);
};

int Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
};

int Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
};

void Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << " ";
    std::cout << "accounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
    std::cout << "deposits:" << _totalNbDeposits << ";";
    std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
};

void Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << " ";
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    _totalNbDeposits++;
    _totalAmount += deposit;
    this->_nbDeposits++;
    this->_amount += deposit;
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
};

bool Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << " ";
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    if (this->_amount - withdrawal < 0)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return(true);
};

int	Account::checkAmount( void ) const
{
    return(0);
};

void Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << " ";
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
};

void Account::_displayTimestamp( void )
{
    time_t timer;
    struct tm *timeinfo;

    time(&timer);
    timeinfo = localtime(&timer);
    std::cout << "[" << timeinfo->tm_year + 1900 << timeinfo->tm_mon + 1 << timeinfo->tm_mday << "_";
    std::cout << timeinfo->tm_hour << timeinfo->tm_min << timeinfo->tm_sec << "]";
};