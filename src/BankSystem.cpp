#include "../headers/BankSystem.hpp"

#include "../headers/SavingsAccount.hpp"

#include "../headers/CurrentAccount.hpp"

#include <iostream>

BankSystem & BankSystem::getInstance() {
    static BankSystem instance;
    return instance;
}

BankSystem::BankSystem(): bank("MyBank") {}

BankSystem::~BankSystem() {
    // Destructor
}

void BankSystem::run() {
    while (true) {
        std::cout << "1. Add Savings Account\n";
        std::cout << "2. Add Current Account\n";
        std::cout << "3. Display Accounts\n";
        std::cout << "4. Remove Account\n";
        std::cout << "5. Notify Clients\n";
        std::cout << "6. Subscribe Account\n";
        std::cout << "7. Unsubscribe Account\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string accountNumber;
                double balance;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter initial balance: ";
                std::cin >> balance;

                SavingsAccount * savingsAccount = new SavingsAccount(accountNumber, balance, & bank);
                bank.addAccount(savingsAccount);
                break;
            }
            case 2: {
                std::string accountNumber;
                double balance;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter initial balance: ";
                std::cin >> balance;

                CurrentAccount * currentAccount = new CurrentAccount(accountNumber, balance, & bank);
                bank.addAccount(currentAccount);
                break;
            }
            case 3:
                bank.displayAccounts();
                break;
            case 4: {
                std::string accountNumber;
                std::cout << "Enter account number to remove: ";
                std::cin >> accountNumber;
                bank.removeAccount(accountNumber);
                break;
            }
            case 5:
                bank.notifyClients();
                std::cout << "Clients notified.\n";
                break;
            case 6: {
                std::string accountNumber;
                std::cout << "Enter account number to subscribe: ";
                std::cin >> accountNumber;
                bank.subscribeAccount(accountNumber);
                break;
            }
            case 7: {
                std::string accountNumber;
                std::cout << "Enter account number to unsubscribe: ";
                std::cin >> accountNumber;
                bank.unsubscribeAccount(accountNumber);
                break;
            }
            case 8:
                std::cout << "Exiting program\n";
                return;
            default:
                std::cout << "Invalid choice\n";
        }
    }
}