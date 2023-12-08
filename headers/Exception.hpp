//
// Created by George on 12/8/2023.
//

#ifndef OOP_EXCEPTION_HPP
#define OOP_EXCEPTION_HPP

#include <stdexcept>

class InvalidDepositException : public std::invalid_argument {
public:
    InvalidDepositException(const std::string& what_arg)
            : std::invalid_argument(what_arg) {}
};

class InvalidWithdrawalException : public std::invalid_argument {
public:
    InvalidWithdrawalException(const std::string& what_arg)
            : std::invalid_argument(what_arg) {}
};

class NegativeAmountException : public std::invalid_argument {
public:
    NegativeAmountException(const std::string& what_arg)
            : std::invalid_argument(what_arg) {}
};

class InsufficientFundsException : public std::invalid_argument {
public:
    InsufficientFundsException(const std::string& what_arg)
            : std::invalid_argument(what_arg) {}
};

class CreditLimitExceededException : public std::invalid_argument {
public:
    CreditLimitExceededException(const std::string& what_arg)
            : std::invalid_argument(what_arg) {}
};

class InvalidCheckAmountException : public std::invalid_argument {
public:
    InvalidCheckAmountException(const std::string& what_arg)
            : std::invalid_argument(what_arg) {}
};


#endif //OOP_EXCEPTION_HPP
