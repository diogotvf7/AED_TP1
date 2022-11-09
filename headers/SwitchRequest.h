//
// Created by diogotvf7 on 03-11-2022.
//

#ifndef AED_TP1_SWITCHREQUEST_H
#define AED_TP1_SWITCHREQUEST_H

#include "Oopsie.h"
#include "Request.h"
#include "Student.h"
#include "Class.h"
#include "Slot.h"

class SwitchRequest : public Request {

public:
    /**
     * @brief Constructor for a Request of type Switch;
     * @param student pointer to the Student who placed the request;
     * @param current pointer for the Student's current Class;
     * @param intended pointer for the Student's intended Class;
     */
    SwitchRequest(Student *s, Class *current, Class *intended);
    /**
     * @brief Get function for the Student's pointer;
     * @return a pointer to the Student object;
     */
    Student *getStudent() const override;
    /**
     * @brief Get function for the current Class's pointer;
     * @return a pointer to the current Class object;
     */
    Class *getCurrentClass() const;
    /**
     * @brief Get function for the intended Class's pointer;
     * @return a pointer to the intended Class object;
     */
    Class *getIntendedClass() const;
    /**
     * @brief Function that checks if a class Switch between two classes is possible (attends to classes imbalance, full classes, etc.);
     * @return return true if the switch is possible; returns false otherwise.
     */
    bool isPossible() const override;
private:
    Student *student;
    Class *current;
    Class *intended;
};

#endif //AED_TP1_SWITCHREQUEST_H
