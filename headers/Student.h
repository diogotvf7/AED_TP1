//
// Created by diogotvf7 on 28-10-2022.
//

#ifndef AED_TP1_STUDENT_H
#define AED_TP1_STUDENT_H

#include <ostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

#include "Class.h"
#include "Request.h"

class Class;
class UC;

class Student {

public:
    /**
     * @brief Constructor for the Student class;
     * @param code string for the Student's code which will be converted to an int;
     * @param name string for the Student's name;
     * @param status boolean that determines whether a Student has a special status or not (default is false);
     */
    Student(const std::string& code, std::string name, bool status = false);
    /**
     * @brief Get function for the Student's Code;
     * @return returns an int with the Student's Code;
     */
    int getCode() const;
    /**
     * @brief Get function for the Student's name;
     * @return returns a string with the Student's name;
     */
    std::string getName() const;
    /**
     * @brief Get function for the Student's Classes;
     * @param optional parameter that filtrates a specific year
     * @return returns a vector with all the Student's Classes;
     */
    std::vector<Class*> getClasses(int year = 0) const;
    /**
     * @brief Get function for the Student's Status;
     * @return returns the bool value of Status;
     */
    bool getStatus() const;
    /**
     * @brief Set function for the Student's Status;
     * @param s boolean value to be assigned to the Student's Status;
     */
    void setStatus(bool s);
    /**
     * @brief Function to check how many Classes the Student has;
     * @return returns the size of vector<Class*> classes in an unsigned value;
     */
    unsigned countClasses() const;
    /**
     * @brief Function that adds a Class to the Student's classes;
     * @param c the Class to be added;
     */
    void addClass(Class *c);
    /**
     * @brief Function that removes a Class from the Student's classes;
     * @param c the Class to be removed;
     */
    void removeClass(Class *c);
    /**
     * @brief Function that checks if a Student is in a specific Class;
     * @param c the class in question;
     * @return returns true if the Student is in the class c; returns false otherwise;
     */
    bool isInClass(Class *c) const;
    /**
     * @brief Function that checks if a Student is in a specific UC;
     * @param uc the uc in question;
     * @return returns true if the Student is in the UC uc; returns false otherwise;
     */
    bool isInUc(UC *uc) const;

private:
    int code;
    std::string name;
    bool status;
    std::vector<Class*> classes;
};


#endif //AED_TP1_STUDENT_H
