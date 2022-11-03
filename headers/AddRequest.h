//
// Created by diogotvf7 on 02-11-2022.
//

#ifndef AED_TP1_ADDREQUEST_H
#define AED_TP1_ADDREQUEST_H

#include "Request.h"
#include "Student.h"
#include "Class.h"
#include "Slot.h"

class AddRequest : public Request {

public:
    /**
     * @brief Constructor for the AddRequest class;
     * @param student pointer to the Student who placed the request;
     * @param intended pointer to the Class the Student wants to join;
     */
    AddRequest(Student *sstudent, Class *intended);
    /**
     * @brief Get function for the AddRequest's Student pointer;
     * @return returns a pointer to the Student who placed the request;
     */
    Student *getStudent() const;
    /**
     * @brief Get function for the AddRequest's Class pointer;
     * @return returns a pointer to the Class the Student wants to join;
     */
    Class *getIntendedClass() const;
    /**
     * @brief Function that checks if the AddRequest is possible or not.
     * This function attends to the maximum of students in a class (30) and tries to create balance in the number of students in all Class's of an UC;
     * It will not be possible to add a student to a Class if there is a gap greater or equal to 4 between the students of the Class with the most Students and the Class with the least Students and the requested Class has three less Students than the Class with the most Students or less;
     * @return returns false if there are 30 or more students in the requested class, if adding the Student would spoil the UC balance or if the Class overlaps with at least one of the Student's Classes;
     */
    bool isPossible() const;
private:
    Student *student;
    Class *intended;
};

#endif //AED_TP1_ADDREQUEST_H
