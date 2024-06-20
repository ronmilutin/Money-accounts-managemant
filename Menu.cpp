/* Assignment C++: 2
   Author: Ido Shwartz, ID: 318732856
   Author: Ron Milutin, ID: 316389584
*/
#include "Menu.h"
#include <iostream>

using namespace std;

// Constructor
Menu::Menu() {}

// Destructor
Menu::~Menu() {
    // Release dynamically allocated account memory
    for (int i = 0; i < bankAccounts.getSize(); ++i) {
        delete bankAccounts[i];
    }
}

// Main menu function
void Menu::mainMenu() {
    int choice;

    do {
        // Display main menu options
        cout << "====== Main Menu ======" << endl;
        cout << "1 - Add a new account" << endl;
        cout << "2 - Deposit (index, amount)" << endl;
        cout << "3 - Withdraw (index, amount)" << endl;
        cout << "4 - Delete an account (index)" << endl;
        cout << "5 - Print details of all accounts" << endl;
        cout << "6 - Exit" << endl;
        cout << "=======================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            // Switch statement to handle user choices
            switch (choice) {
                case 1:
                    addNewAccount();
                    break;
                case 2:
                    depositToAccount();
                    break;
                case 3:
                    withdrawFromAccount();
                    break;
                case 4:
                    deleteAccount();
                    break;
                case 5:
                    printAccountDetails();
                    break;
                case 6:
                    cout << "Exiting the program." << endl;
                    break;
                default:
                    throw (1);
            }
        } catch (int error) {
            // Catch exceptions and display an error message
            exeption(error);
        }

    } while (choice != 6);  // Repeat until the user chooses to exit
}

// Function to add a new account
void Menu::addNewAccount() {
    char choice;
    string accountNumber, accountHolder;
    double initialBalance, overdraft;

    // Gather user input for new account details
    cout << "Enter account number: ";
    cin >> accountNumber;
    cout << "Enter account holder name: ";
    cin >> accountHolder;
    cout << "Enter initial balance: ";
    cin >> initialBalance;
    cout << "Enter account type (S for Savings, C for Checking): ";
    cin >> choice;

    try {
        // Switch statement to handle different account types
        switch (choice) {
            case 'S':
            case 's': {
                double annualRate;
                cout << "Enter annual interest rate: ";
                cin >> annualRate;
                if (annualRate<0) throw (-1);
                // Add a new SavingsAccount to the bankAccounts collection
                bankAccounts.add(new SavingsAccount(accountNumber, accountHolder, initialBalance, annualRate));
                cout << "Account added successfully." << endl;
                break;
            }
            case 'C':
            case 'c': {
                cout << "Enter overdraft limit: ";
                cin >> overdraft;
                // Add a new CheckingAccount to the bankAccounts collection
                bankAccounts.add(new CheckingAccount(accountNumber, accountHolder, initialBalance, overdraft));
                cout << "Account added successfully." << endl;
                break;
            }
            default:
                // Throw an exception for invalid account type
                throw (6);
                //break;
        }
    } catch (int error) {
        // Catch exceptions
        exeption(error);
    }
}

// Function to deposit to an account
void Menu::depositToAccount() {
    int index;
    double amount;

    // Gather user input for account index and deposit amount
    cout << "Enter account index to deposit: ";
    cin >> index;

    try {
        // Check if the account index is valid
        if (index < 0 || index >= bankAccounts.getSize()) {
            // Throw an exception for an invalid account index
            throw (1);
        }

        cout << "Enter deposit amount: ";
        cin >> amount;

        // Call the deposit method for the selected account
        bankAccounts[index]->deposit(amount);
        //cout <<  *bankAccounts[index] << endl << endl;
        cout << "Account Number: " << bankAccounts[index]->getAccountNumber() << endl;
        cout << "Account Holder: " << bankAccounts[index]->getHolderName() << endl;
        cout << "New Balance: $" << bankAccounts[index]->getBalance() << endl << endl;

        cout <<  *bankAccounts[index] << endl;
    } catch (int error) {
        // Catch exceptions and display a generic error message
        exeption(error);
    }
}

// Function to withdraw from an account
void Menu::withdrawFromAccount() {
    int index;
    double amount;

    // Gather user input for account index and withdrawal amount
    cout << "Enter account index to withdraw from: ";
    cin >> index;

    try {
        // Check if the account index is valid

        if (index < 0 || index >= bankAccounts.getSize()) {
            // Throw an exception for an invalid account index
            throw (1);
        }

        cout << "Enter withdrawal amount: ";
        cin >> amount;

        // Call the withdraw method for the selected account
        bankAccounts[index]->withdraw(amount);
        cout << "Withdrawn $" << amount << endl << endl;
        cout <<  *bankAccounts[index] << endl;
    }
    catch (int error) {
        // Catch exceptions and display an error message
        exeption(error);
    }
}

// Function to delete an account
void Menu::deleteAccount() {
    int index;

    // Gather user input for account index to delete
    cout << "Enter account index to delete: ";
    cin >> index;

    try {
        // Check if the account index is valid
        if (index < 0 || index >= bankAccounts.getSize()) {
            // Throw an exception for an invalid account index
            throw (1);
        }

        // Delete the selected account and remove it from the collection
        delete bankAccounts[index];
        bankAccounts.remove(index);

        cout << "Account deleted successfully." << endl;
    } catch (int error) {
        // Catch exceptions and display a generic error message
        //cout << "Error: Index out of range." << endl;
        exeption(error);
    }
}

// Function to print details of all accounts
void Menu::printAccountDetails(){
    cout << "====== Account Details ======" << endl;
    // Iterate through the bankAccounts collection and print details for each account
    for (int i = 0; i < bankAccounts.getSize(); ++i) {

        // Update the interest
        if (bankAccounts[i]->getAccountType()=='s'){
            bankAccounts[i]->deposit(0);
        }
        cout << "Array index " << i << ": " << endl << *bankAccounts[i] << endl << endl;
    }
}

void Menu::exeption(int error) const {
    switch(error) {
        case 1: {
            cout << "Error: Index out of range." << endl;
            break;
        }
        case 2: {
            cout << "Error: Withdrawal amount exceeds available funds." << endl;
            break;
        }
        case 3: {
            cout << "Error: Insufficient funds." << endl;
            break;
        }
        case 4: {
            cout << "Error: Deposit amount must be positive." << endl;
            break;
        }
        case 5: {
            cout << "Error: Withdrawal amount must be positive." << endl;
            break;
        }
        case 6:{
            cout << "Error: Invalid account type." << endl;
            break;
        }
        default: {
            cout << "Other error." << endl;
            break;
        }
    }
}

