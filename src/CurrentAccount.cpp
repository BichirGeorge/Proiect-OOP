#include "../headers/CurrentAccount.hpp"


CurrentAccount::CurrentAccount(const std::string & accountNumber, double balance, Bank * bank): Account(accountNumber, balance, bank) {}

void CurrentAccount::update() {
    std::cout << "Current Account updated.\n";
}

Account * CurrentAccount::clone() const {
    return new CurrentAccount( * this);
}