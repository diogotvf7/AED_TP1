//
// Created by diogotvf7 on 02-11-2022.
//

#include "AddRequest.h"

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

string AddRequest::getType() const {
    return "add";
}

bool AddRequest::isPossible() const {
    if (student->isInUc(intended->getUc())) throw Oopsie("Can't add " + intended->getUc()->getName() + ' ' +
                                                                 intended->getName() + " to " + student->getName() + "'s schedule because: " + student->getName() + " already is in this UC.");
    if (student->isInClass(intended)) throw Oopsie("Can't add " + intended->getUc()->getName() + ' ' +
                                                           intended->getName() + " to " + student->getName() + "'s schedule because: " + student->getName() + " already is in " +
                                                   intended->getUc()->getName() + ' ' + intended->getName() + '.');
    unsigned tmpMax = intended->getUc()->getMaxClassStudents();
    unsigned maxStudents = tmpMax + (intended->countStudents() == tmpMax);
    unsigned minStudents = min(intended->getUc()->getMinClassStudents(intended), intended->countStudents() + 1);
    if (intended->countStudents() >= 30) throw Oopsie("Can't add " + intended->getUc()->getName() + ' ' +
                                                              intended->getName() + " to " + student->getName() + "'s schedule because: " +
                                                      intended->getUc()->getName() + ' ' + intended->getName() + " is full.");
    if (!student->getStatus() && maxStudents - minStudents >= 4 && intended->countStudents() >= maxStudents - 4) throw Oopsie("Can't add " +
                                                                                                                              intended->getUc()->getName() + ' ' +
                                                                                                                                      intended->getName() + " to " + student->getName() + "'s schedule because: " + "Adding " + student->getName() + " to " +
                                                                                                                              intended->getUc()->getName() + ' ' +
                                                                                                                                      intended->getName() + " will cause imbalance in " +
                                                                                                                              intended->getUc()->getName() + ".");

    for (Slot *slot : intended->getSlots())
        for (Class *c : student->getClasses())
            for (Slot *slot2 : c->getSlots())
                if (slot->overlaps(*slot2)) throw Oopsie("Can't add " + intended->getUc()->getName() + ' ' +
                                                                 intended->getName() + " to " + student->getName() + "'s schedule because: " + student->getName() + "'s " +
                                                         c->getUc()->getName() + ' ' + c->getName() + " overlaps with " +
                                                         intended->getUc()->getName() + ' ' + intended->getName() + '.');
    return true;
}


