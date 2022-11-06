//
// Created by diogotvf7 on 27-10-2022.
//

#ifndef AED_TP1_SCHEDULEMANAGER_H
#define AED_TP1_SCHEDULEMANAGER_H

#include <fstream>
#include <vector>
#include <set>
#include <queue>

#include "Student.h"
#include "UC.h"
#include "Request.h"
#include "AddRequest.h"
#include "SwitchRequest.h"
#include "SwapRequest.h"
#include "RemoveRequest.h"

struct StudentCodeCmp {
    bool operator() (Student *lhs, Student *rhs) const {
        return lhs->getCode() < rhs->getCode();
    }
};

struct StudentNameCmp {
    bool operator() (Student *lhs, Student *rhs) const {
        return lhs->getName() < rhs->getName();
    }
};

struct StudentNumberOfClassesCmp {
    bool operator() (Student *lhs, Student *rhs) const {
        return lhs->countClasses() < rhs->countClasses();
    }
};

class ScheduleManager {

public:
    /**
     * @brief Constructor for the Schedule Manager's class.
     * Runs the input reading functions;
     */
    ScheduleManager();
    /**
     * Get function for the UC's vector;
     * @return a vector<UC*> with all the UCs pointers from the input file;
     */
    std::vector<UC*> getUcVector() const;
    /**
     * @brief Get function for the Class's Vector;
     * @return a vector<Class*> with all the Classes pointers from input the file;
     */
    std::vector<Class*> getClassesVector() const;
    /**
     * @brief Get function for the Students By Code Set;
     * @return a set<Student*,StudentCodeCmp> with all the Students pointers from the input file;
     */
    std::set<Student*,StudentCodeCmp> getStudentsByCodeSet() const;
    /**
     * @brief Get function for the Students By Name Set;
     * @return a set<Student*,StudentNameCmp> with all the Students pointers from the input file;
     */
    std::set<Student*,StudentNameCmp> getStudentsByNameSet() const;
    /**
     * @brief Get function for the Students By Number of Classes Set;
     * @return a set<Student*,StudentNumberOfClassesCmp> with all the Students pointers from the input file;
     */
    std::set<Student*,StudentNumberOfClassesCmp> getStudentsByNumberOfClassesSet() const;
    /**
     * @brief Function that finds a Student by Code in the Student's set;
     * @param code the Code to look for;
     * @return returns a reference to the Student in case it finds him, returns nullptr otherwise;
     */
    Student *findStudentByCode(const std::string &code) const;
    /**
     * @brief Function that finds a Student by name in the Student's set;
     * @param name the Name to look for;
     * @return returns a reference to the Student in case it finds him, returns nullptr otherwise;
     */
    Student *findStudentByName(const std::string &name) const;
    //TODO
    Class *findClass(const std::string &ucCode, const std::string &classCode) const;

    void createRequest(Request *r);
    void processRequests();
    void processStatusRequests();
    void processRegularRequests();
    static void processAddRequest(AddRequest *ar);
    static void processRemoveRequest(RemoveRequest *rr);
    static void processSwitchRequest(SwitchRequest *sr);
    static void processSwapRequest(SwapRequest *sr);
    /**
     * @brief Reads the classes_per_uc.csv file and stores the input in vector<Uc> ucs;
     */
    void readClassesPerUcFile();
    /**
     * @brief Reads the classes.csv file and stores the input in vector<Class> classes;
     */
    void readClassesFile();
    /**
     * @brief Reads the students_classes.csv file and stores the input in set<Student> students;
     */
    void readStudentsClassesFile();

    void writeClassesPerUcFile();
    void writeClassesFile();
    void writeStudentsClassesFile();
private:
    std::vector<UC*> ucs;
    std::vector<Class*> classes;
    std::set<Student*,StudentCodeCmp> studentsByCode;
    std::set<Student*,StudentNameCmp> studentsByName;
    std::set<Student*,StudentNumberOfClassesCmp> studentsByNumberOfClasses;
    std::queue<Request*> regularRequests;
    std::queue<Request*> statusRequests;
};


#endif //AED_TP1_SCHEDULEMANAGER_H
