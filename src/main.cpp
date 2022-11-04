#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../headers/ScheduleManager.h"
#include "../headers/ScheduleManager.h"
#include "../headers/UC.h"
#include "../headers/Request.h"
#include "../headers/AddRequest.h"
#include "../headers/SwitchRequest.h"
#include "../headers/SwapRequest.h"
#include "Oopsie.h"

class Request;

using namespace std;

void testSlots() {

    cout << ":::::::::::::SLOTS TESTS:::::::::::::\n";

    Slot s1("Wednesday", "10", "2", "T");
    Slot s2("Wednesday", "11", "1", "TP");
    Slot s3("Wednesday", "11", "1", "PL");
    Slot s4("Wednesday", "11.5", "1", "TP");

    cout << "Test 1: ";
    if (!s1.overlaps(s2)) cout << "passed" << endl;
    else cout << "failed" << endl;

    cout << "Test 2: ";
    if (!s1.overlaps(s3)) cout << "passed" << endl;
    else cout << "failed" << endl;

    cout << "Test 3: ";
    if (s2.overlaps(s3)) cout << "passed" << endl;
    else cout << "failed" << endl;

    cout << "Test 4: ";
    if (s2.overlaps(s4)) cout << "passed" << endl;
    else cout << "failed" << endl;
}

void testAddRequest() {

    cout << "::::::::::ADD REQUEST TESTS::::::::::\n";

    Student *s1 = new Student("202108752", "Diogo");
    UC *uc1 = new UC("AED");
    Class *class1 = new Class("Turma1", uc1);
    class1->addSlot(new Slot("Monday", "10", "3", "TP"));
    class1->addSlot(new Slot("Tuesday", "10.5", "3", "T"));
    s1->addClass(class1);

    UC *uc2 = new UC("LDTS");

    cout << "Test 1: ";
    Class *class2 = new Class("Turma2", uc2);
    class2->addSlot(new Slot("Monday", "11", "1", "TP"));
    class2->addSlot(new Slot("Friday", "6", "0", "T"));
    AddRequest ar1(s1, class2);
    try {
        ar1.isPossible();
        cout << "failed" << endl;
    } catch (Oopsie &e) {
        cout << "passed // " << e.what() << endl;
    }

    cout << "Test 2: ";
    Class *class3 = new Class("Turma3", uc2);
    class3->addSlot(new Slot("Monday", "10.5", "2", "PL"));
    class2->addSlot(new Slot("Friday", "6", "0", "T"));
    AddRequest ar2(s1, class3);
    try {
        ar2.isPossible();
        cout << "failed" << endl;
    } catch (Oopsie &e) {
        cout << "passed // " << e.what() << endl;
    }

    cout << "Test 3: ";
    Class *class4 = new Class("Turma3", uc2);
    class3->addSlot(new Slot("Monday", "0", "24", "T"));
    class2->addSlot(new Slot("Tuesday", "0", "24", "T"));
    class3->addSlot(new Slot("Wednesday", "0", "24", "T"));
    class2->addSlot(new Slot("Thursday", "0", "24", "T"));
    class3->addSlot(new Slot("Friday", "0", "24", "T"));
    AddRequest ar3(s1, class4);
    try {
        ar3.isPossible();
        cout << "passed" << endl;
    } catch (Oopsie &e) {
        cout << "failed // " << e.what() << endl;
    }

    UC *uc3 = new UC("BD"); Slot *slot1 = new Slot("", "0", "0", "T");
    Class *class23 = new Class("", uc3); class23->addSlot(slot1);
    for (int i = 0; i < 23; i++) class23->addStudent(new Student(to_string(i), to_string(i)));
    Class *class25 = new Class("", uc3); class25->addSlot(slot1);
    for (int i = 0; i < 25; i++) class25->addStudent(new Student(to_string(i), to_string(i)));
    Class *class26 = new Class("", uc3); class26->addSlot(slot1);
    for (int i = 0; i < 26; i++) class26->addStudent(new Student(to_string(i), to_string(i)));
    Class *class30 = new Class("", uc3); class30->addSlot(slot1);
    for (int i = 0; i < 30; i++) class30->addStudent(new Student(to_string(i), to_string(i)));

    cout << "Test 4: ";
    AddRequest ar4(s1, class23);
    try {
        ar4.isPossible();
        cout << "passed" << endl;
    } catch (Oopsie &e) {
        cout << "failed // " << e.what() << endl;
    }

    cout << "Test 5: ";
    AddRequest ar5(s1, class25);
    try {
        ar5.isPossible();
        cout << "passed" << endl;
    } catch (Oopsie &e) {
        cout << "failed // " << e.what() << endl;
    }

    cout << "Test 6: ";
    AddRequest ar6(s1, class26);
    try {
        ar6.isPossible();
        cout << "failed" << endl;
    } catch (Oopsie &e) {
        cout << "passed // " << e.what() << endl;
    }

    cout << "Test 7: ";
    AddRequest ar7(s1, class30);
    try {
        ar7.isPossible();
        cout << "failed" << endl;
    } catch (Oopsie &e) {
        cout << "passed // " << e.what() << endl;
    }

    UC *uc4 = new UC("BD"); Slot *slot2 = new Slot("", "0", "0", "T");
    Class *class25_ = new Class("", uc3); class25_->addSlot(slot2);
    for (int i = 0; i < 25; i++) class25_->addStudent(new Student(to_string(i), to_string(i)));
    Class *class26_ = new Class("", uc3); class26_->addSlot(slot2);
    for (int i = 0; i < 26; i++) class26_->addStudent(new Student(to_string(i), to_string(i)));
    Class *class30_ = new Class("", uc3); class30_->addSlot(slot2);
    for (int i = 0; i < 30; i++) class30_->addStudent(new Student(to_string(i), to_string(i)));

    cout << "Test 8: ";
    AddRequest ar8(s1, class25_);
    try {
        ar8.isPossible();
        cout << "passed" << endl;
    } catch (Oopsie &e) {
        cout << "failed // " << e.what() << endl;
    }
}

