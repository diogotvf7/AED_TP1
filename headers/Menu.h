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

    /**
     * @brief Constructor for the Menu Object;
     * @param sm reads the Schedule Manager;
     */
    explicit Menu(ScheduleManager *sm);

    /**
     * @brief Method to get the UCs
     * @return return a vector with all UCs;
     */
    std::vector<UC*> getUcs();

    /**
     * @brief Method to get the Classes of an UC or a Student;
     * @param uc to get the respective classes;
     * @param s to get the respective classes
     * @return return a vector with the respective Classes;
     */
    std::vector<Class*> getClasses(UC *uc = nullptr, Student *s = nullptr);

    /**
     * @brief Method to get the Students of a Class
     * @param c respective Class
     * @return return a vector with all Students of a Class;
     */
    std::vector<Student*> getStudents(Class *c);

    /**
     * @brief Run the menu
     */
    void run();

    /**
     * @brief Run the main menu
     */
    void mainMenu();

    /**
     * @brief Run the UC menu
     */
    void ucMenu();

    /**
     * @brief Run the Class Menu
     */
    void classMenu();

    /**
     * @brief Run the Student Menu
     */
    void studentMenu();

    /**
     * @brief Run the Uc Class Menu
     * @param uc the respective Uc
     */
    bool ucClassMenu(UC *uc);

    /**
     * @brief Run the Class Student menu
     * @param c the respective Class
     */
    bool classStudentMenu(Class *c);

    /**
     * @brief Run the Student Menu
     * @param s the respective Student
     */
    bool studentMenu(Student *s);

    /**
     * @brief Run the Add Request menu
     */
    void addRequest();
    /**
     * @brief Run the Remove Request menu
     */
    void removeRequest();
    /**
     * @brief Run the Switch Request menu
     */
    void switchRequest();
    /**
     * @brief Run the Swap Request menu
     */
    void swapRequest();
    /**
     * Run the Request Menu
     */
    void requestMenu();
    /**
     * @brief Run the ConfigUC Menu
     */
    void configUcMenu();
    /**
     * @brief Run the configClass Menu
     */
    void configClassMenu();
    /**
     *@brief Run the ConfigStudent Menu
     */
    void configStudentMenu();
    /**
     *@brief Run the Find Menu
     */
    void findMenu();
    /**
     *@brief Run the Config Menu
     */
    void configMenu();
    /**
     *@brief Close the Menu
     */
    void close();
    /**
     * @brief Clean the Terminal
     */
    static void cleanTerminal();

private:
    ScheduleManager *sm;
    std::map<std::string,std::string> ucPrintConfig;
    std::map<std::string,std::string> classPrintConfig;
    std::map<std::string,std::string> studentPrintConfig;
    std::string status;

};


#endif //AED_TP1_MENU_H
