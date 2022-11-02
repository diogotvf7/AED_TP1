#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../headers/ScheduleManager.h"
#include "Request.h"
#include "AddRequest.h"

class Request;

using namespace std;

void testSlots() {

    Slot s1("Tuesday", "12.5", "5", "T");
    Slot s2("Tuesday", "14", "2", "T");
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

void testAddRequest(const ScheduleManager &sm) {

    Student *s1 = new Student("202108752", "Diogo");
    UC *uc1 = new UC("AED");
    Class *class1 = new Class("Turma1", uc1);
    class1->addSlot(new Slot("Monday", "10", "3", "TP"));
    class1->addSlot(new Slot("Tuesday", "10.5", "3", "T"));
    s1->addClass(class1);

    cout << ":::::ADD REQUEST TESTS:::::\n";

    cout << "Test 1: ";
    UC *uc2 = new UC("LDTS");
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
    if (!ar1.isPossible()) cout << "passed" << endl;
    else cout << "failed" << endl;

    cout << "Test 3: ";
    Class *class4 = new Class("Turma3", uc2);
    class3->addSlot(new Slot("Monday", "0", "24", "T"));
    class2->addSlot(new Slot("Tuesday", "0", "24", "T"));
    class3->addSlot(new Slot("Wednesday", "0", "24", "T"));
    class2->addSlot(new Slot("Thursday", "0", "24", "T"));
    class3->addSlot(new Slot("Friday", "0", "24", "T"));
    AddRequest ar3(s1, class3);
    if (ar1.isPossible()) cout << "passed" << endl;
    else cout << "failed" << endl;

}

int main() {

    ScheduleManager sm;

    for (Class *c : sm.getClassesVector()) {
        int i = 0;
        for (Slot *s : c->getSlots())
            if (s->getType() != "T") i++;
        cout << i << endl;
    }

    cout << '\n' << sm.getUCsVector().size() << ' ' << sm.getClassesVector().size() << ' ' << sm.getStudentsSet().size() << '\n';

    testSlots();
    testAddRequest(sm);

    return 0;
}
