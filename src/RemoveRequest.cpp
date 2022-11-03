//
// Created by diogotvf7 on 02-11-2022.
//

#include "RemoveRequest.h"

RemoveRequest::RemoveRequest(Student *s, Class *c) {
    this->student = s;
    this->intended = c;
}

Student *RemoveRequest::getStudent() const {
    return student;
}

Class *RemoveRequest::getIntendedClass() const {
    return intended;
}

bool RemoveRequest::isPossible() {

    unsigned tmpMax = intended->getUc()->getMaxClassStudents();
    unsigned maxStudents = tmpMax + (intended->countStudents() == tmpMax);
    unsigned minStudents = std::min(intended->getUc()->getMinClassStudents(intended), intended->countStudents() + 1);
    if (maxStudents - minStudents >= 4 && intended->countStudents() >= maxStudents - 4) return false;
    return true;
}