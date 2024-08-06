#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

class Account
{
private:
    static int m_no0fAccounts; // Total number of Accounts

    static int m_totalAmount; // Total Account Amount

    static int m_totalNbDeposits; // total number of depositis

    static int m_totalNbWithdrawals; // total number of Withdrawals

    static void m_displayTimestamp(void);

    int m_accountIndex; // Account index

    int m_amount; // Current amount deposite or withdrawal

    int m_no0fDeposits; // current number of depositis

    int m_noofWithdrawals; // current number of Withdrawals

    Account(void);

public:
    using acc = Account;

    static int getNoOfAccounts(void);

    static int getTotalAmount(void);

    static int getNbDeposits(void);

    static int getNoOfWithdrawals(void);

    static void displayAccountsInfos(void);

    Account(int initial_deposit);

    ~Account(void);

    void makeDeposit(int deposit);

    bool makeWithdrawal(int withdrawal);

    int checkAmount(void) const;

    void displayStatus(void) const;
};

#endif