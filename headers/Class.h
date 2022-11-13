//
// Created by diogotvf7 on 27-10-2022.
//

#ifndef AED_TP1_CLASS_H
#define AED_TP1_CLASS_H

#include <algorithm>
#include <string>
#include <list>
#include <vector>

#include "UC.h"
#include "Student.h"
#include "Slot.h"

class UC;
class Student;

class Class {

public:
    /**
     * @brief Constructor for the Class class.
     * This constructor calls the UC class function addClass(Class *c) with a pointer to this object as a parameter;
     * @param classCode string for the Class's Code;
     * @param uc the US's pointer;
     */
    Class(const std::string &classCode, UC *uc);
    /**
     * @brief Get function for the Class's Code;
     * @return returns a string with the Class's Code;
     */
    std::string getName() const;
    /**
     * @brief Get function for the UC's pointer;
     * @return returns a pointer to the Class's UC;
     */
    UC *getUc() const;
    /**
     * @brief Get function for the Class's Slots list;
     * @return returns a list with all the pointers to Slots occupied by the Class;
     */
    std::list<Slot*> getSlots() const;
    /**
     * @brief Get function for the Class's Students vector;
     * @return returns a vector with all the pointers from Student's who are in this Class;
     */
    std::vector<Student*> getStudents() const;
    /**
     * @brief Get function for the Class's year in the cycle of studies;
     * @return returns an int correspondent to the year;
     */
    int getYear() const;
    /**
     * @brief Function that adds Student pointers to vector<Student*> students;
     * @param s the Student pointer to be added;
     */
    void addStudent(Student *s);
    /**
     * @bried Function that adds Slot pointers to a Class;
     * @param slot the slot to be added;
     */
    void addSlot(Slot *slot);
    /**
     * @brief Function that removes Student pointers from the vector<Student*> students;
     * @param s the Student pointer to be deleted;
     */
    void removeStudent(Student *s);
    /**
     * @brief Function to check the size of the Class;
     * @return returns the size of vector<Student*> students as an unsigned value;
     */
    unsigned countStudents() const;
    /**
     * @brief Overload of operator== to check equality between Class objects;
     * @param c the right hand side Class;
     * @return return true if both Class objects have the same Class Code and UC Code, returns false otherwise;
     */
    bool operator==(const Class &c) const;

private:
    std::string classCode;
    UC *uc;
    std::list<Slot*> slots;
    std::vector<Student*> students;
};


#endif //AED_TP1_CLASS_H
