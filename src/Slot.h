//
// Created by diogotvf7 on 27-10-2022.
//

#ifndef AED_TP1_SLOT_H
#define AED_TP1_SLOT_H

#include <ostream>

class Slot {

public:
    /**
     * @brief Constructor for the Slot's class
     * @param weekday string for the Slot's weekday;
     * @param start string for the Slot's start hour which will be converted to a float;
     * @param duration string for the Slot's duration which will be converted to a float;
     * @param type string with the type of the Slot (T, TP or PL)
     */
    Slot(std::string weekday, std::string start, std::string duration, std::string type);
    /**
     * @brief Get function for the Slot's Weekday;
     * @return returns a string with the Slot's weekday;
     */
    std::string getWeekday() const;
    /**
     * @brief Get function for the Slot's Start Hour;
     * @return returns a float with the Slot's start hour;
     */
    float getStart() const;
    /**
     * @brief Get function for the Slot's Duration;
     * @return return a float with the Slot's duration;
     */
    float getDuration() const;
    /**
     * @brief Get function for the Slot's Type;
     * @return returns a string with the Slot's Type;
     */
    std::string getType() const;
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
