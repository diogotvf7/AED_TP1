//
// Created by diogotvf7 on 01-11-2022.
//

#ifndef AED_TP1_UC_H
#define AED_TP1_UC_H

#include <string>
#include <vector>

#include "Class.h"
#include "Student.h"

class Class;
class Student;

class UC {

public:
    explicit UC(const std::string& ucCode);
    std::string getUcCode() const;
    std::vector<Class*> getClasses() const;
    unsigned getMinClassStudents() const;
    unsigned getMaxClassStudents() const;
    void addClass(Class *c);
    void addStudent(Student *s);
private:
    std::string ucCode;
    std::vector<Class*> classes;
    std::vector<Student*> students;
};


#endif //AED_TP1_UC_H
