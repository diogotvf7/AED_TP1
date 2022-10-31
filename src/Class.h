//
// Created by diogotvf7 on 27-10-2022.
//

#ifndef AED_TP1_CLASS_H
#define AED_TP1_CLASS_H

#include <string>
#include <list>
#include "Slot.h"

class Class {

public:
    /**
     * @brief Constructor for Class's class;
     * @param classCode string for the Class's Code;
     * @param ucCode string for the US's Code;
     */
    Class(std::string classCode, std::string ucCode);
    /**
     * @brief Get function for the Class's Code;
     * @return returns a string with the Class's Code;
     */
    std::string getClassCode() const;
    /**
     * @brief Get function for the UC's Code;
     * @return returns a string with the UC's Code;
     */
    std::string getUcCode() const;
    /**
     * @brief Get functions for the Class's Slots;
     * @return returns a list with all the Slots occupied by the Class;
     */
    std::list<Slot> getSlots() const;
    /**
     * @bried Function that adds Slots to a Class;
     * @param slot the slot to be added;
     */
    void addSlot(const Slot &slot);
    /**
     * @brief Overload of operator== to check equality between Class objects;
     * @param c the right hand side Class;
     * @return return true if both Class objects have the same Class Code and UC Code, returns false otherwise;
     */
    bool operator==(const Class &c) const;
    /**
     * @brief Overload of operator<< to output Class's info;
     * @param os the output stream to which we want to output the Class's info;
     * @param s the Class that we want to output;
     * @return returns a reference to the original output stream;
     */
    friend std::ostream& operator<<(std::ostream& os, const Class& c);

private:
    std::string classCode;
    std::string ucCode;
    std::list<Slot> slots;
};


#endif //AED_TP1_CLASS_H
