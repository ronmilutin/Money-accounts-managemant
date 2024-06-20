/* Assignment C++: 2
   Author: Ido Shwartz, ID: 318732856
   Author: Ron Milutin, ID: 316389584
*/
#include "Account.h"

// Constructor implementation
Account::Account(const string& number, const string& holder, double initialBalance)
        : accountNumber(number), accountHolderName(holder), balance(initialBalance) {}

// Method to get the current balance
double Account::getBalance() const {
    return balance;
}


// Method to get the account number
string Account::getAccountNumber() const {
    return accountNumber;
}


// Method to get the holder name
string Account::getHolderName() const {
    return accountHolderName;
}

// Overloaded << operator for printing the account details
ostream& operator<<(ostream& os, const Account& acc) {
    os << "Account Number: " << acc.accountNumber << endl
       << "Account Holder: " << acc.accountHolderName << endl
       << "Balance: $" << acc.balance;
    return os;
}

