#include <iostream>
#include "headers/Person.hpp"
#include "headers/Account.hpp"
#include "headers/CheckingAccount.hpp"
#include "headers/SavingsAccount.hpp"
#include "headers/CreditAccount.hpp"
#include "headers/Bank.hpp"
#include "headers/Exception.hpp"

int main() {
    try {
        Bank MazeBank("Maze Bank");
        Person client1("George", "Ionut", "Str. Acadelelor, Nr. 96");
        Person client2("Justin", "Bieber", "Str. Acadelelor, Nr. 96");
        Person client3("Barack", "Obama", "Str. Acadelelor, Nr. 96");
        Person client4("Donald", "Trump", "Str. Acadelelor, Nr. 96");

        MazeBank.createSavingsAccount(client1, 1000.0, 3.0);
        MazeBank.createSavingsAccount(client4, 3000.0, 3.0);
        MazeBank.createCheckingAccount(client2, 2000.0, 500.0);
        MazeBank.createCreditAccount(client3, 1500.0, 2000.0);
        SavingsAccount::displayTotalAccounts();
        int option;

        do {
            std::cout << "\n\nMenu:\n";
            std::cout << "1. Display all accounts\n";
            std::cout << "2. Deposit money\n";
            std::cout << "3. Withdraw money\n";
            std::cout << "4. Display account information\n";
            std::cout << "0. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> option;

            switch (option) {
                case 1:
                    MazeBank.displayAllAccounts();
                    break;
                case 2:
                    int accountNumber;
                    double amount;
                    std::cout << "Enter account number for deposit: ";
                    std::cin >> accountNumber;
                    std::cout << "Enter amount to deposit: ";
                    std::cin >> amount;

                    if (amount < 0) {
                        throw NegativeAmountException("Deposit amount must be non-negative.");
                    }

                    MazeBank.deposit(accountNumber, amount);
                    break;
                case 3:
                    std::cout << "Enter account number for withdrawal: ";
                    std::cin >> accountNumber;
                    std::cout << "Enter amount to withdraw: ";
                    std::cin >> amount;

                    if (amount < 0) {
                        throw NegativeAmountException("Withdrawal amount must be non-negative.");
                    }


                    MazeBank.withdraw(accountNumber, amount);
                    break;
                case 4:
                    int accountNumberInfo;
                    std::cout << "Enter account number for information: ";
                    std::cin >> accountNumberInfo;

                    MazeBank.displayAccountInfo(accountNumberInfo);
                    break;
                case 0:
                    std::cout << "Goodbye!\n";
                    break;
                default:
                    std::cout << "Invalid option. Please try again.\n";
            }
        } while (option != 0);
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
