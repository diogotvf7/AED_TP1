//
// Created by diogotvf7 on 03-11-2022.
//

#include "SwitchRequest.h"

using namespace std;

SwitchRequest::SwitchRequest(Student *student, Class *current, Class *intended) {
    this->student = student;
    this->current = current;
    this->intended = intended;
}

Student *SwitchRequest::getStudent() const {
    return student;
}

Class *SwitchRequest::getCurrentClass() const {
    return current;
}

Class *SwitchRequest::getIntendedClass() const {
    return intended;
}

string SwitchRequest::getType() const {
    return "switch";
}

bool SwitchRequest::isPossible() const {
    if (current->getUc() != intended->getUc()) throw Oopsie("Can't switch " + student->getName() + "'s " + current->getUc()->getName() + ' ' + current->getName() + " to " + intended->getUc()->getName() + ' ' + intended->getName() + " because: both classes are from different UC's.");
    if (!student->isInClass(current)) throw Oopsie("Can't switch " + student->getName() + "'s " + current->getUc()->getName() + ' ' + current->getName() + " to " + intended->getUc()->getName() + ' ' + intended->getName() + " because: " + student->getName() + " insn't in " + current->getUc()->getName() + ' ' + current->getName() + '.');
    if (student->isInClass(intended)) throw Oopsie("Can't switch " + student->getName() + "'s " + current->getUc()->getName() + ' ' + current->getName() + " to " + intended->getUc()->getName() + ' ' + intended->getName() + " because: " + student->getName() + " already is in " + intended->getUc()->getName() + ' ' + intended->getName() + '.');
    unsigned tmpMax = intended->getUc()->getMaxClassStudents();
    unsigned tmpMin = intended->getUc()->getMinClassStudents();
    unsigned maxStudents = max(intended->getUc()->getMaxClassStudents(current), tmpMax + (intended->countStudents() == tmpMax) - (current->countStudents() == tmpMax));
    unsigned minStudents = intended->getUc()->getMinClassStudents(current) == tmpMin ? tmpMin - (current->countStudents() == tmpMin) : tmpMin + (intended->countStudents() == tmpMin);
    if (intended->countStudents() >= 30) throw Oopsie("Can't switch " + student->getName() + "'s " + current->getUc()->getName() + ' ' + current->getName() + " to " + intended->getUc()->getName() + ' ' + intended->getName() + " because: " + intended->getUc()->getName() + ' ' + intended->getName() + " is full.");
    if (!student->getStatus() && current->countStudents() <= intended->countStudents() && maxStudents - minStudents >= 4 && intended->countStudents() >= maxStudents - 4) throw Oopsie("Can't switch " + student->getName() + "'s " + current->getUc()->getName() + ' ' + current->getName() + " to " + intended->getUc()->getName() + ' ' + intended->getName() + " because: " + "Adding " + student->getName() + " to " + intended->getUc()->getName() + ' ' + intended->getName() + " will cause imbalance.");

    for (Slot *slot : intended->getSlots())
        for (Class *c : student->getClasses())
            if (c != current)
                for (Slot *slot2 : c->getSlots())
                    if (slot->overlaps(*slot2))  throw Oopsie("Can't switch " + student->getName() + "'s" + current->getUc()->getName() + ' ' + current->getName() + " to " + intended->getUc()->getName() + ' ' + intended->getName() + " because: " + student->getName() + "'s " + c->getUc()->getName() + ' ' + c->getName() + " overlaps with " + intended->getUc()->getName() + ' ' + intended->getName() + '.');
    return true;

}



