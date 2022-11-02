//
// Created by diogotvf7 on 02-11-2022.
//

#include "../headers/AddRequest.h"

AddRequest::AddRequest(Student *s, Class *c) {
    this->s = s;
    this->c = c;
}

bool AddRequest::isPossible() const {

    for (Slot *slot : c->getSlots())
        for (Class *c2 : s->getClasses())
            for (Slot *slot2 : c2->getSlots())
                if (slot->overlaps(*slot2)) return false;
    return true;
}

