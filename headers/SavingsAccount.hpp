#ifndef OOP_SAVINGSACCOUNT_HPP
#define OOP_SAVINGSACCOUNT_HPP

#include "Account.hpp"

class SavingsAccount: public Account {
public:
    //Constructorul clasei SavingsAccount
    SavingsAccount(const std::string & accountNumber, double balance, Bank * bank);
    // Destructorul clasei SavingsAccount
    ~SavingsAccount() override;
    void update() override;
    Account * clone() const override;
};

#endif //OOP_SAVINGSACCOUNT_HPP