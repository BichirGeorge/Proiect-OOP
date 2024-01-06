#include "../headers/Transaction.hpp"


template <typename T>
Transaction<T>::Transaction(const std::string& accountNumber, T amount, bool isDeposit)
        : accountNumber_(accountNumber), amount_(amount), isDeposit_(isDeposit) {}

template <typename T>
void Transaction<T>::displayTransaction() const {
    std::cout << "Account: " << accountNumber_ << "\n";
    if (isDeposit_) {
        std::cout << "Deposit Amount: " << amount_ << "\n";
    } else {
        std::cout << "Withdrawal Amount: " << amount_ << "\n";
    }
}

template class Transaction<double>;
template class Transaction<int>;