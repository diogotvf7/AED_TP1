//
// Created by diogotvf7 on 27-10-2022.
//

#include "Class.h"

using namespace std;

Class::Class(std::string classCode, std::string ucCode) {
    this->classCode = classCode;
    this->ucCode = ucCode;
}

string Class::getClassCode() const {
    return classCode;
}

string Class::getUcCode() const {
    return ucCode;
}

void Class::addSlot(const Slot &slot) {
    slots.push_back(slot);
}