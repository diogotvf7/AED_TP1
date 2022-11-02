//
// Created by diogotvf7 on 01-11-2022.
//

#ifndef AED_TP1_REQUEST_H
#define AED_TP1_REQUEST_H

#include "Student.h"

class Request {

public:
    Request(Student *student);
private:
    Student *student;
};

#endif //AED_TP1_REQUEST_H
