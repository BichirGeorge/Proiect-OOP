//
// Created by George on 12/8/2023.
//

#ifndef OOP_SAVINGSACCOUNT_HPP
#define OOP_SAVINGSACCOUNT_HPP


#include "Account.hpp"

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int accountNumber, double balance, double interestRate);

    void performOperation() const override;
    void displayInfo() const override;

    void calculateInterest();

    SavingsAccount* clone() const override;

    ~SavingsAccount();
};

#endif //OOP_SAVINGSACCOUNT_HPP
