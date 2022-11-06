//
// Created by diogotvf7 on 01-11-2022.
//

#include "UC.h"

using namespace std;

UC::UC(const string &ucCode) {
    this->ucCode = ucCode;
}

string UC::getName() const {
    return ucCode;
}

std::vector<Class *> UC::getClasses() const {
    return classes;
}

unsigned UC::countStudents() const {
    unsigned total = 0;
    for (Class *c : classes) total += c->countStudents();
    return total;
}

unsigned UC::getMinClassStudents(Class *ignore) const {
    unsigned min = INT16_MAX;
    for (Class *c : classes)
        if (c != ignore && c->countStudents() < min)
            min = c->countStudents();
    return min;
}

unsigned UC::getMaxClassStudents(Class *ignore) const {
    unsigned max = 0;
    for (Class *c : classes)
        if (c != ignore && c->countStudents() > max)
            max = c->countStudents();
    return max;
}

void UC::addClass(Class *c) {
    classes.push_back(c);
}
