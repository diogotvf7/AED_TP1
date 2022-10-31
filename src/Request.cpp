//
// Created by Johnny on 31/10/2022.
//

#include "Request.h"

Request::Request(const Student &student , const std::vector<Class> &classes1 ,const std::vector<Class> &classes2 , std::string typeofrequest){
    this->student = student;
    this->classes1 = classes1;
    this->classes1 = classes2;
    this->typeOfRequest = typeOfRequest;
}

const Student &Request::getStudent() const {
    return student;
}

const std::vector<Class> &Request::getStudentClasses1() const {
    return classes1;
}
const std::vector<Class> &Request::getStudentClasses2() const {
    return classes2;
}

const std::string &Request::getTypeOfRequest() const {
    return typeOfRequest;
}
