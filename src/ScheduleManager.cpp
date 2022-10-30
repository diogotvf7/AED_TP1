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

    while (getline(in, line, '\r')) {

        string classCode, ucCode, weekday, start, duration, type;

        stringstream input(line);

        getline(input, classCode, ',');
        getline(input, ucCode, ',');
        getline(input, weekday, ',');
        getline(input, start, ',');
        getline(input, duration, ',');
        getline(input, type);

        std::vector<Class>::iterator i = find_if(classes.begin(), classes.end(),[classCode, ucCode](Class c) { return c.getClassCode() == classCode && c.getUcCode() == ucCode; });

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


}