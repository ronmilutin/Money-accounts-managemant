/* Assignment C++: 2
   Author: Ido Shwartz, ID: 318732856
   Author: Ron Milutin, ID: 316389584
*/
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"
#include <chrono>

using namespace std;

class SavingsAccount : public Account {
private:
    double annualInterestRate;
    chrono::steady_clock::time_point lastTransactionTime;

    // Method to update interest based on time passed since the last transaction
    void updateInterest();

public:
    // Constructor
    SavingsAccount(const string& number, const string& holder, double initialBalance, double annualRate);

    // Destructor
    ~SavingsAccount() override;

    // Deposit method
    void deposit(double amount) override;

    // Withdraw method
    void withdraw(double amount) override;

    // Method to get the account type
    char getAccountType() const override;

};

#endif // SAVINGSACCOUNT_H