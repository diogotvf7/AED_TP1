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

queue<string> ScheduleManager::getFailedRequests() const {
    return failedRequests;
}

void ScheduleManager::addRequest(Request *r) {
    if (r->getStudent()->getStatus())
        statusRequests.push(r);
    else
        regularRequests.push(r);
}

void ScheduleManager::processAddRequest(AddRequest *ar) {
    if (ar->isPossible())
        ar->getStudent()->addClass(ar->getIntendedClass());
}

void ScheduleManager::processRemoveRequest(RemoveRequest *rr) {
    rr->getStudent()->removeClass(rr->getCurrentClass());
}

void ScheduleManager::processSwitchRequest(SwitchRequest *sr) {
    if (sr->isPossible()) {
        sr->getStudent()->removeClass(sr->getCurrentClass());
        sr->getStudent()->addClass(sr->getIntendedClass());
    }
}

void ScheduleManager::processSwapRequest(SwapRequest *sr) {
    if (sr->isPossible()) {
        sr->getStudent()->removeClass(sr->getCurrentClass());
        sr->getColleague()->removeClass(sr->getIntendedClass());
        sr->getStudent()->addClass(sr->getIntendedClass());
        sr->getColleague()->addClass(sr->getCurrentClass());
    }
}

void ScheduleManager::processRequests() {
    processStatusRequests();
    processRegularRequests();
}
//TODO
void ScheduleManager::processStatusRequests() {

    unsigned i = 0;
    while (!statusRequests.empty()) {

        Request *r = statusRequests.front();

        try {
            processAddRequest(dynamic_cast<AddRequest*>(r));
            processRemoveRequest(dynamic_cast<RemoveRequest*>(r));
            processSwitchRequest(dynamic_cast<SwitchRequest*>(r));
            processSwapRequest(dynamic_cast<SwapRequest*>(r));
        } catch (Oopsie &e) {
            failedRequests.push("Failed request " + to_string(++i) + ": " +  e.what());
        }

        statusRequests.pop();
    }
}

void ScheduleManager::processRegularRequests() {

    unsigned i = 0;
    while (!regularRequests.empty()) {

        Request *r = regularRequests.front();

        try {
            processAddRequest(dynamic_cast<AddRequest*>(r));
            processRemoveRequest(dynamic_cast<RemoveRequest*>(r));
            processSwitchRequest(dynamic_cast<SwitchRequest*>(r));
            processSwapRequest(dynamic_cast<SwapRequest*>(r));
        } catch (Oopsie &e) {
            failedRequests.push("Failed request " + to_string(++i) + ": " +  e.what());
        }

        regularRequests.pop();
    }
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


