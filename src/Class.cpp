//
// Created by diogotvf7 on 27-10-2022.
//

#include "Class.h"

using namespace std;

Class::Class(const string &classCode, UC *uc) {
    this->classCode = classCode;
    this->uc = uc;
    uc->addClass(this);
}

string Class::getName() const {
    return classCode;
}

UC * Class::getUc() const {
    return uc;
}

list<Slot*> Class::getSlots() const {
    return slots;
}

vector<Student*> Class::getStudents() const {
    return students;
}

void Class::addStudent(Student *s) {
    students.push_back(s);
}

void Class::addSlot(Slot *slot) {
    slots.push_back(slot);
}

void Class::removeStudent(Student *s) {
    remove(students.begin(), students.end(), s);
}

unsigned Class::countStudents() const {
    return students.size();
}

bool Class::operator==(const Class &c) const {
    return classCode == c.classCode && uc->getName() == c.uc->getName();
}

ostream &operator<<(ostream &os, const Class &c) {

    os << "     - UC Code: " << c.getUc()->getName() << "      Class Code: " << c.classCode << endl;
    for (Slot *s : c.slots)
        os << "       - " << *s;
    return os;
}



