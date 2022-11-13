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

std::vector<Class *> UC::getClasses(int year) const {
    if (year) {
        vector<Class*> tmp;
        copy_if(classes.begin(), classes.end(), back_inserter(tmp), [year](Class *c){return c->getYear() == year;});
        return tmp;
    }
    return classes;
}

int UC::getYear() const {
    return ucCode[6] - '0' + 1;
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
