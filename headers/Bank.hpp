//
// Created by George on 12/8/2023.
//

#ifndef OOP_BANK_HPP
#define OOP_BANK_HPP

#include <iostream>
#include <vector>
#include <memory>
#include "Person.hpp"
#include "Account.hpp"
#include "CheckingAccount.hpp"
#include "SavingsAccount.hpp"
#include "CreditAccount.hpp"

class Bank {
private:
    std::string name;
    std::vector<std::unique_ptr<Account>> accounts;

public:
    Bank(const std::string& name);

    void createSavingsAccount(const Person& person, double balance, double interestRate);
    void createCheckingAccount(const Person& person, double balance, double overdraftLimit);
    void createCreditAccount(const Person& person, double balance, double creditLimit);

    void displayAllAccounts() const;

    void deposit(int accountNumber, double amount);

    void withdraw(int accountNumber, double amount);

    void displayAccountInfo(int accountNumber) const;
};



#endif //OOP_BANK_HPP
