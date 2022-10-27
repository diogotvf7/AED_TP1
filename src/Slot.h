//
// Created by diogotvf7 on 27-10-2022.
//

#ifndef AED_TP1_SLOT_H
#define AED_TP1_SLOT_H

class Slot {

public:
    Slot(std::string weekday, std::string start, std::string duration, std::string type);

    int getWeekday() const;
    float getStart() const;
    float getDuration() const;
    std::string getType() const;

    bool operator<(const Slot &s) const;

private:
    int weekday;
    float start;
    float duration;
    std::string type;
};


#endif //AED_TP1_SLOT_H
