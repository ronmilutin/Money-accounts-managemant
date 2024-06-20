/* Assignment C++: 2
   Author: Ido Shwartz, ID: 318732856
   Author: Ron Milutin, ID: 316389584
*/
#include "CheckingAccount.h"
using namespace std;

// Constructor implementation
CheckingAccount::CheckingAccount(const string& number, const string& holder, double initialBalance, double overdraft)
        : Account(number, holder, initialBalance), overdraftLimit(overdraft) {}

// Destructor implementation
CheckingAccount::~CheckingAccount() {}

// Method to deposit money into the account
void CheckingAccount::deposit(double amount) {
    if (amount > 0) balance += amount;  // Increase the balance by the deposited amount
    else throw (4);
}

// Method to withdraw money from the account
void CheckingAccount::withdraw(double amount) {
    // Check if the withdrawal amount exceeds the available balance plus overdraft limit
    if (amount <= 0) throw(5);
    else if (amount > balance + overdraftLimit) throw (2);
    else balance -= amount; // Deduct the withdrawal amount from the balance
}

// Method to get the account type
char CheckingAccount::getAccountType() const {
    return 'c';
}
