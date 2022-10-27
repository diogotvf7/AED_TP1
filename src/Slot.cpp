//
// Created by diogotvf7 on 27-10-2022.
//

#include <string>
#include "Slot.h"

using namespace std;

Slot::Slot(std::string weekday, std::string start, std::string duration, std::string type) {

    if (weekday == "Monday")
            this->weekday = 0;
    else if (weekday == "Tuesday")
            this->weekday = 1;
    else if (weekday == "Wednesday")
            this->weekday = 2;
    else if (weekday == "Thursday")
            this->weekday = 3;
    else if (weekday == "Friday")
            this->weekday = 4;

    this->start = stof(start,  nullptr);
    this->duration = stof(duration, nullptr);
    this->type = type;
}

int Slot::getWeekday() const {
    return weekday;
}
float Slot::getStart() const {
    return start;
}
float Slot::getDuration() const {
    return duration;
}
std::string Slot::getType() const {
    return type;
}

bool Slot::operator<(const Slot &s) const {

    return weekday < s.weekday || (weekday == s.weekday && start < s.start);
}