//
// Created by joaob on 29/10/2022.
//

#include "../headers/Student.h"

Student::Student(int number, std::string name) {
    this->number = number;
    this->name = name;
}
 

int Student::getNumber() const {
    return number;
}

const std::string &Student::getName() const {
    return name;
}

const std::list<Class> &Student::getClasses() const {
    return classes;
}
