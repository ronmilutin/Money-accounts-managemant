/* Assignment C++: 2
   Author: Ido Shwartz, ID: 318732856
   Author: Ron Milutin, ID: 316389584
*/
#ifndef MENU_H
#define MENU_H

#include "Array.h"
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

class Menu {
private:
    Array<Account*> bankAccounts;

public:
    Menu();
    ~Menu();

    void mainMenu();
    void addNewAccount();
    void depositToAccount();
    void withdrawFromAccount();
    void deleteAccount();
    void printAccountDetails();
    void exeption(int error) const;
};

#endif // MENU_H
