//
// Created by George on 12/8/2023.
//

#include "../headers/CreditAccount.hpp"

CreditAccount::CreditAccount(int accountNumber, double balance, double creditLimit)
        : Account(accountNumber, balance), creditLimit(creditLimit) {
}

//void CreditAccount::performOperation() const {
//    std::cout << "----\n";
//}

//void CreditAccount::useCredit(double amount) {
//    if (amount < 0) {
//        throw NegativeAmountException("Credit usage amount must be non-negative.");
//    }
//    if (getBalance() + creditLimit >= amount) {
//        deposit(amount);
//        std::cout << "Credit used successfully!\n";
//    } else {
//        throw CreditLimitExceededException("Credit limit exceeded. Transaction failed.");
//    }
//}

void CreditAccount::displayInfo() const {
    std::cout << "Credit Account Information\n";
    std::cout << "Account Number: " << getAccountNumber() << "\n";
    std::cout << "Balance: " << getBalance() << "\n";
    std::cout << "Credit Limit: " << creditLimit << "\n";
}

//CreditAccount* CreditAccount::clone() const {
//    return new CreditAccount(*this);
//}

CreditAccount::~CreditAccount() = default;
