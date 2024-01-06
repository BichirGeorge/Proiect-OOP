#include "../headers/Transaction.hpp"


// Implementation
template <typename T>
Transaction<T>::Transaction(const std::string& accountNumber, T amount, bool isDeposit)
        : accountNumber_(accountNumber), amount_(amount), isDeposit_(isDeposit) {}

template <typename T>
void Transaction<T>::displayTransaction() const {
    std::cout << "Account: " << accountNumber_ << "\n";
    std::cout << (isDeposit_ ? "Deposit" : "Withdrawal") << " Amount: " << amount_ << "\n";
}

template class Transaction<double>;
template class Transaction<int>;