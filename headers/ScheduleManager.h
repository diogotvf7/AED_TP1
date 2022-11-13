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

class ScheduleManager {

public:
    /**
     * @brief Constructor for the Schedule Manager's class.
     * Runs the input reading functions;
     */
    explicit ScheduleManager(const std::string &path);
    /**
     * Get function for the UC's vector;
     * @param optional parameter that filtrates a specific year
     * @return returns a vector<UC*> with all the info read from the input file;
     */
    std::vector<UC*> getUcVector(int year = 0) const;
    /**
     * @brief Get function for the Class's Vector;
     * @param optional parameter that filtrates a specific year
     * @return returns a vector<Class*> with all the info read from the input the file;
     */
    std::vector<Class*> getClassesVector(int year = 0) const;
    /**
     * @brief Get function for the StudentsByCode Set;
     * @return returns a set<Student*,StudentCodeCmp> with all the info read from the input file;
     */
    std::set<Student*,StudentCodeCmp> getStudentsByCodeSet() const;
    /**
     * @brief Get function for the StudentsByName Set;
     * @return returns a set<Student*,StudentNameCmp> with all the info read from the input file;
     */
    std::set<Student*,StudentNameCmp> getStudentsByNameSet() const;
    /**
     * @brief Function that finds a Student by Code in the Student's set;
     * Complexity: O(log(n))
     * @param code a string with the Code to look for;
     * @return returns a pointer to the Student in case he was found, returns nullptr otherwise;
     */
    Student *findStudentByCode(const std::string &code) const;
    /**
     * @brief Function that finds a Student by name in the Student's set;
     * Complexity: O(log(n))
     * @param name a the Name to look for;
     * @return returns a pointer to the Student in case he was found, returns nullptr otherwise;
     */
    Student *findStudentByName(const std::string &name) const;
    /**
     * @brief Function that finds a Class in the Class's vector;
     * Complexity: O(n)
     * @param ucCode a string with the UC code to look for;
     * @param classCode a string with the Class code to look for;
     * @return returns a pointer to the Class in case it was found, returns nullptr otherwise;
     */
    Class *findClass(const std::string &ucCode, const std::string &classCode) const;
    /**
     * @brief Function that finds a UC in the UC's vector;
     * Complexity: O(n)
     * @param ucCode a string with the UC code to look for;
     * @return return a pointer to the UC in case it was found, returns nullptr otherwise;
     */
    UC *findUc(const std::string &ucCode) const;
    /**
     * @brief Function that creates a Request and adds it to the respective Queue;
     * @param r a pointer to the Request that is being pushed to the Queue;
     */
    void createRequest(Request *r);
    /**
     * @brief Function that calls 'processStatusRequests()' and 'processRegularRequests()'
     */
    void processRequests();
    /**
     * @brief Function that processes Requests from Students with status;
     */
    void processStatusRequests();
    /**
     * @brief Function that processes Requests from regular Students;
     */
    void processRegularRequests();
    /**
     * @brief Function that implements the changes of an AddRequest if it is possible;
     * @param ar a pointer to the Request;
     */
    static void processAddRequest(AddRequest *ar);
    /**
     * @brief Function that implements the changes of a RemoveRequest if it is possible;
     * @param rr a pointer to the Request;
     */
    static void processRemoveRequest(RemoveRequest *rr);
    /**
     * @brief Function that implements the changes of a SwitchRequest if it is possible;
     * @param sr a pointer to the Request;
     */
    static void processSwitchRequest(SwitchRequest *sr);
    /**
     * @brief Function that implements the changes of a SwapRequest if it is possible;
     * @param sr a pointer to the Request;
     */
    static void processSwapRequest(SwapRequest *sr);
    /**
     * @brief Reads the 'data/input/classes_per_uc.csv' file and stores the input in vector<Uc*> ucs;
     */
    void readClassesPerUcFile();
    /**
     * @brief Reads the 'data/input/classes.csv' file and stores the input in vector<Class*> classes;
     */
    void readClassesFile();
    /**
     * @brief Reads the 'data/input/students_classes.csv' or 'data/input/students_classes_edited.csv' (depending on initial choice) file and stores the input in set<Student*,StudentCodeCmp> studentsByCode and set<Student*,StudentNameCmp> studentsByName;
     */
    void readStudentsClassesFile(const std::string &path);
    /**
     * @brief Writes the changes made by the processed Requests to '/data/output/failed_request_log';
     */
    void writeChanges();
private:
    std::vector<UC*> ucs;
    std::vector<Class*> classes;
    std::set<Student*,StudentCodeCmp> studentsByCode;
    std::set<Student*,StudentNameCmp> studentsByName;
    std::queue<Request*> regularRequests;
    std::queue<Request*> statusRequests;
};


#endif //AED_TP1_SCHEDULEMANAGER_H
