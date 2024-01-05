#ifndef OOP_BANKSYSTEM_HPP
#define OOP_BANKSYSTEM_HPP

//Implementare Singleton

#include "Bank.hpp"

class BankSystem {
public: static BankSystem & getInstance();
    ~BankSystem();
    //Ruleaza sistemul bancar
    void run();

private: Bank bank;

    BankSystem();
};

#endif //OOP_BANKSYSTEM_HPP