/* Assignment C++: 2
   Author: Ido Shwartz, ID: 318732856
   Author: Ron Milutin, ID: 316389584
*/
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <cstring>
#include <iostream>
using namespace std;

// Abstract base class for representing an account
class Account {
protected:
    string accountNumber;       // Account number
    string accountHolderName;   // Name of the account holder
    double balance;             // Current balance

public:
    // Constructor
    Account(const string& number, const string& holder, double initialBalance);

    // Virtual destructor
    virtual ~Account() {}

    // Pure virtual methods
    virtual void deposit(double amount) = 0;        // Deposit money into the account
    virtual void withdraw(double amount) = 0;       // Withdraw money from the account
    virtual char getAccountType() const = 0;        // Get the account type
    double getBalance() const;                      // Get the current balance
    string getAccountNumber() const;                // Method to get the account number
    string getHolderName() const;                   // Method to get the holder name

    // Overloaded << operator for printing the account details
    friend ostream& operator<<(ostream& os, const Account& acc);
};

#endif // ACCOUNT_H
