//
// Created by diogotvf7 on 02-11-2022.
//

#include "RemoveRequest.h"

RemoveRequest::RemoveRequest(Student *s, Class *c) {
    this->student = s;
    this->current = c;
}

Student *RemoveRequest::getStudent() const {
    return student;
}

Class *RemoveRequest::getCurrentClass() const {
    return current;
}

