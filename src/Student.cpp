//
// Created by diogotvf7 on 28-10-2022.
//

#include "Student.h"

using namespace std;

Student::Student(string code, string name, bool status) {
    this->code = stoi(code);
    this->name = name;
    this->status = status;
}

int Student::getCode() const {
    return code;
}

string Student::getName() const {
    return name;
}

list<Class> Student::getClasses() const {
    return schedule;
}

void Student::addClass(const Class &c) {
    schedule.push_back(c);
}

//TODO
void Student::removeClass() {

}

bool Student::operator==(const Student &s) const {
    return code == s.code && name == s.name;
}

ostream &operator<<(ostream &os, const Student &s) {

    os << " - Code: " << s.code << "      Name: " << s.name << "\n" << endl;
    for (const Class &c : s.schedule)
        os << c;
    return os;
}

