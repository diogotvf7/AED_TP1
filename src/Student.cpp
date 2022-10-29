//
// Created by joaob on 29/10/2022.
//

#include "Student.h"

using namespace std;

Student::Student(int number, string name) {
    this->number = number;
    this->name = name;
}
 
int Student::getNumber() const {
    return number;
}

const string &Student::getName() const {
    return name;
}

const list<Class> &Student::getClasses() const {
    return classes;
}
