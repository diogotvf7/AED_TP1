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
    if (intended->countStudents() >= 30) throw Oopsie("Can't add " + intended->getUc()->getUcCode() + ' ' + intended->getClassCode() + " to " + student->getName() + "'s schedule because: " + intended->getUc()->getUcCode() + ' ' + intended->getClassCode() + " is full.");
    if (maxStudents - minStudents >= 4 && intended->countStudents() >= maxStudents - 4) throw Oopsie("Can't add " + intended->getUc()->getUcCode() + ' ' + intended->getClassCode() + " to " + student->getName() + "'s schedule because: " + "Adding " + student->getName() + " to " + intended->getUc()->getUcCode() + ' ' + intended->getClassCode() + " will cause imbalance in " + intended->getUc()->getUcCode() + ".");

    for (Slot *slot : intended->getSlots())
        for (Class *c : student->getClasses())
            for (Slot *slot2 : c->getSlots())
                if (slot->overlaps(*slot2)) throw Oopsie("Can't add " + intended->getUc()->getUcCode() + ' ' + intended->getClassCode() + " to " + student->getName() + "'s schedule because: " + student->getName() + "'s " + c->getUc()->getUcCode() + ' ' + c->getClassCode() + " overlaps with " + intended->getUc()->getUcCode() + ' ' + intended->getClassCode() + '.');
    return true;
}


