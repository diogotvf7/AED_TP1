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
    list<Slot*> sorted = slots;
    sorted.sort([](Slot *lhs, Slot *rhs){return *lhs < *rhs;});
    return sorted;
}

vector<Student*> Class::getStudents() const {
    return students;
}

int Class::getYear() const {
    return classCode[0] - '0';
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



