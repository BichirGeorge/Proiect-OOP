//
// Created by George on 12/8/2023.
//

#include "../headers/Account.hpp"
Account::Account(int accountNumber, double balance)
        : accountNumber(accountNumber), balance(balance) {
}

int Account::getAccountNumber() const{
    return accountNumber;
}

double Account::getBalance() const{
    return balance;
}

void Account::deposit(double amount){
    if (amount < 0) {
        throw NegativeAmountException("Deposit amount must be non-negative.");
    }
    balance += amount;
}

int Account::totalAccounts = 0;

void Account::displayTotalAccounts(){
    std::cout << "Total number of accounts: " << totalAccounts << "\n";
}
int Account::getTotalAccounts(){
    return totalAccounts;
}

void Account::incrementTotalAccounts(){
    totalAccounts++;
}

void Account::withdraw(double amount){
    if (amount < 0) {
        throw NegativeAmountException("Withdrawal amount must be non-negative.");
    }
    if (balance < amount) {
        throw InsufficientFundsException("Insufficient funds for withdrawal.");
    }
    balance -= amount;
}