//
// Created by diogotvf7 on 01-11-2022.
//

#include "../headers/UC.h"

using namespace std;

UC::UC(const string &ucCode) {
    this->maxStudentsInClass = 0;
    this->minStudentsInClass = INT16_MAX;
    this->ucCode = ucCode;
}

string UC::getUcCode() const {
    return ucCode;
}

vector<Class *> UC::getClasses() const {
    return classes;
}

void UC::addClassToUc(Class *c) {
    classes.push_back(c);
    maxStudentsInClass = c->countStudents() > maxStudentsInClass ? c->countStudents() : maxStudentsInClass;
    minStudentsInClass = c->countStudents() < minStudentsInClass ? c->countStudents() : minStudentsInClass;
}




