//
// Created by diogotvf7 on 02-11-2022.
//

#include "../headers/AddRequest.h"

using namespace std;

AddRequest::AddRequest(Student *student, Class *intended) {
    this->student = student;
    this->intended = intended;
}

Student *AddRequest::getStudent() const {
    return student;
}

Class *AddRequest::getIntendedClass() const {
    return intended;
}

bool AddRequest::isPossible() const {

    unsigned tmpMax = intended->getUc()->getMaxClassStudents();
    unsigned maxStudents = tmpMax + (intended->countStudents() == tmpMax);
    unsigned minStudents = min(intended->getUc()->getMinClassStudents(intended), intended->countStudents() + 1);
    if (intended->countStudents() >= 30) return false;
    if (maxStudents - minStudents >= 4 && intended->countStudents() >= maxStudents - 4) return false;

    for (Slot *slot : intended->getSlots())
        for (Class *c2 : student->getClasses())
            for (Slot *slot2 : c2->getSlots())
                if (slot->overlaps(*slot2)) return false;
    return true;
}


