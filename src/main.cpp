#include <iostream>
#include <string>
#include <vector>

#include "ScheduleManager.h"
#include "UC.h"
#include "Request.h"
#include "AddRequest.h"
#include "SwitchRequest.h"
#include "SwapRequest.h"
#include "Oopsie.h"
#include "Menu.h"

class Request;

using namespace std;

void testRandom(ScheduleManager *sm) {

    cout << "::::::::::::RANDOM TESTS:::::::::::::\n";

    Student *s1 = sm->findStudentByName("Renata");
    Class *c1 = s1->getClasses().front();
    s1->removeClass(c1);
    cout << "Test 1: ";
    if (s1->isInClass(c1)) cout << "failed" << endl;
    else cout << "passed" << endl;

    Student *s2 = sm->findStudentByCode("202040617");
    cout << "Test 2: ";
    if (s2) cout << "passed" << endl;
    else cout << "failed" << endl;

    Student *s3 = sm->findStudentByName("Aramis");
    cout << "Test 3: ";
    if (s3) cout << "passed" << endl;
    else cout << "failed" << endl;
}

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

    auto *s1 = new Student("202108752", "Diogo");
    UC *uc1 = new UC("AED");
    auto *class1 = new Class("Turma1", uc1);
    class1->addSlot(new Slot("Monday", "10", "3", "TP"));
    class1->addSlot(new Slot("Tuesday", "10.5", "3", "T"));
    s1->addClass(class1);

    UC *uc2 = new UC("LDTS");

    cout << "Test 1: ";
    auto *class2 = new Class("Turma2", uc2);
    class2->addSlot(new Slot("Monday", "11", "1", "TP"));
    class2->addSlot(new Slot("Friday", "6", "0", "T"));
    AddRequest ar1(s1, class2);
    try {
        ar1.isPossible();
        cout << "failed" << endl;
    } catch (Oopsie &e) {
        cout << "passed" << endl;
    }

    cout << "Test 2: ";
    auto *class3 = new Class("Turma3", uc2);
    class3->addSlot(new Slot("Monday", "10.5", "2", "PL"));
    class2->addSlot(new Slot("Friday", "6", "0", "T"));
    AddRequest ar2(s1, class3);
    try {
        ar2.isPossible();
        cout << "failed" << endl;
    } catch (Oopsie &e) {
        cout << "passed" << endl;
    }

    cout << "Test 3: ";
    auto *class4 = new Class("Turma3", uc2);
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
        cout << "failed" << endl;
    }

    UC *uc3 = new UC("BD"); Slot *slot1 = new Slot("", "0", "0", "T");
    auto *class23 = new Class("", uc3); class23->addSlot(slot1);
    for (int i = 0; i < 23; i++) class23->addStudent(new Student(to_string(i), to_string(i)));
    auto *class25 = new Class("", uc3); class25->addSlot(slot1);
    for (int i = 0; i < 25; i++) class25->addStudent(new Student(to_string(i), to_string(i)));
    auto *class26 = new Class("", uc3); class26->addSlot(slot1);
    for (int i = 0; i < 26; i++) class26->addStudent(new Student(to_string(i), to_string(i)));
    auto *class30 = new Class("", uc3); class30->addSlot(slot1);
    for (int i = 0; i < 30; i++) class30->addStudent(new Student(to_string(i), to_string(i)));

    cout << "Test 4: ";
    AddRequest ar4(s1, class23);
    try {
        ar4.isPossible();
        cout << "passed" << endl;
    } catch (Oopsie &e) {
        cout << "failed" << endl;
    }

    cout << "Test 5: ";
    AddRequest ar5(s1, class25);
    try {
        ar5.isPossible();
        cout << "passed" << endl;
    } catch (Oopsie &e) {
        cout << "failed" << endl;
    }

    cout << "Test 6: ";
    AddRequest ar6(s1, class26);
    try {
        ar6.isPossible();
        cout << "failed" << endl;
    } catch (Oopsie &e) {
        cout << "passed" << endl;
    }

    cout << "Test 7: ";
    AddRequest ar7(s1, class30);
    try {
        ar7.isPossible();
        cout << "failed" << endl;
    } catch (Oopsie &e) {
        cout << "passed" << endl;
    }

    Slot *slot2 = new Slot("", "0", "0", "T");
    auto *class25_ = new Class("", uc3); class25_->addSlot(slot2);
    for (int i = 0; i < 25; i++) class25_->addStudent(new Student(to_string(i), to_string(i)));
    auto *class26_ = new Class("", uc3); class26_->addSlot(slot2);
    for (int i = 0; i < 26; i++) class26_->addStudent(new Student(to_string(i), to_string(i)));
    auto *class30_ = new Class("", uc3); class30_->addSlot(slot2);
    for (int i = 0; i < 30; i++) class30_->addStudent(new Student(to_string(i), to_string(i)));

    cout << "Test 8: ";
    AddRequest ar8(s1, class25_);
    try {
        ar8.isPossible();
        cout << "passed" << endl;
    } catch (Oopsie &e) {
        cout << "failed" << endl;
    }
}

