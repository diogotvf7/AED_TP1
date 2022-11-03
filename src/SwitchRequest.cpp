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

bool SwitchRequest::isPossible() const {

    unsigned tmpMax = intended->getUc()->getMaxClassStudents();
    unsigned tmpMin = intended->getUc()->getMinClassStudents();
    unsigned maxStudents = max(intended->getUc()->getMaxClassStudents(current), tmpMax + (intended->countStudents() == tmpMax) - (current->countStudents() == tmpMax));
    unsigned minStudents = intended->getUc()->getMinClassStudents(current) == tmpMin ? tmpMin - (current->countStudents() == tmpMin) : tmpMin + (intended->countStudents() == tmpMin);
    if (intended->countStudents() >= 30) return false;
    if (current->countStudents() <= intended->countStudents() && maxStudents - minStudents >= 4 && intended->countStudents() >= maxStudents - 4) return false;

    for (Slot *slot : intended->getSlots())
        for (Class *c2 : student->getClasses())
            if (c2 != current)
                for (Slot *slot2 : c2->getSlots())
                    if (slot->overlaps(*slot2)) return false;
    return true;

}

