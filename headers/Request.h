//
// Created by diogotvf7 on 01-11-2022.
//

#ifndef AED_TP1_REQUEST_H
#define AED_TP1_REQUEST_H

#include "Student.h"

class Student;

class Request {

public:
    virtual Student *getStudent() const = 0;
    virtual std::string getType() const = 0;
    virtual bool isPossible() const = 0;
};

#endif //AED_TP1_REQUEST_H
