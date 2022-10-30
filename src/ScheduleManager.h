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
    /**
     * @brief Get function for the Class's Vector;
     * @return a vector<Class> with all the Classes from input the file;
     */
    std::vector<Class> getClasses() const;
    /**
     * @brief Get functions for the Students Set;
     * @return a set<Student> with all the Students from the input file;
     */
    std::set<Student, StudentCmp> getStudents() const;
    /**
     * @brief Reads the classes_per_uc.csv file and stores the input in vector<Class> classes;
     */
    void readClassesFile();
    /**
     * @brief Reads the students_classes.csv file and stores the input in set<Student> students;
     */
    void readStudentsFile();

private:
    std::vector<Class> classes;
    std::set<Student, StudentCmp> students;
};


#endif //AED_TP1_SCHEDULEMANAGER_H
