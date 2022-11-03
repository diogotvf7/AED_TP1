//
// Created by diogotvf7 on 27-10-2022.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "../headers/ScheduleManager.h"
#include "../headers/UC.h"
#include "../headers/Student.h"

using namespace std;

ScheduleManager::ScheduleManager() {
    readClassesPerUcFile();
    readClassesFile();
    readStudentsClassesFile();
}

vector<UC*> ScheduleManager::getUCsVector() const {
    return ucs;
}

vector<Class*> ScheduleManager::getClassesVector() const {
    return classes;
}

set<Student*, StudentCmp> ScheduleManager::getStudentsSet() const {
    return students;
}

void ScheduleManager::readClassesPerUcFile() {

    ifstream in("../data/input/classes_per_uc.csv");
    string line; getline(in, line); // Ignore Header

    UC *currentUC;

    while (getline(in, line)) {

        string ucCode, classCode;
        stringstream input(line);

        getline(input, ucCode, ',');
        getline(input, classCode, '\r');

        if (ucs.empty() || ucCode != currentUC->getUcCode()) {
            currentUC = new UC(ucCode);
            ucs.push_back(currentUC);
        }
        Class *newClass = new Class(classCode, currentUC);
        classes.push_back(newClass);
    }
}

void ScheduleManager::readClassesFile() {

    ifstream in("../data/input/classes.csv");
    string line; getline(in, line); // Ignore Header

    while (getline(in, line)) {

        string classCode, ucCode, weekday, start, duration, type;
        stringstream input(line);

        getline(input, classCode, ',');
        getline(input, ucCode, ',');
        getline(input, weekday, ',');
        getline(input, start, ',');
        getline(input, duration, ',');
        getline(input, type, '\r');

        auto itr = find_if(classes.begin(), classes.end(),[ucCode, classCode](Class *c){return c->getClassCode() == classCode && c->getUc()->getUcCode() == ucCode;});
        (*itr)->addSlot(new Slot(weekday, start, duration, type));
    }
}

void ScheduleManager::readStudentsClassesFile() {

    ifstream in("../data/input/students_classes.csv");
    string line;

    getline(in, line); // Ignore Header

    Student *currentStudent = nullptr;

    while (getline(in, line)) {

        string code, name, ucCode, classCode;

        stringstream input(line);

        getline(input, code, ',');
        getline(input, name, ',');
        getline(input, ucCode, ',');
        getline(input, classCode, '\r');

        auto itr = find_if(classes.begin(), classes.end(),[classCode, ucCode](Class *c) {return c->getClassCode() == classCode && c->getUc()->getUcCode() == ucCode;});

        if (currentStudent == nullptr) {
            currentStudent = new Student(code, name);
        }
        if (currentStudent->getCode() != stoi(code)) {
            students.insert(currentStudent);
            currentStudent = new Student(code, name);
        }
        currentStudent->addClass(*itr);
    }
    students.insert(currentStudent);
}


