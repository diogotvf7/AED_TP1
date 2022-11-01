//
// Created by diogotvf7 on 27-10-2022.
//

#include <algorithm>
#include "../headers/Class.h"

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

std::list<Slot> Class::getSlots() const {
    return slots;
}

void Class::addSlot(const Slot &slot) {
    slots.push_back(slot);
    slots.sort();
}

bool Class::operator==(const Class &c) const {
    return classCode == c.classCode && ucCode == c.ucCode;
}

ostream &operator<<(ostream &os, const Class &c) {

    os << "     - UC Code: " << c.ucCode << "      Class Code: " << c.classCode << endl;
    for (const Slot &s : c.slots)
        os << "       - " << s;
    return os;
}


