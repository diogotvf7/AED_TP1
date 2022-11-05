//
// Created by diogotvf7 on 04-11-2022.
//

#ifndef AED_TP1_MENU_H
#define AED_TP1_MENU_H

#include <iomanip>
#include <algorithm>
#include <map>

#include "ScheduleManager.h"


class Menu {

public:
    explicit Menu(ScheduleManager *sm);
    void run();
    void mainMenu();
    void ucMenu();
    void ucClassMenu(UC *uc);
    static void cleanTerminal() ;

private:
    ScheduleManager *sm;
    std::map<std::string,std::string> ucConfig;
    std::map<std::string,std::string> classConfig;
    std::string status;

};


#endif //AED_TP1_MENU_H
