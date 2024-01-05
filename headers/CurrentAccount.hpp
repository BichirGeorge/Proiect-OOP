#ifndef OOP_CURRENTACCOUNT_HPP
#define OOP_CURRENTACCOUNT_HPP

#include "Account.hpp"

class CurrentAccount: public Account {
public:
    //Constructorul clasei CurrentAccount
    CurrentAccount(const std::string & accountNumber, double balance, Bank * bank);
    // CurrentAccount nu primeste dobanda
    void update() override;
    //Cloneaza
    Account * clone() const override;
};

#endif //OOP_CURRENTACCOUNT_HPP