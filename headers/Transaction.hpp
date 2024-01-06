#ifndef OOP_TRANSACTION_HPP
#define OOP_TRANSACTION_HPP


#include <iostream>
#include <string>

template <typename T>
class Transaction {
public:
    // Constructor
    Transaction(const std::string& accountNumber, T amount, bool isDeposit);

    // Display transaction details
    void displayTransaction() const;

private:
    std::string accountNumber_;
    T amount_;
    bool isDeposit_;
};



#endif //OOP_TRANSACTION_HPP
