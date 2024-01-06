#ifndef OOP_ACCOUNTFACTORY_HPP
#define OOP_ACCOUNTFACTORY_HPP

#include "Account.hpp"
#include "SavingsAccount.hpp"
#include "CurrentAccount.hpp"

class AccountFactory {
public:
    // Creeaza un cont de tipul specificat
    static Account* createAccount(const std::string& accountNumber, double balance, Bank* bank, const std::string& accountType);
};

#endif //OOP_ACCOUNTFACTORY_HPP
