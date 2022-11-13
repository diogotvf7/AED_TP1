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
     * @brief Constructor for the Menu class;
     * @param sm a pointer to the Schedule Manager object;;
     */
    explicit Menu(ScheduleManager *sm);
    /**
     * @brief Method to get the UCs;
     * @return return a vector with all UCs;
     */
    std::vector<UC*> getUcs();
    /**
     * @brief Method to get the Classes of an UC or a Student;
     * @param uc if not nullptr, the function gets this UC's classes;
     * @param s if not nullptr, the function gets this Student's classes;
     * @return return a vector with the respective Classes;
     */
    std::vector<Class*> getClasses(UC *uc = nullptr, Student *s = nullptr);
    /**
     * @brief Method to get the Students of a Class vector;
     * @param c a pointer to the Class in question;
     * @return returns a vector with all the Students pointers of a Class;
     */
    std::vector<Student*> getStudents(Class *c);
    /**
     * @brief Runs the menu;
     */
    void run();
    /**
     * @brief Runs the main menu;
     */
    void mainMenu();
    /**
     * @brief Shows all the UC's;
     */
    void ucMenu();
    /**
     * @brief Shows all the Classes;
     */
    void classMenu();
    /**
     * @brief Shows all the Students;
     * @return return a pointer to the selected Student, returns nullptr if no student is selected;
     */
    Student * studentMenu();
    /**
     * @brief Shows a Student's Schedule;
     * @param s the Student in question;
     */
    bool studentClassesMenu(Student *s);
    /**
     * @brief Shows the classes from an UC;
     * @param uc the respective Uc
     */
    bool ucClassMenu(UC *uc);
    /**
     * @brief Shows the Student's of a Class;
     * @param c the Class in question;
     */
    bool classStudentMenu(Class *c);
    /**
     * @brief Runs the Add Request menu;
     */
    void addRequest();
    /**
     * @brief Runs the Remove Request menu;
     */
    void removeRequest();
    /**
     * @brief Runs the Switch Request menu;
     */
    void switchRequest();
    /**
     * @brief Runs the Swap Request menu;
     */
    void swapRequest();
    /**
     * Runs the Request Menu;
     */
    void requestMenu();
    /**
     * @brief Runs the UC configuration menu;
     */
    void configUcMenu();
    /**
     * @brief Runs the Class configuration menu;
     */
    void configClassMenu();
    /**
     *@brief Runs the Student configuration menu;
     */
    void configStudentMenu();
    /**
     *@brief Runs the find menu;
     */
    void findMenu();
    /**
     *@brief Runs the configurations menu;
     */
    void configMenu();
    /**
     *@brief Closes the menu and asks if the user wants to process and save the requests made;
     */
    void close();
    /**
     * @brief Cleans the Terminal;
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
