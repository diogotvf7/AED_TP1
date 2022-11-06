//
// Created by diogotvf7 on 28-10-2022.
//

#include <utility>

#include "Student.h"

using namespace std;

Student::Student(const string& code, string name, bool status) {
    this->code = stoi(code);
    this->name = std::move(name);
    this->status = status;
}

int Student::getCode() const {
    return code;
}

string Student::getName() const {
    return name;
}

vector<Class*> Student::getClasses() const {
    return classes;
}

bool Student::getStatus() const {
    return status;
}

void Student::setStatus(bool s) {
    this->status = s;
}

unsigned Student::countClasses() const {
    return classes.size();
}

void Student::addClass(Class *c) {
    classes.push_back(c);
    c->addStudent(this);    // Adds Student to Class Student's vector
}

void Student::removeClass(Class *c) {
    classes.erase(find(classes.begin(), classes.end(), c));
    c->removeStudent(this);
}

bool Student::isInClass(Class *c) const {
    for (Class *sc : classes)
        if (c == sc)
            return true;
    return false;
}

bool Student::isInUc(UC *uc) const {
    for (Class *sc : classes)
        if (uc->getName() == sc->getUc()->getName())
            return true;
    return false;
}

ostream &operator<<(ostream &os, const Student &s) {
    os << " - Code: " << s.code << "      Name: " << s.name << "\n" << endl;
    for (Class *c : s.classes)
        os << c;
    return os;
}



