#include "../headers/AccountFactory.hpp"

Account* AccountFactory::createAccount(const std::string& accountNumber, double balance, Bank* bank, const std::string& accountType) {
    if (accountType == "Savings") {
        return new SavingsAccount(accountNumber, balance, bank);
    } else if (accountType == "Current") {
        return new CurrentAccount(accountNumber, balance, bank);
    } else {
        return nullptr; // Tip de cont necunoscut
    }
}