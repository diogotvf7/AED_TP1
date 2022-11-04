//
// Created by diogotvf7 on 03-11-2022.
//

#ifndef AED_TP1_SWAPREQUEST_H
#define AED_TP1_SWAPREQUEST_H

#include "Oopsie.h"
#include "Student.h"
#include "Class.h"
#include "Request.h"
#include "Slot.h"

class SwapRequest : public Request {

public:
    SwapRequest(Student *student, Student *colleague, Class *current, Class *intended);
    Student *getStudent() const override;
    Student *getColleague() const;
    Class *getCurrentClass() const;
    Class *getIntendedClass() const;
    bool isPossible() const;
private:
    Student *student;
    Student *colleague;
    Class *current;
    Class *intended;
};


#endif //AED_TP1_SWAPREQUEST_H
