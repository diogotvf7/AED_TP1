//
// Created by diogotvf7 on 27-10-2022.
//

#include <iomanip>
#include <cmath>
#include <ostream>
#include <map>
#include <string>

#include "../headers/Slot.h"

using namespace std;

Slot::Slot(std::string weekday, std::string start, std::string duration, std::string type) {

    this->weekday = weekday;
    this->start = stof(start,  nullptr);
    this->duration = stof(duration, nullptr);
    this->type = type;
}

string Slot::getWeekday() const {
    return weekday;
}

float Slot::getStart() const {
    return start;
}

float Slot::getDuration() const {
    return duration;
}

string Slot::getType() const {
    return type;
}

bool Slot::overlaps(const Slot &s) {
    if (type == "T" || s.type == "T")
        return false;
    return (weekday == s.weekday) && ((start < s.start + s.duration) && (s.start < start + duration));
}

bool Slot::operator<(const Slot &s) const {

    map<string, int> weekdays = {{"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5}};

    return weekdays[weekday] < weekdays[s.weekday] || (weekdays[weekday] == weekdays[s.weekday] && start < s.start);
}

ostream &operator<<(std::ostream& os, const Slot& s) {

    float startHours; float startMinutes = modf(s.start, &startHours) * 60;
    ostringstream startOss; startOss << setfill('0') << right << setw(2) << startHours << ':' << setw(2) << left << startMinutes;
    float endHours; float endMinutes = modf(s.start + s.duration, &endHours) * 60;
    ostringstream endOss; endOss << setfill('0') << right << setw(2) << endHours << ':' << setw(2) << left << endMinutes;

    os << setfill(' ') << left << setw(15) << s.weekday << setw(15) << startOss.str() << setw(15) << endOss.str() << setw(15) << s.type << endl;
    return os;
}