void testSwitchRequest() {

    cout << "::::::::SWITCH REQUEST TESTS:::::::::\n";

    auto *s1 = new Student("202108752", "Diogo");

    UC *uc3 = new UC("BD"); Slot *slot = new Slot("", "0", "0", "T");
    auto *class23 = new Class("", uc3); class23->addSlot(slot);
    for (int i = 0; i < 23; i++) class23->addStudent(new Student(to_string(i), to_string(i)));
    auto *class25 = new Class("", uc3); class25->addSlot(slot);
    for (int i = 0; i < 25; i++) class25->addStudent(new Student(to_string(i), to_string(i)));
    auto *class26 = new Class("", uc3); class26->addSlot(slot);
    for (int i = 0; i < 26; i++) class26->addStudent(new Student(to_string(i), to_string(i)));
    auto *class27 = new Class("", uc3); class27->addSlot(slot);
    for (int i = 0; i < 27; i++) class27->addStudent(new Student(to_string(i), to_string(i)));
    auto *class30 = new Class("", uc3); class30->addSlot(slot);
    for (int i = 0; i < 30; i++) class30->addStudent(new Student(to_string(i), to_string(i)));

    s1->addClass(class23);

    cout << "Test 1: ";
    SwitchRequest sr1(s1, class23, class25);
    try {
        sr1.isPossible();
        cout << "passed" << endl;
    } catch (Oopsie &e) {
        cout << "failed" << endl;
    }

    cout << "Test 2: ";
    SwitchRequest sr2(s1, class23, class26);
    try {
        sr2.isPossible();
        cout << "failed" << endl;
    } catch (Oopsie &e) {
        cout << "passed" << endl;
    }

    s1->removeClass(class23);
    s1->addClass(class30);

    cout << "Test 3: ";
    SwitchRequest sr3(s1, class30, class23);
    try {
        sr3.isPossible();
        cout << "passed" << endl;
    } catch (Oopsie &e) {
        cout << "failed" << endl;
    }

    cout << "Test 4: ";
    SwitchRequest sr4(s1, class30, class25);
    try {
        sr4.isPossible();
        cout << "passed" << endl;
    } catch (Oopsie &e) {
        cout << "failed" << endl;
    }

    cout << "Test 5: ";
    SwitchRequest sr5(s1, class30, class26);
    try {
        sr5.isPossible();
        cout << "passed" << endl;
    } catch (Oopsie &e) {
        cout << "failed" << endl;
    }

    s1->removeClass(class30);
    s1->addClass(class26);

    cout << "Test 6: ";
    SwitchRequest sr6(s1, class26, class27);
    try {
        sr6.isPossible();
        cout << "failed" << endl;
    } catch (Oopsie &e) {
        cout << "passed" << endl;
    }
}

void testSwapRequest() {

    cout << ":::::::::SWAP REQUEST TESTS::::::::::\n";

    UC *uc = new UC("Street");

    auto *s1 = new Student("0", "Diogo");
    auto *s2 = new Student("0", "Chico");
    auto *s3 = new Student("0", "Belchior");

    auto *c1 = new Class("Class1", uc); c1->addSlot(new Slot("Wednesday", "10", "2", "T"));
    auto *c2 = new Class("Class2", uc); c2->addSlot(new Slot("Wednesday", "11", "1", "TP"));
    auto *c3 = new Class("Class3", uc); c3->addSlot(new Slot("Wednesday", "11", "1", "TP"));
    auto *c4 = new Class("Class4", uc); c4->addSlot(new Slot("Wednesday", "11", "1", "PL"));

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
    SwapRequest sr2(s1, s3, c1, c4);
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
        cout << "passed" << endl;
    }
}

