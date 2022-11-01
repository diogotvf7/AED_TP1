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
     * @brief Constructor for the Schedule Manager's class.
     * Runs the input reading functions;
     */
    ScheduleManager();
    /**
     * @brief Get function for the Class's Vector;
     * @return a vector<Class> with all the Classes from input the file;
     */
    std::vector<Class> getClassesVector() const;
    /**
     * @brief Get functions for the Students Set;
     * @return a set<Student> with all the Students from the input file;
     */
    std::set<Student*, StudentCmp> getStudentsSet() const;
    /**
     * @brief Function that finds a Student by Code and Name in the Student's set;
     * @param code the Code to look for;
     * @param name the Name to look for;
     * @return returns a reference to the Student in case it finds him, returns Student("", "") otherwise;
     */
    Student findStudent(std::string code, const std::string& name) const;
    /**
     * @brief Reads the classes_per_uc.csv file and stores the input in vector<Class> classes;
     */
    void readClassesFile();
    /**
     * @brief Reads the students_classes.csv file and stores the input in set<Student> students;
     */
    void readStudentsFile();
    void updateStudent();

private:
    std::vector<Class*> classes;
    std::set<Student*, StudentCmp> students;
};


#endif //AED_TP1_SCHEDULEMANAGER_H
