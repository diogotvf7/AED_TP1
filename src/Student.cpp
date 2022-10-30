//
// Created by diogotvf7 on 28-10-2022.
//

#include "Student.h"

using namespace std;

Student::Student(int code, string name, bool status = 0) {
    this->code = code;
    this->name = name;
    this->status = status;
}

int Student::getCode() const {
    return code;
}

string Student::getName() const {
    return name;
}

void Student::addClass(const Class &c) {
    schedule.push_back(c);
}

//TODO
void Student::removeClass() {

}

