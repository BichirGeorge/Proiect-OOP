//
// Created by George on 12/8/2023.
//

#include "../headers/Person.hpp"

int Person::lastID = 0;

Person::Person(const std::string& firstName, const std::string& lastName, const std::string& address)
        : firstName(firstName), lastName(lastName), address(address) {
    id = ++lastID;
}

std::string Person::getFirstName() const {
    return firstName;
}

std::string Person::getLastName() const {
    return lastName;
}

std::ostream& operator<<(std::ostream& out, const Person& person) {
    out << "Name: " << person.firstName << " " << person.lastName << "\n";
    out << "Address: " << person.address << "\n";
    out << "ID: " << person.id << "\n";
    return out;
}

std::istream& operator>>(std::istream& in, Person& person) {
    in >> person.firstName >> person.lastName >> person.address;
    return in;
}
