//
// Created by diogotvf7 on 03-11-2022.
//

#include "SwapRequest.h"

SwapRequest::SwapRequest(Student *student, Student *colleague, Class *current, Class *intended) {
    this->student = student;
    this->colleague = colleague;
    this->current = current;
    this->intended = intended;
}

Student *SwapRequest::getStudent() const {
    return student;
}

Student *SwapRequest::getColleague() const {
    return colleague;
}

Class *SwapRequest::getCurrentClass() const {
    return current;
}

Class *SwapRequest::getIntendedClass() const {
    return intended;
}

bool SwapRequest::isPossible() const {

    for (Slot *slot1 : current->getSlots())
        for (Class *c : colleague->getClasses())
            if (c != intended)
                for (Slot *slot2 : c->getSlots())
                    if (slot1->overlaps(*slot2)) throw Oopsie("Can't swap " + student->getName() + "'s " + current->getUc()->getUcCode() + ' ' + current->getClassCode() + " with " + colleague->getName() + "'s " + intended->getUc()->getUcCode() + ' ' + intended->getClassCode() + " because: " + student->getName() + "'s " + current->getUc()->getUcCode() + ' ' + current->getClassCode() + " overlaps with " + colleague->getName() + "'s " + c->getUc()->getUcCode() + ' ' + c->getClassCode());
    for (Slot *slot1 : intended->getSlots())
        for (Class *c : student->getClasses())
            if (c != current)
                for (Slot *slot2 : c->getSlots())
                    if (slot1->overlaps(*slot2)) throw Oopsie("Can't swap " + student->getName() + "'s " + current->getUc()->getUcCode() + ' ' + current->getClassCode() + " with " + colleague->getName() + "'s " + intended->getUc()->getUcCode() + ' ' + intended->getClassCode() + " because: " + colleague->getName() + "'s " + intended->getUc()->getUcCode() + ' ' + intended->getClassCode() + " overlaps with " + student->getName() + "'s " + c->getUc()->getUcCode() + ' ' + c->getClassCode());
    return true;
}

