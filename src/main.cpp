#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "ScheduleManager.h"

using namespace std;

void testSlots() {

    Slot s1("Tuesday", "12.5", "0", "");
    Slot s2("Tuesday", "14", "0", "");
    Slot s3("Friday", "0", "0", "");
    Slot s4("Friday", "0", "0", "");
    Slot s5("Monday", "15", "0", "");

    cout << ":::::SLOT TESTS:::::\n";

    cout << "Test 1: ";
    if (s1 < s2) cout << "passed" << '\n';
    else cout << "failed" << '\n';

    cout << "Test 2: ";
    if (!(s3 < s5)) cout << "passed" << '\n';
    else cout << "failed" << '\n';

    cout << "Test 3: ";
    if (!(s3 < s4)) cout << "passed" << '\n';
    else cout << "failed" << '\n';

    cout << "Test 4: ";
    if ((s5 < s1)) cout << "passed" << '\n';
    else cout << "failed" << '\n';
}

int main() {

    // testSlots();

    ScheduleManager sm;
    sm.readClassesFile();
    vector<Class> classes = sm.getClasses();
    for (const Class &c : classes)
        for (const Slot &s : c.getSlots())
            cout << s;


    cout << '\n' << sm.getClasses().size();
/*
    cout << s.getClasses()[0].getClassCode() << ' ' << s.getClasses()[0].getUcCode();
    cout << s.getClasses()[1].getClassCode() << ' ' << s.getClasses()[1].getUcCode();
    cout << s.getClasses()[2].getClassCode() << ' ' << s.getClasses()[2].getUcCode();
    cout << s.getClasses()[3].getClassCode() << ' ' << s.getClasses()[3].getUcCode();
    cout << s.getClasses()[4].getClassCode() << ' ' << s.getClasses()[4].getUcCode();
    cout << s.getClasses()[5].getClassCode() << ' ' << s.getClasses()[5].getUcCode();
*/
    return 0;
}
