/* Assignment C++: 2
   Author: Ido Shwartz, ID: 318732856
   Author: Ron Milutin, ID: 316389584
*/
#include "SavingsAccount.h"
#include <iostream>
#include <cmath>


using namespace std;

// Constructor implementation
SavingsAccount::SavingsAccount(const string& number, const string& holder, double initialBalance, double annualRate)
        : Account(number, holder, initialBalance), annualInterestRate(annualRate) {
    lastTransactionTime = chrono::steady_clock::now();
}

// Destructor implementation
SavingsAccount::~SavingsAccount() {}

// Deposit method implementation
void SavingsAccount::deposit(double amount) {
    updateInterest(); // Call the function to update interest before depositing
    balance += amount;
    lastTransactionTime = chrono::steady_clock::now(); // Record the time of the transaction
}

// Withdraw method implementation
void SavingsAccount::withdraw(double amount) {
    updateInterest(); // Call the function to update interest before withdrawing
    if (amount <= 0) throw(5);
    else if (amount <= balance) {
        balance -= amount;
        lastTransactionTime = chrono::steady_clock::now(); // Record the time of the transaction
    } else throw(3);

}

// Method to update interest based on time passed since the last transaction
void SavingsAccount::updateInterest() {
    chrono::steady_clock::time_point currentTime = chrono::steady_clock::now();
    chrono::duration<double> timeDifference = chrono::duration_cast<chrono::duration<double>>(currentTime - lastTransactionTime);
    double elapsedTime = timeDifference.count(); // Calculate the time elapsed since the last transaction in seconds

    // Calculate interest earned using the simple interest formula
    double updatedBalance = balance * pow(1 + annualInterestRate, (int)elapsedTime);

    // Update the balance with the calculated interest
    balance = updatedBalance;
}

// Method to get the account type
char SavingsAccount::getAccountType() const {
    return 's';
}