void testSwitchRequest() {

    cout << "::::::::SWITCH REQUEST TESTS:::::::::\n";

    Student *s1 = new Student("202108752", "Diogo");

    UC *uc3 = new UC("BD"); Slot *slot = new Slot("", "0", "0", "T");
    Class *class23 = new Class("", uc3); class23->addSlot(slot);
    for (int i = 0; i < 23; i++) class23->addStudent(new Student(to_string(i), to_string(i)));
    Class *class25 = new Class("", uc3); class25->addSlot(slot);
    for (int i = 0; i < 25; i++) class25->addStudent(new Student(to_string(i), to_string(i)));
    Class *class26 = new Class("", uc3); class26->addSlot(slot);
    for (int i = 0; i < 26; i++) class26->addStudent(new Student(to_string(i), to_string(i)));
    Class *class27 = new Class("", uc3); class27->addSlot(slot);
    for (int i = 0; i < 27; i++) class27->addStudent(new Student(to_string(i), to_string(i)));
    Class *class30 = new Class("", uc3); class30->addSlot(slot);
    for (int i = 0; i < 30; i++) class30->addStudent(new Student(to_string(i), to_string(i)));

    s1->addClass(class23);

    cout << "Test 1: ";
    SwitchRequest sr1(s1, class23, class25);
    try {
        sr1.isPossible();
        cout << "passed" << endl;
    } catch (Oopsie &e) {
        cout << "failed // " << e.what() << endl;
    }

    cout << "Test 2: ";
    SwitchRequest sr2(s1, class23, class26);
    try {
        sr2.isPossible();
        cout << "failed" << endl;
    } catch (Oopsie &e) {
        cout << "passed // " << e.what() << endl;
    }

    s1->removeClass(class23);
    s1->addClass(class30);

    cout << "Test 3: ";
    SwitchRequest sr3(s1, class30, class23);
    try {
        sr3.isPossible();
        cout << "passed" << endl;
    } catch (Oopsie &e) {
        cout << "failed // " << e.what() << endl;
    }

    cout << "Test 4: ";
    SwitchRequest sr4(s1, class30, class25);
    try {
        sr4.isPossible();
        cout << "passed" << endl;
    } catch (Oopsie &e) {
        cout << "failed // " << e.what() << endl;
    }

    cout << "Test 5: ";
    SwitchRequest sr5(s1, class30, class26);
    try {
        sr5.isPossible();
        cout << "passed" << endl;
    } catch (Oopsie &e) {
        cout << "failed // " << e.what() << endl;
    }

    s1->removeClass(class30);
    s1->addClass(class26);

    cout << "Test 6: ";
    SwitchRequest sr6(s1, class26, class27);
    try {
        sr6.isPossible();
        cout << "failed" << endl;
    } catch (Oopsie &e) {
        cout << "passed // " << e.what() << endl;
    }
}

