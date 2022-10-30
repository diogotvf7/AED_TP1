//
// Created by diogotvf7 on 27-10-2022.
//

#ifndef AED_TP1_SCHEDULEMANAGER_H
#define AED_TP1_SCHEDULEMANAGER_H

#include <vector>
#include "Class.h"

class ScheduleManager {

public:

    std::vector<Class> getClasses() const;
    void readClassesFile();

private:
    std::vector<Class> classes;
};


#endif //AED_TP1_SCHEDULEMANAGER_H