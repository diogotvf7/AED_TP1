//
// Created by diogotvf7 on 03-11-2022.
//

#ifndef AED_TP1_SWAPREQUEST_H
#define AED_TP1_SWAPREQUEST_H

#include "Oopsie.h"
#include "Student.h"
#include "Class.h"
#include "Request.h"
#include "Slot.h"

class SwapRequest : public Request {

public:

    /**
     * @brief Constructor for a Request of type Swap;
     * @param student pointer for the Student who placed the request;
     * @param colleague pointer for the Student with whom the request will be made;
     * @param current pointer for the Student's current Class;
     * @param intended pointer for the Student's intended Class;
     */
    SwapRequest(Student *student, Student *colleague, Class *current, Class *intended);
    /**
     * @brief Get function for the Student's pointer;
     * @return a pointer to the Student object;
     */
    Student *getStudent() const override;
    /**
     * @brief Get function for the colleague's pointer;
     * @return a pointer to the colleague object;
     */
    Student *getColleague() const;
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
     * @brief Function that checks if a class Swap between two students is possible;
     * @return return true if the swap is possible; returns false otherwise.
     */
    bool isPossible() const override;
private:
    Student *student;
    Student *colleague;
    Class *current;
    Class *intended;
};


#endif //AED_TP1_SWAPREQUEST_H
