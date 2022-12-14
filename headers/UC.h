//
// Created by diogotvf7 on 01-11-2022.
//

#ifndef AED_TP1_UC_H
#define AED_TP1_UC_H

#include <string>
#include <vector>

#include "Class.h"
#include "Student.h"

class Class;

class UC {

public:
    /**
     * @brief Constructor for the UC class;
     * @param ucCode string for the UC's code;
     */
    explicit UC(const std::string& ucCode);
    /**
     * @brief Get function for the UC's UC Code;
     * @return returns a string with the UC code;
     */
    std::string getName() const;
    /**
     * @brief Get function for the UC's Classes vector;
     * @param optional parameter that filtrates a specific year
     * @return returns a vector<Class*> with pointers to all the UC's classes;
     */
    std::vector<Class*> getClasses(int year = 0) const;
    /**
     * @brief Get function for the UC's year in the cycle of studies;
     * @return returns an int correspondent to the year;
     */
    int getYear() const;
    /**
     * @brief Funtion that counts the amount of Students in an UC;
     * @return returns an unsigned value for the total number of Students registered in the UC;
     */
    unsigned countStudents() const;
    /**
     * @brief Function to get the number of students of the class with the least students in the UC;
     * @param ignore optional parameter if any Class is to be ignored in the count;
     * @return returns an unsigned value for the number of Students of the class with the least students in the UC;
     */
    unsigned getMinClassStudents(Class *ignore = nullptr) const;
    /**
     * @brief Function to get the number of students of the class with the most students in the UC;
     * @param ignore optional parameter if any Class is to be ignored in the count;
     * @return returns an unsigned value for the number of students of the class with the most students in the UC;
     */
    unsigned getMaxClassStudents(Class *ignore = nullptr) const;
    /**
     * @brief Function that adds a Class to the UC;
     * @param c a pointer to the class to be added to the UC;
     */
    void addClass(Class *c);
private:
    std::string ucCode;
    std::vector<Class*> classes;
};


#endif //AED_TP1_UC_H
