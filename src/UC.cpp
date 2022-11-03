//
// Created by diogotvf7 on 01-11-2022.
//

#include "../headers/UC.h"

using namespace std;

UC::UC(const string &ucCode) {
    this->ucCode = ucCode;
}

string UC::getUcCode() const {
    return ucCode;
}

vector<Class *> UC::getClasses() const {
    return classes;
}

unsigned UC::getMinClassStudents() const {
    unsigned min = INT16_MAX;
    for (Class *c : classes)
        if (c->countStudents() < min)
            min = c->countStudents();
    return min;
}

unsigned UC::getMaxClassStudents() const {
    unsigned max = 0;
    for (Class *c : classes)
        if (c->countStudents() > max)
            max = c->countStudents();
    return max;
}

void UC::addClass(Class *c) {
    classes.push_back(c);
}
