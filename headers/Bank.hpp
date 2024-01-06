#ifndef OOP_BANK_HPP
#define OOP_BANK_HPP

#include <vector>

#include <string>

#include "Account.hpp"
// Clasa bank este o banca si gestioneaza conturile bancare
class Bank {
public:
    //Constructor clasa bank
    explicit Bank(const std::string & name);
    //Destructor clasa bank
    ~Bank();
    //Adauga un cont
    void addAccount(Account * account);
    //Elimina un cont
    void removeAccount(const std::string & accountNumber);
    //Afiseaza toate conturile create
    void displayAccounts() const;
    //Notifica toate conturile
    void notifyClients();
    // Aboneaza contul
    void subscribeAccount(const std::string & accountNumber);
    // Dezaboneaza contul
    void unsubscribeAccount(const std::string & accountNumber);
private: std::string name;
    std::vector < Account * > accounts;

    bool accountExists(const std::string & accountNumber) const;
};

#endif //OOP_BANK_HPP