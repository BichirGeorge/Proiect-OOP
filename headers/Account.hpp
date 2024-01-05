#ifndef OOP_ACCOUNT_HPP
#define OOP_ACCOUNT_HPP

#include <iostream>

#include <string>

class Bank;

class Account {
public:
    //Constructorul clasei Account
    Account(const std::string & accountNumber, double balance, Bank * bank);
    //Destructorul clasei Account
    virtual~Account();
    //Actualizeaza contul
    virtual void update() = 0;
    //Cloneaza contul (virtual)
    virtual Account * clone() const = 0;

    const std::string & getAccountNumber() const;
    //Obtine balanta contului
    double getBalance() const;
    //Depoziteaza bani in cont
    void deposit(double amount);
    //Retrage bani din cont
    void withdraw(double amount);

    Account & operator = (const Account & other);
    friend std::ostream & operator << (std::ostream & os,
                                       const Account & account);
    //Aboneaza contul
    void subscribe();

    // Dezaboneaza contul
    void unsubscribe();

    // Metoda pentru a notifica contul despre un eveniment
    void notify();

    bool isSubscribed() const;

protected: std::string accountNumber;
    double balance;
    Bank * bank;

private: bool subscribed = false; //Contul nu este abonat default
};

#endif //OOP_ACCOUNT_HPP