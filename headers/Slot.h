//
// Created by diogotvf7 on 27-10-2022.
//

#ifndef AED_TP1_SLOT_H
#define AED_TP1_SLOT_H

#include <ostream>
#include <string>



class Slot {

public:
    /**
     * @brief Constructor for Slot object;
     * @param weekday string for the Slot's weekday;
     * @param start string for the Slot's start hour which will be converted to a float;
     * @param duration string for the Slot's duration which will be converted to a float;
     * @param type string with the type of the Slot (T, TP or PL)
     */
    Slot(const std::string &weekday, const std::string& start, const std::string &duration, const std::string &type);
    /**
     * @brief Get function for the Slot's Type;
     * @return returns a string with the Slot's Type;
     */
    std::string getType() const;
    /**
     * @brief Function that checks if there is overlap between to Slots;
     * @param s the right hand side Slot;
     * @return returns true if there is overlap between TP-TP, PL-PL, or TP-PL classes, returns false otherwise;
     */
    bool overlaps(const Slot &s);
    /**
     * @brief Overload of operator< to check if lhs Slot starts before rhs Slot
     * @param s the right hand side Slot;
     * @return returns true if the lhs Slot starts before the rhs Slot, returns false otherwise;
     */
    bool operator<(const Slot &s) const;
    /**
     * @brief Overload of operator<< to output Slot's info;
     * @param os the output stream to which we want to output the Slot's info;
     * @param s the Slot that we want to output;
     * @return returns a reference to the original output stream;
     */
    friend std::ostream& operator<<(std::ostream& os, const Slot& s);

private:
    std::string weekday;
    float start;
    float duration;
    std::string type;
};


#endif //AED_TP1_SLOT_H
