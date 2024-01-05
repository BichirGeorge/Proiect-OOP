#include "../headers/Bank.hpp"

#include <algorithm>

#include <iostream>

Bank::Bank(const std::string & name): name(name) {}

Bank::~Bank() {
    for (Account * account: accounts) {
        delete account;
    }
}

void Bank::addAccount(Account * account) {
    if (accountExists(account -> getAccountNumber())) {
        std::cout << "An account with the same account number already exists. Cannot add the account.\n";
    } else
        accounts.push_back(account);
}

void Bank::removeAccount(const std::string & accountNumber) {
    auto it = std::remove_if(accounts.begin(), accounts.end(),
                             [accountNumber](Account * account) {
                                 return account -> getAccountNumber() == accountNumber;
                             });

    accounts.erase(it, accounts.end());
}

void Bank::displayAccounts() const {
    std::cout << "Bank Name: " << name << "\n";
    for (const auto & account: accounts) {
        std::cout << * account << "\n";
    }
}

void Bank::notifyClients() {
    for (const auto & account: accounts) {
        if (account -> isSubscribed()) {
            account -> update();
        }
    }
}

bool Bank::accountExists(const std::string & accountNumber) const {
    // Verifica daca exista un cont cu acelasi numar
    for (const auto & account: accounts) {
        if (account -> getAccountNumber() == accountNumber) {
            return true;
        }
    }
    return false;
}

void Bank::subscribeAccount(const std::string & accountNumber) {
    for (const auto & account: accounts) {
        if (account -> getAccountNumber() == accountNumber) {
            account -> subscribe();
            std::cout << "Account subscribed to notifications.\n";
            return;
        }
    }
    std::cout << "Account not found.\n";
}

void Bank::unsubscribeAccount(const std::string & accountNumber) {
    for (const auto & account: accounts) {
        if (account -> getAccountNumber() == accountNumber) {
            account -> unsubscribe();
            std::cout << "Account unsubscribed from notifications.\n";
            return;
        }
    }
    std::cout << "Account not found.\n";
}