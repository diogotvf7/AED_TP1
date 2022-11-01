//
// Created by diogotvf7 on 01-11-2022.
//

#include "../headers/Request.h"

Request::Request(Student student , const std::vector<Class> &classes1 ,const std::vector<Class> &classes2 , std::string typeOfRequest){
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