void testRequests(ScheduleManager *sm) {

    cout << "::::::::::::REQUEST TESTS::::::::::::\n";

    auto *linoMarcolino = new Student("200000000", "Lino Marcolino");
    string ucc = "L.EIC015", cc1 = "2LEIC01", cc3 = "2LEIC03";

    Class *_2leic01 = nullptr, *_2leic03 = nullptr;
    for (Class *c : sm->getClassesVector()) {
        if (_2leic01 != nullptr && _2leic03 != nullptr) break;
        if (c->getUc()->getName() == ucc && c->getName() == cc3) _2leic03 = c;
        if (c->getUc()->getName() == ucc && c->getName() == cc1) _2leic01 = c;
    }

    sm->createRequest(new AddRequest(linoMarcolino, _2leic01));
    sm->processRequests();

    cout << "Test 1: ";
    if (linoMarcolino->isInClass(_2leic01)) cout << "passed" << endl;
    else cout << "failed" << endl;

    sm->createRequest(new SwitchRequest(linoMarcolino, _2leic01, _2leic03));
    sm->processRequests();

    cout << "Test 2: ";
    if (linoMarcolino->isInClass(_2leic01) && !linoMarcolino->isInClass(_2leic03)) cout << "passed" << endl;
    else cout << "failed" << endl;

    auto *tiagoOliveira = new Student("200000001", "Tiago Oliveira");
    auto *tiagoSequeira = new Student("200000002", "Tiago Sequeira ", true);
    string ucCode = "L.EIC021", classCode1 = "3LEIC01", classCode2 = "3LEIC02", classCode3 = "3LEIC05";

    Class *_3leic01 = nullptr, *_3leic02 = nullptr, *_3leic05 = nullptr;
    for (Class *c : sm->getClassesVector()) {
        if (_3leic01 != nullptr && _3leic02 != nullptr && _3leic05 != nullptr) break;
        if (c->getUc()->getName() == ucCode && c->getName() == classCode1) _3leic01 = c;
        if (c->getUc()->getName() == ucCode && c->getName() == classCode2) _3leic02 = c;
        if (c->getUc()->getName() == ucCode && c->getName() == classCode3) _3leic05 = c;
    }
    sm->createRequest(new AddRequest(tiagoOliveira, _3leic01));
    sm->processRequests();

    cout << "Test 3: ";
    if (tiagoOliveira->isInClass(_3leic01)) cout << "passed" << endl;
    else cout << "failed" << endl;

    sm->createRequest(new AddRequest(tiagoSequeira, _3leic05));
    sm->createRequest(new AddRequest(tiagoSequeira, _3leic02));
    sm->processRequests();

    cout << "Test 4: ";
    if (!tiagoSequeira->isInClass(_3leic02)) cout << "passed" << endl;
    else cout << "failed" << endl;

    cout << "Test 5: ";
    if (tiagoSequeira->isInClass(_3leic05)) cout << "passed" << endl;
    else cout << "failed" << endl;

    ucCode = "L.EIC005";

    Class *_1leic10 = nullptr, *_1leic09 = nullptr, *_1leic06 = nullptr;
    for (Class *c : sm->getClassesVector()) {
        if (_1leic10 != nullptr && _1leic09 != nullptr && _1leic06 != nullptr) break;
        if (c->getUc()->getName() == ucCode && c->countStudents() == 0) _1leic10 = c;
        if (c->getUc()->getName() == ucCode && c->countStudents() == 1) _1leic09 = c;
        if (c->getUc()->getName() == ucCode && c->countStudents() == 2) _1leic06 = c;
    }

    sm->createRequest(new RemoveRequest(tiagoOliveira, _3leic01));
    sm->processRequests();

    cout << "Test 6: ";
    if (!tiagoOliveira->isInClass(_3leic01)) cout << "passed" << endl;
    else cout << "failed" << endl;

    sm->createRequest(new AddRequest(tiagoOliveira, _1leic10));
    sm->createRequest(new AddRequest(tiagoSequeira, _1leic09));
    sm->processRequests();

    cout << "Test 7: ";
    if (tiagoOliveira->isInClass(_1leic10) && !tiagoSequeira->isInClass(_1leic09)) cout << "passed" << endl;
    else cout << "failed" << endl;

    sm->createRequest(new SwitchRequest(tiagoOliveira, _1leic10, _1leic06));
    sm->createRequest(new SwapRequest(tiagoOliveira, tiagoSequeira, _1leic06, _1leic09));
    sm->processRequests();

    cout << "Test 8: ";
    if (tiagoOliveira->isInClass(_1leic06) && !tiagoSequeira->isInClass(_1leic06)) cout << "passed" << endl;
    else cout << "failed" << endl;


}

void runTests(ScheduleManager *sm) {

    testRandom(sm);
    testSlots();
    testAddRequest();
    testSwitchRequest();
    testSwapRequest();
    testRequests(sm);
}

int main() {

    string path;

    ifstream in ("../data/input/students_classes_edited.csv");

    if (!in) {
        path = "../data/input/students_classes.csv";
    }

    else {
        cout << "Do you want the original or edited schedule?\n";
        cout << "All changes to the edited will be lost if you choose the original\n";
        cout << "0: original\n";
        cout << "1: edited\n";

        string option;

        while (true) {

            cin >> option;

            if (option == "0") {
                path = "../data/input/students_classes.csv";
                break;
            }

            if (option == "1") {
                path = "../data/input/students_classes_edited.csv";
                break;
            }

            cout << "Invalid option";
        }

    }

    ScheduleManager sm(path);

    Menu menu(&sm);
    menu.run();

//    runTests(&sm);
//    cout << '\n' << sm.getUcVector().size() << ' ' << sm.getClassesVector().size() << ' ' << sm.getStudentsByCodeSet().size() << '\n';

    return 0;
}
