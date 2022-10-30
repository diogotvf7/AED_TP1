//
// Created by diogotvf7 on 27-10-2022.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "ScheduleManager.h"

using namespace std;

vector<Class> ScheduleManager::getClasses() const {
    return classes;
}

void ScheduleManager::readClassesFile() {

    ifstream in("../data/input/classes.csv");
    string line;

    getline(in, line); // Ignore first line

    while (getline(in, line)) {

        string classCode, ucCode, weekday, start, duration, type;

        stringstream input(line);

        getline(input, classCode, ',');
        getline(input, ucCode, ',');
        getline(input, weekday, ',');
        getline(input, start, ',');
        getline(input, duration, ',');
        getline(input, type, '\r');

        vector<Class>::iterator i = find_if(classes.begin(), classes.end(),[classCode, ucCode](const Class &c) { return c.getClassCode() == classCode && c.getUcCode() == ucCode; });

        if (i == classes.end()) {

            Class c(classCode, ucCode);
            c.addSlot(Slot(weekday, start, duration, type));
            classes.push_back(c);

        } else {

            i->addSlot(Slot(weekday, start, duration, type));
        }
    }
}

void ScheduleManager::readStudentsFile() {

    ifstream in("../data/input/classes.csv");
    string line;

    getline(in, line); // Ignore first line

    while (getline(in, line)) {

        string code, name, ucCode, classCode;

        stringstream input(line);

        getline(input, code, ',');
        getline(input, name, ',');
        getline(input, ucCode, ',');
        getline(input, classCode, '\r');

        set<Student>::iterator i = find_if(students.begin(), students.end(), [code](const Student &s) {return stoi(code) == s.getCode();});

        if (i == students.end()) {

            Student s(code, name);
            s.addClass(Class(classCode, ucCode));
            students.insert(s);
        } else {

            // Isto está tudo merdado aqui:
            // 1 -> Tentar adicionar referência a uma aula que esteja no vetor classes (mudar em cima também)
            // 2 -> Tentar perceber porque é que não dá para fazer logo "i->addClass(...);"
            Student s = *i;
            s.addClass(Class(classCode, ucCode));
        }
    }
}