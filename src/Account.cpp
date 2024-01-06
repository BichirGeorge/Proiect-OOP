#include "../headers/Account.hpp"

Account::Account(const std::string & accountNumber, double balance, Bank * bank): accountNumber(accountNumber), balance(balance), bank(bank) {}

Account::~Account() {}

const std::string & Account::getAccountNumber() const {
    return accountNumber;
}

[[maybe_unused]] double Account::getBalance() const {
    return balance;
}

[[maybe_unused]] void Account::deposit(double amount) {
    balance += amount;
}

[[maybe_unused]] void Account::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
    } else {
        std::cout << "Insufficient funds\n";
    }
}

Account & Account::operator = (const Account & other) {
    if (this != & other) {
        accountNumber = other.accountNumber;
        balance = other.balance;
    }
    return * this;
}

void Account::subscribe() {
    subscribed = true;
}

void Account::unsubscribe() {
    subscribed = false;
}

[[maybe_unused]] void Account::notify() {
    if (subscribed) {
        update();
    }
}

bool Account::isSubscribed() const {
    return subscribed;
}

std::ostream & operator << (std::ostream & os,
                            const Account & account) {
    os << "Account Number: " << account.accountNumber << ", Balance: " << account.balance;
    return os;
}