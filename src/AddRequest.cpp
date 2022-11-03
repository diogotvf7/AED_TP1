//
// Created by diogotvf7 on 02-11-2022.
//

#include "../headers/AddRequest.h"

using namespace std;

AddRequest::AddRequest(Student *s, Class *c) {
    this->s = s;
    this->c = c;
}

Student *AddRequest::getStudent() const {
    return s;
}

Class *AddRequest::getRequestedClass() const {
    return c;
}

bool AddRequest::isPossible() const {

    unsigned maxStudents = max(c->getUc()->getMaxClassStudents(), c->countStudents() + 1);
    unsigned minStudents = c->getUc()->getMinClassStudents();

    if (c->countStudents() >= 30) return false;
    if (maxStudents - minStudents >= 4 && c->countStudents() >= maxStudents - 3) return false;
    for (Slot *slot : c->getSlots())
        for (Class *c2 : s->getClasses())
            for (Slot *slot2 : c2->getSlots())
                if (slot->overlaps(*slot2)) return false;
    return true;
}