void testSwapRequest() {

    cout << ":::::::::SWAP REQUEST TESTS::::::::::\n";

    UC *uc = new UC("Street");

    Student *s1 = new Student("0", "Diogo");
    Student *s2 = new Student("0", "Chico");
    Student *s3 = new Student("0", "Belchior");

    Class *c1 = new Class("Class1", uc); c1->addSlot(new Slot("Wednesday", "10", "2", "T"));
    Class *c2 = new Class("Class2", uc); c2->addSlot(new Slot("Wednesday", "11", "1", "TP"));
    Class *c3 = new Class("Class3", uc); c3->addSlot(new Slot("Wednesday", "11", "1", "TP"));
    Class *c4 = new Class("Class4", uc); c4->addSlot(new Slot("Wednesday", "11", "1", "PL"));

    s1->addClass(c1);
    s2->addClass(c2);
    s2->addClass(c3);
    s3->addClass(c4);

    cout << "Test 1: ";
    SwapRequest sr1(s1, s2, c1, c2);
    try {
        sr1.isPossible();
        cout << "passed" << endl;
    } catch (Oopsie &e) {
        cout << "failed // " << e.what() << endl;
    }

    cout << "Test 2: ";
    SwapRequest sr2(s1, s3, c1, c3);
    try {
        sr2.isPossible();
        cout << "passed" << endl;
    } catch (Oopsie &e) {
        cout << "failed // " << e.what() << endl;
    }

    cout << "Test 3: ";
    SwapRequest sr3(s2, s3, c2, c3);
    try {
        sr3.isPossible();
        cout << "failed" << endl;
    } catch (Oopsie &e) {
        cout << "passed // " << e.what() << endl;
    }
}

void testRequests(ScheduleManager *sm) {

    cout << "::::::::::::REQUEST TESTS::::::::::::\n";

    Student *s1 = new Student("200000000", "Lino Marcolino");
    string ucCode = "L.EIC015", classCode1 = "2LEIC01", classCode3 = "2LEIC03";
    auto class19 = find_if(sm->getClassesVector().begin(), sm->getClassesVector().end(), [ucCode, classCode1](Class *c){return ((c->getUc()->getUcCode() == ucCode) && (c->getClassCode() == classCode1));});
    auto class25 = find_if(sm->getClassesVector().begin(), sm->getClassesVector().end(), [ucCode, classCode3](Class *c){return ((c->getUc()->getUcCode() == ucCode) && (c->getClassCode() == classCode3));});
    sm->addRequest(new AddRequest(s1, *class19));
    sm->addRequest(new SwitchRequest(s1, *class19, *class25));
    sm->addRequest(new RemoveRequest(s1, *class25));

    Student *s2 = new Student("200000001", "Tiago Oliveira");

    sm->processRequests();

    while (!sm->getFailedRequests().empty()) {

        cout << sm->getFailedRequests().front() << endl;
        sm->getFailedRequests().pop();
    }
}

void runTests(ScheduleManager *sm) {
    testSlots();
    testAddRequest();
    testSwitchRequest();
    testSwapRequest();
    testRequests(sm);
}

int main() {

    ScheduleManager sm;

    runTests(&sm);
/*
    for (UC *uc : sm.getUCsVector())
        // cout << uc->getClasses().size() << endl;
        // cout << uc->getUcCode() << ":  " << uc->getMinClassStudents() << "   " << uc->getMaxClassStudents() << endl;
*/
    cout << '\n' << sm.getUCsVector().size() << ' ' << sm.getClassesVector().size() << ' ' << sm.getStudentsSet().size() << '\n';

    return 0;
}

