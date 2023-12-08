//
// Created by George on 12/8/2023.
//

#ifndef OOP_ACCOUNT_HPP
#define OOP_ACCOUNT_HPP


#include <iostream>
#include "Exception.hpp"

class Account {
private:
    int accountNumber;
    double balance;
    static int totalAccounts;

public:
    Account(int accountNumber, double balance);

    //virtual void performOperation() const = 0;
    virtual void displayInfo() const = 0;

    int getAccountNumber() const;
    double getBalance() const;

    static void displayTotalAccounts();
    //static int getTotalAccounts();
    static void incrementTotalAccounts();

    void deposit(double amount);
    void withdraw(double amount);

    //virtual Account* clone() const = 0;
};


#endif //OOP_ACCOUNT_HPP
