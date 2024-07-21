#include "Account.hpp"
#include <iostream>
#include <ctime>

// Static member variable definitions
int Account::m_no0fAccounts = 0;
int Account::m_totalAmount = 0;
int Account::m_totalNbDeposits = 0;
int Account::m_totalNbWithdrawals = 0;

// Private static member function to display timestamp
void Account::m_displayTimestamp()
{
    std::time_t now = std::time(nullptr);
    std::cout << "Timestamp: " << std::asctime(std::localtime(&now));
}

Account::Account()
    : m_accountIndex(m_no0fAccounts + 1), // Assign unique account index
      m_amount(0),
      m_no0fDeposits(0),
      m_noofWithdrawals(0)
{
    m_no0fAccounts++; // Increment the total number of accounts
}

// Public static member functions

int Account::getNoOfAccounts()
{
    return m_no0fAccounts;
}

int Account::getTotalAmount()
{
    return m_totalAmount;
}

int Account::getNbDeposits()
{
    return m_totalNbDeposits;
}

int Account::getNoOfWithdrawals()
{
    return m_totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
    m_displayTimestamp();
    std::cout << "Total number of accounts: " << m_no0fAccounts << std::endl;
    std::cout << "Total amount across all accounts: " << m_totalAmount << std::endl;
    std::cout << "Total number of deposits: " << m_totalNbDeposits << std::endl;
    std::cout << "Total number of withdrawals: " << m_totalNbWithdrawals << std::endl;
}

// Constructor with initial deposit
Account::Account(int initial_deposit)
    : m_accountIndex(m_no0fAccounts + 1),
      m_amount(initial_deposit),
      m_no0fDeposits(1), // Initial deposit counts as a deposit
      m_noofWithdrawals(0)
{
    m_no0fAccounts++;
    m_totalAmount += initial_deposit;
    m_totalNbDeposits++;
}

// Destructor
Account::~Account()
{
    m_no0fAccounts--;
}

// Member function to make a deposit
void Account::makeDeposit(int deposit)
{
    m_amount += deposit;
    m_no0fDeposits++;
    m_totalAmount += deposit;
    m_totalNbDeposits++;
}

// Member function to make a withdrawal
bool Account::makeWithdrawal(int withdrawal)
{
    if (m_amount >= withdrawal)
    {
        m_amount -= withdrawal;
        m_noofWithdrawals++;
        m_totalAmount -= withdrawal;
        m_totalNbWithdrawals++;
        return true;
    }
    else
    {
        std::cout << "Insufficient funds!" << std::endl;
        return false;
    }
}

// Member function to check current amount
int Account::checkAmount() const
{
    return m_amount;
}

// Member function to display account status
void Account::displayStatus() const
{
    std::cout << "Account Index: " << m_accountIndex << std::endl;
    std::cout << "Current Amount: " << m_amount << std::endl;
    std::cout << "Number of Deposits: " << m_no0fDeposits << std::endl;
    std::cout << "Number of Withdrawals: " << m_noofWithdrawals << std::endl;
}
int main()
{
    // Creating accounts
    Account acc1(1000); // Initial deposit of 1000
    Account acc2(500);  // Initial deposit of 500

    // Making transactions
    acc1.makeDeposit(500);
    acc2.makeWithdrawal(200);

    // Displaying account status
    std::cout << "Account 1 status:" << std::endl;
    acc1.displayStatus();
    std::cout << std::endl;

    std::cout << "Account 2 status:" << std::endl;
    acc2.displayStatus();
    std::cout << std::endl;

    // Displaying overall account information
    std::cout << "Overall Account Information:" << std::endl;
    Account::displayAccountsInfos();

    return 0;
}
