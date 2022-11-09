//
// Created by diogotvf7 on 01-11-2022.
//

#ifndef AED_TP1_REQUEST_H
#define AED_TP1_REQUEST_H

#include "Student.h"

class Student;

class Request {

public:
    /**
     * @brief Get function for the Student's pointer;
     * @return a pointer to the Student object;
     */
    virtual Student *getStudent() const = 0;
    /**
     * @brief Get Function for the Request's type;
     * @return returns a string with the Request's type;
     */
    virtual std::string getType() const = 0;
    /**
     * @brief Function that checks if a Request is possible;
     * @return return true if the request is possible; returns false otherwise.
     */
    virtual bool isPossible() const = 0;
};

#endif //AED_TP1_REQUEST_H
