//
// Created by diogotvf7 on 03-11-2022.
//

#include "SwapRequest.h"

SwapRequest::SwapRequest(Student *student1, Student *student2, Class *class1, Class *class2) {
    this->student1 = student1;
    this->student2 = student2;
    this->class1 = class1;
    this->class2 = class2;
}

Student *SwapRequest::getStudent1() const {
    return student1;
}

Student *SwapRequest::getStudent2() const {
    return student2;
}

Class *SwapRequest::getClass1() const {
    return class1;
}

Class *SwapRequest::getClass2() const {
    return class2;
}

bool SwapRequest::isPossible() const {

    for (Slot *slot1 : class1->getSlots())
        for (Class *c : student2->getClasses())
            for (Slot *slot2 : c->getSlots())
                if (slot1->overlaps(*slot2)) return false;
    for (Slot *slot1 : class2->getSlots())
        for (Class *c : student1->getClasses())
            for (Slot *slot2 : c->getSlots())
                if (slot1->overlaps(*slot2)) return false;
    return true;
}

