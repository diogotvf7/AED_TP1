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

std::string SwapRequest::getType() const {
    return "swap";
}

bool SwapRequest::isPossible() const {
    if (current->getUc() != intended->getUc()) throw Oopsie("Can't swap " + student->getName() + "'s " +
                                                            current->getUc()->getName() + ' ' + current->getName() + " with " + colleague->getName() + "'s " +
                                                            intended->getUc()->getName() + ' ' + intended->getName() + " because: both classes are from different UC's.");
    if (!student->isInClass(current)) throw Oopsie("Can't swap " + student->getName() + "'s " +
                                                   current->getUc()->getName() + ' ' + current->getName() + " with " + colleague->getName() + "'s " +
                                                   intended->getUc()->getName() + ' ' + intended->getName() + " because: " + student->getName() + " insn't in " +
                                                   current->getUc()->getName() + ' ' + current->getName() + '.');
    if (student->isInClass(intended)) throw Oopsie("Can't swap " + student->getName() + "'s " +
                                                   current->getUc()->getName() + ' ' + current->getName() + " with " + colleague->getName() + "'s " +
                                                   intended->getUc()->getName() + ' ' + intended->getName() + " because: " +
                                                   intended->getUc()->getName() + ' ' + intended->getName() + " already is in " + student->getName() + "'s schedule.");
    if (!colleague->isInClass(intended)) throw Oopsie("Can't swap " + student->getName() + "'s " +
                                                      current->getUc()->getName() + ' ' + current->getName() + " with " + colleague->getName() + "'s " +
                                                      intended->getUc()->getName() + ' ' + intended->getName() + " because: " + colleague->getName() + " insn't in " +
                                                      intended->getUc()->getName() + ' ' + intended->getName() + '.');
    if (colleague->isInClass(current)) throw Oopsie("Can't swap " + student->getName() + "'s " +
                                                    current->getUc()->getName() + ' ' + current->getName() + " with " + colleague->getName() + "'s " +
                                                    intended->getUc()->getName() + ' ' + intended->getName() + " because: " +
                                                    current->getUc()->getName() + ' ' + current->getName() + " already is in " + colleague->getName() + "'s schedule.");
    for (Slot *slot1 : current->getSlots())
        for (Class *c : colleague->getClasses())
            if (c != intended)
                for (Slot *slot2 : c->getSlots())
                    if (slot1->overlaps(*slot2)) throw Oopsie("Can't swap " + student->getName() + "'s " +
                                                              current->getUc()->getName() + ' ' + current->getName() + " with " + colleague->getName() + "'s " +
                                                              intended->getUc()->getName() + ' ' + intended->getName() + " because: " + student->getName() + "'s " +
                                                              current->getUc()->getName() + ' ' + current->getName() + " overlaps with " + colleague->getName() + "'s " +
                                                              c->getUc()->getName() + ' ' + c->getName());
    for (Slot *slot1 : intended->getSlots())
        for (Class *c : student->getClasses())
            if (c != current)
                for (Slot *slot2 : c->getSlots())
                    if (slot1->overlaps(*slot2)) throw Oopsie("Can't swap " + student->getName() + "'s " +
                                                              current->getUc()->getName() + ' ' + current->getName() + " with " + colleague->getName() + "'s " +
                                                              intended->getUc()->getName() + ' ' + intended->getName() + " because: " + colleague->getName() + "'s " +
                                                              intended->getUc()->getName() + ' ' + intended->getName() + " overlaps with " + student->getName() + "'s " +
                                                              c->getUc()->getName() + ' ' + c->getName());
    return true;
}


