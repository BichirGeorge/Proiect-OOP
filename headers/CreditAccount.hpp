//
// Created by George on 12/8/2023.
//

#ifndef OOP_CREDITACCOUNT_HPP
#define OOP_CREDITACCOUNT_HPP



#include "Account.hpp"

class CreditAccount : public Account {
private:
    double creditLimit;

public:
    CreditAccount(int accountNumber, double balance, double creditLimit);

    //void performOperation() const override;
    void displayInfo() const override;

    //void useCredit(double amount);

    //CreditAccount* clone() const override;

    ~CreditAccount();
};


#endif //OOP_CREDITACCOUNT_HPP
