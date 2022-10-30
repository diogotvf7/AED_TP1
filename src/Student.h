//
// Created by diogotvf7 on 28-10-2022.
//

#ifndef AED_TP1_STUDENT_H
#define AED_TP1_STUDENT_H

#include <string>
#include <vector>

#include "Class.h"

class Student {

public:
    Student(std::string code, std::string name, bool status = false);

    int getCode() const;

    std::string getName() const;

    void addClass(const Class &c);

    void removeClass();

private:
    int code;
    std::string name;
    bool status;
    std::list<Class> schedule;
};


#endif //AED_TP1_STUDENT_H
