//
// Created by George on 12/8/2023.
//

#include "../headers/Bank.hpp"

Bank::Bank(const std::string& name)
        : name(name) {
}

void Bank::createSavingsAccount(const Person& person, double balance, double interestRate) {
    std::unique_ptr<Account> account = std::make_unique<SavingsAccount>(accounts.size() + 1, balance, interestRate);
    accounts.push_back(std::move(account));
    std::cout << "Savings Account created successfully for " << person.getFirstName() << " " << person.getLastName() << "!\n";
    Account::incrementTotalAccounts();
}

void Bank::createCheckingAccount(const Person& person, double balance, double overdraftLimit) {
    std::unique_ptr<Account> account = std::make_unique<CheckingAccount>(accounts.size() + 1, balance, overdraftLimit);
    accounts.push_back(std::move(account));
    std::cout << "Checking Account created successfully for " << person.getFirstName() << " " << person.getLastName() << "!\n";
    Account::incrementTotalAccounts();
}

void Bank::createCreditAccount(const Person& person, double balance, double creditLimit) {
    std::unique_ptr<Account> account = std::make_unique<CreditAccount>(accounts.size() + 1, balance, creditLimit);
    accounts.push_back(std::move(account));
    std::cout << "Credit Account created successfully for " << person.getFirstName() << " " << person.getLastName() << "!\n";
    Account::incrementTotalAccounts();
}

void Bank::displayAllAccounts() const {
    std::cout << "Accounts of the bank " << name << ":\n";
    for (const auto& account : accounts) {
        if (auto savingsAccount = dynamic_cast<SavingsAccount*>(account.get())) {
            savingsAccount->displayInfo();
        } else if (auto checkingAccount = dynamic_cast<CheckingAccount*>(account.get())) {
            checkingAccount->displayInfo();
        } else if (auto creditAccount = dynamic_cast<CreditAccount*>(account.get())) {
            creditAccount->displayInfo();
        } else {
            std::cerr << "Unknown account type!\n";
        }
        std::cout << "--------------------------\n";
    }
}

void Bank::deposit(int accountNumber, double amount) {
    for (const auto& account : accounts) {
        if (account->getAccountNumber() == accountNumber) {
            account->deposit(amount);
            return;
        }
    }
    std::cout << "Account not found.\n";
}

void Bank::withdraw(int accountNumber, double amount) {
    for (const auto& account : accounts) {
        if (account->getAccountNumber() == accountNumber) {
            account->withdraw(amount);
            return;
        }
    }
    std::cout << "Account not found.\n";
}

void Bank::displayAccountInfo(int accountNumber) const {
    for (const auto& account : accounts) {
        if (account->getAccountNumber() == accountNumber) {
            account->displayInfo();
            return; // Found the account, no need to continue searching
        }
    }
    std::cout << "Account not found.\n";
}