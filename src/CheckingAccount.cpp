//
// Created by George on 12/8/2023.
//

#include "../headers/CheckingAccount.hpp"

CheckingAccount::CheckingAccount(int accountNumber, double balance, double overdraftLimit)
        : Account(accountNumber, balance), overdraftLimit(overdraftLimit) {
}

void CheckingAccount::performOperation() const {
    std::cout << "----\n";
}


void CheckingAccount::displayInfo() const {
    std::cout << "Checking Account Information\n";
    std::cout << "Account Number: " << getAccountNumber() << "\n";
    std::cout << "Balance: " << getBalance() << "\n";
    std::cout << "Overdraft Limit: " << overdraftLimit << "\n";
}

CheckingAccount* CheckingAccount::clone() const {
    return new CheckingAccount(*this);
}

CheckingAccount::~CheckingAccount() = default;