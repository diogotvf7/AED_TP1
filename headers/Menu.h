//
// Created by diogotvf7 on 04-11-2022.
//

#ifndef AED_TP1_MENU_H
#define AED_TP1_MENU_H

#include <iomanip>
#include <algorithm>
#include <list>
#include <vector>
#include <map>

#include "UC.h"
#include "Class.h"
#include "Student.h"
#include "ScheduleManager.h"

class Menu {

public:
    explicit Menu(ScheduleManager *sm);
    std::vector<UC*> getUcs();
    std::vector<Class*> getClasses(UC *uc = nullptr, Student *s = nullptr);
    std::vector<Student*> getStudents(Class *c);
    void run();
    void mainMenu();
    void ucMenu();
    void classMenu();
    void studentMenu();
    bool ucClassMenu(UC *uc);
    bool classStudentMenu(Class *c);
    bool studentMenu(Student *s);
    void addRequest();
    void removeRequest();
    void switchRequest();
    void swapRequest();
    void requestMenu();
    void configUcMenu();
    void configClassMenu();
    void configStudentMenu();
    void findMenu();
    void configMenu();
    void close();
    static void cleanTerminal();

private:
    ScheduleManager *sm;
    std::map<std::string,std::string> ucPrintConfig;
    std::map<std::string,std::string> classPrintConfig;
    std::map<std::string,std::string> studentPrintConfig;
    std::string status;

};


#endif //AED_TP1_MENU_H
