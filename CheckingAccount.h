/* Assignment C++: 2
   Author: Ido Shwartz, ID: 318732856
   Author: Ron Milutin, ID: 316389584
*/
#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Account.h"

// Concrete class representing a checking account
class CheckingAccount : public Account {
private:
    double overdraftLimit;  // Overdraft limit for the checking account

public:
    // Constructor
    CheckingAccount(const string& number, const string& holder, double initialBalance, double overdraft);

    // Destructor
    ~CheckingAccount();

    // Method to deposit money into the account
    void deposit(double amount) override;

    // Method to withdraw money from the account
    void withdraw(double amount) override;

    // Method to get the account type
    char getAccountType() const override;

};

#endif // CHECKING_ACCOUNT_H

