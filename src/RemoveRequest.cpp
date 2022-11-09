//
// Created by diogotvf7 on 02-11-2022.
//

#include "Oopsie.h"
#include "RemoveRequest.h"

using namespace std;

RemoveRequest::RemoveRequest(Student *s, Class *c) {
    this->student = s;
    this->current = c;
}

Student *RemoveRequest::getStudent() const {
    return student;
}

Class *RemoveRequest::getCurrentClass() const {
    return current;
}

string RemoveRequest::getType() const {
    return "remove";
}

bool RemoveRequest::isPossible() const {
    if (!student->isInClass(current)) throw Oopsie("Can't remove " + current->getUc()->getName() + ' ' +
                                                           current->getName() + " from " + student->getName() + "'s schedule because: " +
                                                   current->getUc()->getName() + ' ' + current->getName() + " already isn't in " + student->getName() + "'s schedule.");
    return true;
}

