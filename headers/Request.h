//
// Created by diogotvf7 on 01-11-2022.
//

#ifndef AED_TP1_REQUEST_H
#define AED_TP1_REQUEST_H


#include <string>
#include <queue>
#include "Student.h"

class Request {

public:
    Request(const Student &student , const std::vector<Class> &classes1 ,
            const std::vector<Class> &classes2 , std::string typeofrequest);

    const Student &getStudent() const;

    const std::vector<Class> &getStudentClasses1() const;

    const std::vector<Class> &getStudentClasses2() const;

    const std::string &getTypeOfRequest() const;

private:
    Student student;
    std::vector<Class> classes1;
    std::vector<Class> classes2;
    std::string typeOfRequest;

};

#endif //AED_TP1_REQUEST_H
