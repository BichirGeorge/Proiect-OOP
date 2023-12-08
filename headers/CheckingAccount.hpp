//
// Created by George on 12/8/2023.
//

#ifndef OOP_CHECKINGACCOUNT_HPP
#define OOP_CHECKINGACCOUNT_HPP

#include "Account.hpp"

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accountNumber, double balance, double overdraftLimit);

    //void performOperation() const override;
    void displayInfo() const override;


    //CheckingAccount* clone() const override;

    ~CheckingAccount();
};


#endif //OOP_CHECKINGACCOUNT_HPP
