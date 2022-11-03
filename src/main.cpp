#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../headers/ScheduleManager.h"
#include "../headers/UC.h"
#include "../headers/Request.h"
#include "../headers/AddRequest.h"
#include "../headers/SwitchRequest.h"

class Request;

using namespace std;

void testSlots() {

    Slot s1("Tuesday", "12.5", "5", "T");
    Slot s2("Tuesday", "14", "2", "T");
    Slot s3("Friday", "0", "0", "");
    Slot s4("Friday", "0", "0", "");
    Slot s5("Monday", "15", "0", "");

    cout << "::::::::::::::SLOT TESTS:::::::::::::\n";

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

    Slot s6("Wednesday", "10", "2", "T");
    Slot s7("Wednesday", "11", "1", "TP");
    Slot s8("Wednesday", "11", "1", "PL");
    Slot s9("Wednesday", "11.5", "1", "TP");

    cout << "Test 5: ";
    if (!s6.overlaps(s7)) cout << "passed" << endl;
    else cout << "failed" << endl;

    cout << "Test 6: ";
    if (!s6.overlaps(s8)) cout << "passed" << endl;
    else cout << "failed" << endl;

    cout << "Test 7: ";
    if (s7.overlaps(s8)) cout << "passed" << endl;
    else cout << "failed" << endl;

    cout << "Test 8: ";
    if (s7.overlaps(s9)) cout << "passed" << endl;
    else cout << "failed" << endl;
}

void testAddRequest() {

    Student *s1 = new Student("202108752", "Diogo");
    UC *uc1 = new UC("AED");
    Class *class1 = new Class("Turma1", uc1);
    class1->addSlot(new Slot("Monday", "10", "3", "TP"));
    class1->addSlot(new Slot("Tuesday", "10.5", "3", "T"));
    s1->addClass(class1);

    cout << "::::::::::ADD REQUEST TESTS::::::::::\n";

    UC *uc2 = new UC("LDTS");

    cout << "Test 1: ";
    Class *class2 = new Class("Turma2", uc2);
    class2->addSlot(new Slot("Monday", "11", "1", "TP"));
    class2->addSlot(new Slot("Friday", "6", "0", "T"));
    AddRequest ar1(s1, class2);
    if (!ar1.isPossible()) cout << "passed" << endl;
    else cout << "failed" << endl;

    cout << "Test 2: ";
    Class *class3 = new Class("Turma3", uc2);
    class3->addSlot(new Slot("Monday", "10.5", "2", "PL"));
    class2->addSlot(new Slot("Friday", "6", "0", "T"));
    AddRequest ar2(s1, class3);
    if (!ar2.isPossible()) cout << "passed" << endl;
    else cout << "failed" << endl;

    cout << "Test 3: ";
    Class *class4 = new Class("Turma3", uc2);
    class3->addSlot(new Slot("Monday", "0", "24", "T"));
    class2->addSlot(new Slot("Tuesday", "0", "24", "T"));
    class3->addSlot(new Slot("Wednesday", "0", "24", "T"));
    class2->addSlot(new Slot("Thursday", "0", "24", "T"));
    class3->addSlot(new Slot("Friday", "0", "24", "T"));
    AddRequest ar3(s1, class4);
    if (ar3.isPossible()) cout << "passed" << endl;
    else cout << "failed" << endl;

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
    if (ar4.isPossible()) cout << "passed" << endl;
    else cout << "failed" << endl;

    cout << "Test 5: ";
    AddRequest ar5(s1, class25);
    if (ar5.isPossible()) cout << "passed" << endl;
    else cout << "failed" << endl;

    cout << "Test 6: ";
    AddRequest ar6(s1, class26);
    if (!ar6.isPossible()) cout << "passed" << endl;
    else cout << "failed" << endl;

    cout << "Test 7: ";
    AddRequest ar7(s1, class30);
    if (!ar7.isPossible()) cout << "passed" << endl;
    else cout << "failed" << endl;


    UC *uc4 = new UC("BD"); Slot *slot2 = new Slot("", "0", "0", "T");
    Class *class25_ = new Class("", uc3); class25_->addSlot(slot2);
    for (int i = 0; i < 25; i++) class25_->addStudent(new Student(to_string(i), to_string(i)));
    Class *class26_ = new Class("", uc3); class26_->addSlot(slot2);
    for (int i = 0; i < 26; i++) class26_->addStudent(new Student(to_string(i), to_string(i)));
    Class *class30_ = new Class("", uc3); class30_->addSlot(slot2);
    for (int i = 0; i < 30; i++) class30_->addStudent(new Student(to_string(i), to_string(i)));

    cout << "Test 8: ";
    AddRequest ar8(s1, class25_);
    if (ar8.isPossible()) cout << "passed" << endl;
    else cout << "failed" << endl;
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
    if (sr1.isPossible()) cout << "passed" << endl;
    else cout << "failed" << endl;

    cout << "Test 2: ";
    SwitchRequest sr2(s1, class23, class26);
    if (!sr2.isPossible()) cout << "passed" << endl;
    else cout << "failed" << endl;

    s1->removeClass(class23);
    s1->addClass(class30);

    cout << "Test 3: ";
    SwitchRequest sr3(s1, class30, class23);
    if (sr2.isPossible()) cout << "passed" << endl;
    else cout << "failed" << endl;

    cout << "Test 4: ";
    SwitchRequest sr4(s1, class30, class25);
    if (sr2.isPossible()) cout << "passed" << endl;
    else cout << "failed" << endl;

    cout << "Test 5: ";
    SwitchRequest sr5(s1, class30, class26);
    if (sr2.isPossible()) cout << "passed" << endl;
    else cout << "failed" << endl;

    cout << "Test 6: ";
    SwitchRequest sr6(s1, class30, class27);
    if (sr2.isPossible()) cout << "passed" << endl;
    else cout << "failed" << endl;
 }

int main() {

    ScheduleManager sm;
/*
    for (UC *uc : sm.getUCsVector())
        // cout << uc->getClasses().size() << endl;
        // cout << uc->getUcCode() << ":  " << uc->getMinClassStudents() << "   " << uc->getMaxClassStudents() << endl;
*/
    cout << '\n' << sm.getUCsVector().size() << ' ' << sm.getClassesVector().size() << ' ' << sm.getStudentsSet().size() << '\n';

    testSlots();
    testAddRequest();
    testSwitchRequest();

    return 0;
}
