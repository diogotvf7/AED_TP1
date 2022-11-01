#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../headers/ScheduleManager.h"

using namespace std;

void testSlots() {

    Slot s1("Tuesday", "12.5", "0", "");
    Slot s2("Tuesday", "14", "0", "");
    Slot s3("Friday", "0", "0", "");
    Slot s4("Friday", "0", "0", "");
    Slot s5("Monday", "15", "0", "");

    cout << ":::::SLOT TESTS:::::\n";

    cout << "Test 1: ";
    if (s1 < s2) cout << "passed" << endl;
    else cout << "failed" << endl;

    cout << "Test 2: ";
    if (!(s3 < s5)) cout << "passed" << endl;
    else cout << "failed" << endl;

    cout << "Test 3: ";
    if (!(s3 < s4)) cout << "passed" << endl;
    else cout << "failed" << endl;

    cout << "Test 4: ";
    if ((s5 < s1)) cout << "passed" << endl;
    else cout << "failed" << endl;
}

void testStudents(const ScheduleManager &sm) {

    auto s1 = sm.findStudent("202071557","Ludovico");
    auto s3 = sm.findStudent("202027527","Renata");

    cout << ":::::STUDENT TESTS:::::" << endl;

    cout << "Test 1: ";
    if (s1.getClasses().size() == 4) cout << "passed" << endl;
    else cout << "failed" << endl;

    cout << "Test 2: ";
    try {
        auto s2 = sm.findStudent("202071557", "Wrong Name");
        cout << "failed" << endl;
    } catch (const invalid_argument &e) {
        cout << "passed" << endl;
    }

    cout << "Test 3: ";
    if (s3.getClasses() == list<Class>{Class("1LEIC13", "L.EIC003"), Class("1LEIC13","L.EIC004"), Class("1LEIC14", "L.EIC005")}) cout << "passed" << endl;
    else cout << "failed" << endl;

    cout << "Test 4: ";
    if (s3.getClasses() == list<Class>{Class("1LEIC13", "L.EIC001"), Class("1LEIC13","L.EIC004"), Class("1LEIC14", "L.EIC005")}) cout << "failed" << endl;
    else cout << "passed" << endl;

    cout << "Test 5: ";
    try {
        auto s2 = sm.findStudent("0", "Ludovico");
        cout << "failed" << endl;
    } catch (const invalid_argument &e) {
        cout << "passed" << endl;
    }
}

void testStudentsPrint(const ScheduleManager &sm) {

    cout << *sm.getStudentsSet().find(Student("201920727", "Ines")) << endl;
    cout << *sm.getStudentsSet().begin() << endl;
}

int main() {

    ScheduleManager sm;

    vector<Class> classes = sm.getClassesVector();
    for (const Class &c : classes)
        for (const Slot &s : c.getSlots())
            cout << s;

    set<Student, StudentCmp> students = sm.getStudentsSet();
    for (const auto & student : students)
        cout << ' ' << student.getCode() << endl;

    cout << '\n' << sm.getClassesVector().size() << ' ' << sm.getStudentsSet().size() << '\n';

    testSlots();
    testStudents(sm);
    testStudentsPrint(sm);

    return 0;
}
