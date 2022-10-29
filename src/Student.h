//
// Created by joaob on 29/10/2022.
//
#include <string>

#include "Class.h"

#ifndef AED_TP1_MASTER_STUDENT_H
#define AED_TP1_MASTER_STUDENT_H


class Student {


public:

    Student(int number , std::string name );


    int getNumber() const;

    const std::string &getName() const;

    const std::list<Class> &getClasses() const;


private:
    int number;
    std::string name ;
    std::list<Class> classes;

};


#endif //AED_TP1_MASTER_STUDENT_H
