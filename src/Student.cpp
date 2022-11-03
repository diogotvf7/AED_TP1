//
// Created by diogotvf7 on 28-10-2022.
//

#include "../headers/Student.h"

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

vector<Class*> Student::getClasses() const {
    return classes;
}

queue<Request*> Student::getRequests() const {
    return requests;
}

void Student::addClass(Class *c) {
    classes.push_back(c);
    c->addStudent(this);    // Adds Student to Class Student's vector
}

void Student::removeClass(Class *c) {
    remove(classes.begin(), classes.end(), c);
    c->removeStudent(this);
}

bool Student::operator==(const Student &s) const {
    return code == s.code && name == s.name;
}

ostream &operator<<(ostream &os, const Student &s) {

    os << " - Code: " << s.code << "      Name: " << s.name << "\n" << endl;
    for (Class *c : s.classes)
        os << c;
    return os;
}


