//
// Created by diogotvf7 on 04-11-2022.
//

#include <iostream>
#include <iomanip>

#include "Menu.h"

using namespace std;

bool isNumerical(const string& s) {
    return all_of(s.begin(), s.end(), [](const char &c){return isdigit(c);});
}
template<class T>
bool nameCmp(T *lhs, T *rhs) {
    return lhs->getName() < rhs->getName();
}
template<class T>
bool nameCmpReverse (T *lhs, T *rhs) {
    return lhs->getName() > rhs->getName();
}
template<class T>
bool attendanceCmp (T *lhs, T *rhs) {
    return lhs->countStudents() < rhs->countStudents();
}
template<class T>
bool attendanceCmpReverse (T *lhs, T *rhs) {
    return lhs->countStudents() > rhs->countStudents();
}

Menu::Menu(ScheduleManager *sm) {
    this->sm = sm;
    this->status = "0";
    this->ucConfig = {{"ORDER", "NAME"}, {"SHOW ATTENDANCE", "YES"}, {"REVERSE", "NO"}, {"YEAR", "ALL"}};
    this->classConfig = {{"ORDER", "ATTENDANCE"}, {"SHOW ATTENDANCE", "YES"}, {"REVERSE", "NO"}, {"YEAR", "ALL"}};
}

void Menu::run() {

    bool alive = true;
    while (alive) {
        switch (stoi(status)) {

            case 0: // Main menu
                mainMenu();
                break;
            case 1: //
                ucMenu(); // SHOW UCS LIST MENU
                cin >> status;
                break;
            case 2: //
                cout << "ORDER BY\n"
                     << "0. BACK\n";
                cin >> status;
                break;
            case 3: //
                cout << "Showing SEE CURRICULAR UNITS\n"
                     << "0. BACK\n";
                cin >> status;
                break;
            case 4: //
                cout << "Showing SEE CURRICULAR UNITS\n"
                     << "0. BACK\n";
                cin >> status;
                break;
            case 5: //
                cout << "Showing SEE CURRICULAR UNITS\n"
                     << "0. BACK\n";
                cin >> status;
                break;
            case 6:
                cout << "CONFIGURATIONS"
                    << "0. BACK\n";
                cin >> status;
                break;
            case 7: // EXIT
                alive = false;
                break;
        }
        cleanTerminal();
    }

}

void Menu::mainMenu() {
    cleanTerminal();
    cout << "__________________________________________________________________\n"
         << "|                            Main menu                           |\n"
         << "|                  Choose an option to continue                  |\n"
         << "|________________________________________________________________|\n"
         << "|                                                                |\n"
         << "|                  1. SEE CURRICULAR UNITS                       |\n"
         << "|                  2. SEE CLASSES                                |\n"
         << "|                  3. SEE STUDENTS                               |\n"
         << "|                  4. FIND STUDENT/CLASS/CURRICULAR UNIT         |\n"
         << "|                  5. MAKE REQUEST                               |\n"
         << "|                  6. CONFIGURATIONS                             |\n"
         << "|                  7. EXIT                                       |\n"
         << "|________________________________________________________________|\n\n";
    cout << " OPTION: "; cin >> status;
}

void Menu::ucMenu() {

    vector<UC*> sortedUcs = sm->getUcVector();
    if (ucConfig["ORDER"] == "NAME" && ucConfig["REVERSE"] == "NO")
        sort(sortedUcs.begin(), sortedUcs.end(), nameCmp<UC>);
    else if (ucConfig["ORDER"] == "NAME" && ucConfig["REVERSE"] == "YES")
        sort(sortedUcs.begin(), sortedUcs.end(), nameCmpReverse<UC>);
    else if (ucConfig["ORDER"] == "ATTENDANCE" && ucConfig["REVERSE"] == "NO")
        sort(sortedUcs.begin(), sortedUcs.end(), attendanceCmp<UC>);
    else if (ucConfig["ORDER"] == "ATTENDANCE" && ucConfig["REVERSE"] == "YES")
        sort(sortedUcs.begin(), sortedUcs.end(), attendanceCmpReverse<UC>);

    cleanTerminal();
    cout << "__________________________________________________________________\n"
         << "|                        CURRICULAR UNITS                        |\n"
         << "|                                                                |\n"
         << "|________________________________________________________________|\n"
         << "|                                                                |\n";

    for (size_t i = 0; i < sortedUcs.size(); i++) {
        cout << "|" << right << setw(14) << to_string((i + 1)) + ". " << setw(10) << "  " + sortedUcs[i]->getName();
        if (ucConfig["SHOW ATTENDANCE"] == "YES") {
            cout << ": " << setw(12) <<  to_string((sortedUcs[i]->countStudents())) + " students" << setw(27) << "|" << endl;
        } else cout << setw(40) << '|' << endl;
    }
    cout << "|________________________________________________________________|\n"
         << "|           WRITE A NUMBER TO INSPECT A CURRICULAR UNIT          |\n"
         << "|                     WRITE 'back' TO GO BACK                    |\n"
         << "|________________________________________________________________|\n\n";

    while (true) {

        cout << "   - OPTION: "; cin >> status;
        if (isNumerical(status)) {
            ucClassMenu(sortedUcs[stoi(status) - 1]);
            break;
        }
        else if (status == "back")
            break;
    }
}

void Menu::ucClassMenu(UC *uc) {

    vector<Class*> sortedUcClasses = uc->getClasses();
    if (classConfig["ORDER"] == "NAME" && classConfig["REVERSE"] == "NO")
        sort(sortedUcClasses.begin(), sortedUcClasses.end(), nameCmp<Class>);
    else if (ucConfig["ORDER"] == "NAME" && ucConfig["REVERSE"] == "YES")
        sort(sortedUcClasses.begin(), sortedUcClasses.end(), nameCmpReverse<Class>);
    else if (ucConfig["ORDER"] == "ATTENDANCE" && ucConfig["REVERSE"] == "NO")
        sort(sortedUcClasses.begin(), sortedUcClasses.end(), attendanceCmp<Class>);
    else if (ucConfig["ORDER"] == "ATTENDANCE" && ucConfig["REVERSE"] == "YES")
        sort(sortedUcClasses.begin(), sortedUcClasses.end(), attendanceCmpReverse<Class>);

    cleanTerminal();
    cout << "__________________________________________________________________\n"
         << "|" << right << setw(32 + (int)(uc->getName().size() / 2)) << uc->getName() << setw(30) << "|\n"
         << "|                                                                |\n"
         << "|________________________________________________________________|\n"
         << "|                                                                |\n";

    for (size_t i = 0; i < sortedUcClasses.size(); i++) {
        cout << "|" << right << setw(14) << to_string((i + 1)) + ". " << setw(10) << "  " + sortedUcClasses[i]->getName();
        if (classConfig["SHOW ATTENDANCE"] == "YES") {
            cout << ": " << setw(12) <<  to_string((sortedUcClasses[i]->countStudents())) + " students" << setw(27) << "|" << endl;
        } else cout << setw(40) << '|' << endl;
    }

    cout << "|________________________________________________________________|\n"
         << "|           WRITE A NUMBER TO INSPECT A CURRICULAR UNIT          |\n"
         << "|                     WRITE 'back' TO GO BACK                    |\n"
         << "|________________________________________________________________|\n\n";

    while (true) {

        cout << "   - OPTION: "; cin >> status;
        if (isNumerical(status)) {
            cout << status;
            break;
        }
        else if (status == "back")
            break;
    }
}

void Menu::cleanTerminal() {
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

