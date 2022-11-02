//
// Created by diogotvf7 on 01-11-2022.
//

#ifndef AED_TP1_UC_H
#define AED_TP1_UC_H

#include <string>
#include <vector>

#include "Class.h"

class Class;

class UC {

public:
    explicit UC(const std::string& ucCode);
    std::string getUcCode() const;
    std::vector<Class*> getClasses() const;
    void addClassToUc(Class *c);
private:
    std::string ucCode;
    std::vector<Class*> classes;
    unsigned minStudentsInClass;
    unsigned maxStudentsInClass;
};


#endif //AED_TP1_UC_H
