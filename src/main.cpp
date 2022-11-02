#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../headers/ScheduleManager.h"

using namespace std;

void testSlots() {

    Slot s1("Tuesday", "12.5", "5", "T");
    Slot s2("Tuesday", "14", "2", "T");
    Slot s3("Friday", "0", "0", "");
    Slot s4("Friday", "0", "0", "");
    Slot s5("Monday", "15", "0", "");
    Slot s6("Wednesday", "10", "2", "T");
    Slot s7("Wednesday", "11", "1", "TP");
    Slot s8("Wednesday", "11", "1", "PL");
    Slot s9("Wednesday", "11.5", "1", "TP");

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


int main() {

    ScheduleManager sm;

    cout << '\n' << sm.getClassesVector().size() << ' ' << sm.getStudentsSet().size() << '\n';

    // testSlots();

    return 0;
}
