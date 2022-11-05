//
// Created by diogotvf7 on 27-10-2022.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "ScheduleManager.h"
#include "UC.h"
#include "Student.h"

using namespace std;

ScheduleManager::ScheduleManager() {
    readClassesPerUcFile();
    readClassesFile();
    readStudentsClassesFile();
}

std::vector<UC *> ScheduleManager::getUcVector() const {
    return ucs;
}

vector<Class*> ScheduleManager::getClassesVector() const {
    return classes;
}

set<Student*,StudentCodeCmp> ScheduleManager::getStudentsByCodeSet() const {
    return studentsByCode;
}

set<Student*,StudentNameCmp> ScheduleManager::getStudentsByNameSet() const {
    return studentsByName;
}

Student *ScheduleManager::findStudentByCode(const string &code) const {
    auto i = studentsByCode.find(new Student(code, ""));
    if (i == studentsByCode.end())
        return nullptr;
    return *i;
}

Student *ScheduleManager::findStudentByName(const string &name) const {
    auto i = studentsByName.find(new Student("0", name));
    if (i == studentsByName.end())
        return nullptr;
    return *i;
}

void ScheduleManager::createRequest(Request *r) {
    if (r->getStudent()->getStatus())
        statusRequests.push(r);
    else
        regularRequests.push(r);
}

void ScheduleManager::processAddRequest(AddRequest *ar) {
    try {ar->isPossible();} catch (Oopsie &e) {
        throw Oopsie(e);
    }
        ar->getStudent()->addClass(ar->getIntendedClass());
}

void ScheduleManager::processRemoveRequest(RemoveRequest *rr) {
    try {rr->isPossible();} catch (Oopsie &e) {
        throw Oopsie(e);
    }
    rr->getStudent()->removeClass(rr->getCurrentClass());
}

void ScheduleManager::processSwitchRequest(SwitchRequest *sr) {
    try {sr->isPossible();} catch (Oopsie &e) {
        throw Oopsie(e);
    }
    sr->getStudent()->removeClass(sr->getCurrentClass());
    sr->getStudent()->addClass(sr->getIntendedClass());
}

void ScheduleManager::processSwapRequest(SwapRequest *sr) {
    try {sr->isPossible();} catch (Oopsie &e) {
        throw Oopsie(e);
    }
    sr->getStudent()->removeClass(sr->getCurrentClass());
    sr->getColleague()->removeClass(sr->getIntendedClass());
    sr->getStudent()->addClass(sr->getIntendedClass());
    sr->getColleague()->addClass(sr->getCurrentClass());
}

void ScheduleManager::processRequests() {
    processStatusRequests();
    processRegularRequests();
}

void ScheduleManager::processStatusRequests() {

    ofstream output_file("../data/output/output_log", std::ios_base::app);

    while (!statusRequests.empty()) {

        Request *r = statusRequests.front();

        try {
            if (r->getType() == "add")
                processAddRequest(dynamic_cast<AddRequest*>(r));
            else if (r->getType() == "remove")
                processRemoveRequest(dynamic_cast<RemoveRequest*>(r));
            else if (r->getType() == "switch")
                processSwitchRequest(dynamic_cast<SwitchRequest*>(r));
            else if (r->getType() == "swap")
                processSwapRequest(dynamic_cast<SwapRequest*>(r));
        } catch (Oopsie &e) {
            output_file << "Failed request: " + e.what() << endl;
        }

        statusRequests.pop();
    }
}

void ScheduleManager::processRegularRequests() {

    ofstream output_file("../data/output/output_log", std::ios_base::app);

    while (!regularRequests.empty()) {

        Request *r = regularRequests.front();

        try {
            if (r->getType() == "add")
                processAddRequest(static_cast<AddRequest*>(r));
            else if (r->getType() == "remove")
                processRemoveRequest(static_cast<RemoveRequest*>(r));
            else if (r->getType() == "switch")
                processSwitchRequest(static_cast<SwitchRequest*>(r));
            else if (r->getType() == "swap")
                processSwapRequest(static_cast<SwapRequest*>(r));
        } catch (Oopsie &e) {
            output_file << "Failed request: " + e.what() << endl;
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

        if (ucs.empty() || ucCode != currentUC->getName()) {
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

        auto itr = find_if(classes.begin(), classes.end(),[ucCode, classCode](Class *c){return c->getName() == classCode &&
                c->getUc()->getName() == ucCode;});
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

        auto itr = find_if(classes.begin(), classes.end(),[classCode, ucCode](Class *c) {return
                c->getName() == classCode &&
                c->getUc()->getName() == ucCode;});

        if (currentStudent == nullptr) {
            currentStudent = new Student(code, name);
        }
        if (currentStudent->getCode() != stoi(code)) {
            studentsByCode.insert(currentStudent);
            studentsByName.insert(currentStudent);
            currentStudent = new Student(code, name);
        }
        currentStudent->addClass(*itr);
    }
    studentsByCode.insert(currentStudent);
    studentsByName.insert(currentStudent);
}



