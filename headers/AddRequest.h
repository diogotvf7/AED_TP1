//
// Created by diogotvf7 on 02-11-2022.
//

#ifndef AED_TP1_ADDREQUEST_H
#define AED_TP1_ADDREQUEST_H

#include "Request.h"
#include "Student.h"
#include "Class.h"
#include "Slot.h"

class AddRequest : public Request {

public:
    AddRequest(Student *s, Class *c);
    bool isPossible() const override;
private:
    Student *s;
    Class *c;
};


#endif //AED_TP1_ADDREQUEST_H
