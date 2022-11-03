//
// Created by diogotvf7 on 03-11-2022.
//

#ifndef AED_TP1_SWAPREQUEST_H
#define AED_TP1_SWAPREQUEST_H

#include "Student.h"
#include "Class.h"
#include "Request.h"
#include "Slot.h"

class SwapRequest : public Request {

public:
    SwapRequest(Student *student1, Student *student2, Class *class1, Class *class2);
    Student *getStudent1() const;
    Student *getStudent2() const;
    Class *getClass1() const;
    Class *getClass2() const;
    bool isPossible() const;
private:
    Student *student1;
    Student *student2;
    Class *class1;
    Class *class2;
};


#endif //AED_TP1_SWAPREQUEST_H
