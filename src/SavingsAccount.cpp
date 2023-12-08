//
// Created by George on 12/8/2023.
//

#include "../headers/SavingsAccount.hpp"

SavingsAccount::SavingsAccount(int accountNumber, double balance, double interestRate)
        : Account(accountNumber, balance), interestRate(interestRate) {
}

void SavingsAccount::performOperation() const {
    std::cout << "----\n";
}

void SavingsAccount::calculateInterest() {
    double interest = getBalance() * interestRate / 100.0;
    deposit(interest);
}

void SavingsAccount::displayInfo() const {
    std::cout << "Savings Account Information\n";
    std::cout << "Account Number: " << getAccountNumber() << "\n";
    std::cout << "Balance: " << getBalance() << "\n";
    std::cout << "Interest Rate: " << interestRate << "%\n";
}

SavingsAccount* SavingsAccount::clone() const {
    return new SavingsAccount(*this);
}

SavingsAccount::~SavingsAccount() = default;