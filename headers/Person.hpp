//
// Created by George on 12/8/2023.
//

#ifndef OOP_PERSON_HPP
#define OOP_PERSON_HPP


#include <string>
#include <iostream>

class Person {
private:
    std::string firstName;
    std::string lastName;
    std::string address;
    int id;

    static int lastID;

public:
    Person(const std::string& firstName, const std::string& lastName, const std::string& address);

    std::string getFirstName() const;

    std::string getLastName() const;

    friend std::ostream& operator<<(std::ostream& out, const Person& person);

    friend std::istream& operator>>(std::istream& in, Person& person);
};



#endif //OOP_PERSON_HPP
