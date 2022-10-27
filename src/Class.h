//
// Created by diogotvf7 on 27-10-2022.
//

#ifndef AED_TP1_CLASS_H
#define AED_TP1_CLASS_H

#include <string>
#include <list>
#include "Slot.h"

class Class {

public:
    Class(std::string classCode, std::string ucCode);

    std::string getClassCode() const;

    std::string getUcCode() const;

    void addSlot(const Slot &slot);

private:
    std::string classCode;
    std::string ucCode;
    std::list<Slot> slots;
};


#endif //AED_TP1_CLASS_H
