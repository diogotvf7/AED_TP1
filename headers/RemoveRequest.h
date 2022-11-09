//
// Created by diogotvf7 on 02-11-2022.
//

#ifndef AED_TP1_REMOVEREQUEST_H
#define AED_TP1_REMOVEREQUEST_H
#include "Request.h"
#include "Student.h"
#include "Class.h"
#include "Slot.h"

class RemoveRequest : public Request {

public:

    /**
     * @brief Constructor for a Request of type Remove;
     * @param s pointer for the Student who placed the request;
     * @param c pointer for the Student's current Class;
     */
    RemoveRequest(Student *s, Class *c);
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
     * @brief Function that checks if it is possible to Remove a class to a student;
     * @return return true if the remove is possible; returns false otherwise.
     */
    bool isPossible() const override;
    
private:
    Student *student;
    Class *current;
};


#endif //AED_TP1_REMOVEREQUEST_H
