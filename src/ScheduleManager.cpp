//
// Created by diogotvf7 on 27-10-2022.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "ScheduleManager.h"

using namespace std;

ScheduleManager::ScheduleManager() {
    readClassesFile();
    readStudentsFile();
}

vector<Class> ScheduleManager::getClassesVector() const {
    return classes;
}

set<Student, StudentCmp> ScheduleManager::getStudentsSet() const {
    return students;
}

Student ScheduleManager::findStudent(string code, const string &name) const {
    auto i = students.find(Student(code, name));
    if (i == students.end())
        throw invalid_argument("No Student with that code!");
    if (i->getName() != name)
        throw invalid_argument("Code and Name do not match!");
    return *i;
}

void ScheduleManager::readClassesFile() {

    ifstream in("../data/input/classes.csv");
    string line;

    getline(in, line); // Ignore first line

    while (getline(in, line)) {

        string classCode, ucCode, weekday, start, duration, type;

        stringstream input(line);

        getline(input, classCode, ',');
        getline(input, ucCode, ',');
        getline(input, weekday, ',');
        getline(input, start, ',');
        getline(input, duration, ',');
        getline(input, type, '\r');

        auto i = find_if(classes.begin(), classes.end(),[classCode, ucCode](const Class &c) { return c.getClassCode() == classCode && c.getUcCode() == ucCode; });

        if (i == classes.end()) {

            Class c(classCode, ucCode);
            c.addSlot(Slot(weekday, start, duration, type));
            classes.push_back(c);

        } else {

            i->addSlot(Slot(weekday, start, duration, type));
        }
    }
}





void ScheduleManager::readStudentsFile() {

    ifstream in("../data/input/students_classes.csv");
    string line;

    getline(in, line); // Ignore first line

    string previousCode = "0";
    Student previousStudent = Student("0", "D");

    while (getline(in, line)) {

        string code, name, ucCode, classCode;

        stringstream input(line);

        getline(input, code, ',');
        getline(input, name, ',');
        getline(input, ucCode, ',');
        getline(input, classCode, '\r');

        auto i = find_if(classes.begin(), classes.end(),[classCode, ucCode](const Class &c) { return c.getClassCode() == classCode && c.getUcCode() == ucCode; });


        if (code == previousCode) {

            previousStudent.addClass(*i);
        } else {
            if (previousStudent.getCode() != 0)
                students.insert(previousStudent);
            previousStudent = Student(code, name);
            previousStudent.addClass(*i);
        }
        previousCode = code;
    }
    students.insert(previousStudent);
}


void ScheduleManager::addRequest(  std::string typeofrequest , const Student &student ,
                                   const std::vector<Class> classes1 = {}, const std::vector<Class> classes2 = {}) {
    requests.push(Request(student , classes1 , classes2 , typeofrequest));
}

void ScheduleManager::processRequests() {
    while(!requests.empty()){
        Request request = requests.front();
        if (request.getTypeOfRequest() == "Remove Student "){
            Class studentclass = request.getStudentClasses1().front();
            Student student  = request.getStudent();
            removeStudent( student , studentclass );
        }
        else if (request.getTypeOfRequest() == "Add Student"){
            addStudent();
        }
        else if (request.getTypeOfRequest() == "Change Student Class"){
            changeStudentClass();
        }
        else if (request.getTypeOfRequest() == "Change Student Classes"){
            changeStudentClasses();
        }
        else{
            cout << "Invalid Input" ;
        }
        requests.pop();
    }
}

void ScheduleManager::removeStudent(Student &student, Class studentclass) {

}






