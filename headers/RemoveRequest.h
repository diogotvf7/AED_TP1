//
// Created by diogotvf7 on 02-11-2022.
//

#ifndef AED_TP1_REMOVEREQUEST_H
#define AED_TP1_REMOVEREQUEST_H
#include "Request.h"
#include "Student.h"
#include "Class.h"
#include "Slot.h"

class RemoveRequest : public Request {

public:

    RemoveRequest(Student *s, Class *c);
    Student *getStudent() const;
    Class *getIntendedClass() const;
    bool isPossible();
private:
    Student *student;
    Class *intended;
};


#endif //AED_TP1_REMOVEREQUEST_H
