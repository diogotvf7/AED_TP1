//
// Created by diogotvf7 on 27-10-2022.
//

#ifndef AED_TP1_SCHEDULEMANAGER_H
#define AED_TP1_SCHEDULEMANAGER_H

#include <vector>
#include <set>
#include "Student.h"

struct StudentCmp {
    bool operator() (const Student& left, const Student& right) const {
        return left.getCode() < right.getCode();
    }
};

class ScheduleManager {

public:

    std::vector<Class> getClasses() const;
    void readClassesFile();
    void readStudentsFile();

private:
    std::vector<Class> classes;
    std::set<Student, StudentCmp> students;
};


#endif //AED_TP1_SCHEDULEMANAGER_H
