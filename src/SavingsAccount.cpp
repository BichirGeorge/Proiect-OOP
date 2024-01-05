#include "../headers/SavingsAccount.hpp"


SavingsAccount::SavingsAccount(const std::string & accountNumber, double balance, Bank * bank): Account(accountNumber, balance, bank) {}

void SavingsAccount::update() {
    double interestRate = 0.05;
    balance += balance * interestRate;
    std::cout << "Savings Account updated.\n";
}

Account * SavingsAccount::clone() const {
    return new SavingsAccount( * this);
}

SavingsAccount::~SavingsAccount() {

}