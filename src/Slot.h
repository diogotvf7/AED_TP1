//
// Created by diogotvf7 on 27-10-2022.
//

#ifndef AED_TP1_SLOT_H
#define AED_TP1_SLOT_H

#include <ostream>

class Slot {

public:
    Slot(std::string weekday, std::string start, std::string duration, std::string type);

    std::string getWeekday() const;
    float getStart() const;
    float getDuration() const;
    std::string getType() const;

    bool operator<(const Slot &s) const;
    friend std::ostream& operator<<(std::ostream& os, const Slot& s);

private:
    std::string weekday;
    float start;
    float duration;
    std::string type;
};


#endif //AED_TP1_SLOT_H
