//
// Created by diogotvf7 on 02-11-2022.
//

#ifndef AED_TP1_ADDREQUEST_H
#define AED_TP1_ADDREQUEST_H

#include "Oopsie.h"
#include "Request.h"
#include "Student.h"
#include "Class.h"
#include "Slot.h"

class AddRequest : public Request {

public:
    /**
     * @brief Constructor for a Request of type Add;
     * @param student pointer to the Student who placed the request;
     * @param intended pointer for the Student's intended Class;
     */
    AddRequest(Student *student, Class *intended);
    /**
     * @brief Get function for the Student's pointer;
     * @return a pointer to the Student object;
     */
    Student *getStudent() const override;
    /**
     * @brief Get function for the intended Class's pointer;
     * @return a pointer to the intended Class object;
     */
    Class *getIntendedClass() const;
    /**
     * @brief Function that checks if it is possible to Add a class to a student (attends to classes imbalance, full classes, etc.);
     * @return return true if the add is possible; returns false otherwise.
     */
    bool isPossible() const override;
private:
    Student *student;
    Class *intended;
};

#endif //AED_TP1_ADDREQUEST_H
