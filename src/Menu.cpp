//
// Created by diogotvf7 on 04-11-2022.
//

#include <iostream>
#include <iomanip>

#include "Menu.h"

using namespace std;


string toLower(const string &s) {
    string lowerS;
    for (char c : s) lowerS += tolower(c);
    return lowerS;
}
bool isNumerical(const string& s) {
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}
template<class T>
bool nameCmp(T *lhs, T *rhs) {
    return lhs->getName() < rhs->getName();
}
template<class T>
bool nameCmpReverse(T *lhs, T *rhs) {
    return lhs->getName() > rhs->getName();
}
template<class T>
bool attendanceCmp(T *lhs, T *rhs) {
    return lhs->countStudents() < rhs->countStudents();
}
template<class T>
bool attendanceCmpReverse(T *lhs, T *rhs) {
    return lhs->countStudents() > rhs->countStudents();
}
template<class T>
bool numberOfClassesCmp(T *lhs, T *rhs) {
    return lhs->countClasses() < rhs->countClasses();
}
template<class T>
bool numberOfClassesCmpReverse(T *lhs, T *rhs) {
    return lhs->countClasses() > rhs->countClasses();
}

Menu::Menu(ScheduleManager *sm) {
    this->sm = sm;
    this->status = "0";
    this->ucPrintConfig = {{"ORDER", "name"}, {"SHOW ATTENDANCE", "no"}, {"REVERSE", "no"}, {"YEAR", "all"}}; // ORDER->(NAME / ATTENDANCE)   SHOW ATTENDANCE->(YES / NO)   REVERSE->(YES / NO)   YEAR->(1 / 2 / 3 / ALL)
    this->classPrintConfig = {{"ORDER", "name"}, {"SHOW ATTENDANCE", "no"}, {"REVERSE", "no"}, {"YEAR", "all"}}; // ORDER->(NAME / ATTENDANCE)   SHOW ATTENDANCE->(YES / NO)   REVERSE->(YES / NO)   YEAR->(1 / 2 / 3 / ALL)
    this->studentPrintConfig = {{"ORDER", "name"}, {"SHOW NUMBER OF CLASSES", "no"}, /*{"REVERSE", "no"}*/}; // ORDER->(NAME / CODE)   SHOW NUMBER OF CLASSES->(YES / NO)   REVERSE->(YES / NO)
}

vector<UC*> Menu::getUcs() {
    vector<UC*> sortedUcs = sm->getUcVector();
    if (ucPrintConfig["ORDER"] == "name" && ucPrintConfig["REVERSE"] == "no")
        sort(sortedUcs.begin(), sortedUcs.end(), nameCmp<UC>);

    else if (ucPrintConfig["ORDER"] == "name" && ucPrintConfig["REVERSE"] == "yes")
        sort(sortedUcs.begin(), sortedUcs.end(), nameCmpReverse<UC>);

    else if (ucPrintConfig["ORDER"] == "attendance" && ucPrintConfig["REVERSE"] == "no")
        sort(sortedUcs.begin(), sortedUcs.end(), attendanceCmp<UC>);

    else if (ucPrintConfig["ORDER"] == "attendance" && ucPrintConfig["REVERSE"] == "yes")
        sort(sortedUcs.begin(), sortedUcs.end(), attendanceCmpReverse<UC>);

    return sortedUcs;
}

vector<Class*> Menu::getClasses(UC *uc, Student *s) {

    vector<Class*> sortedClasses;

    if (uc) sortedClasses = uc->getClasses();
    else if (s) sortedClasses = s->getClasses();
    else sortedClasses = sm->getClassesVector();

    if (classPrintConfig["ORDER"] == "name" && classPrintConfig["REVERSE"] == "no")
        sort(sortedClasses.begin(), sortedClasses.end(), nameCmp<Class>);

    else if (classPrintConfig["ORDER"] == "name" && classPrintConfig["REVERSE"] == "yes")
        sort(sortedClasses.begin(), sortedClasses.end(), nameCmpReverse<Class>);

    else if (classPrintConfig["ORDER"] == "attendance" && classPrintConfig["REVERSE"] == "no")
        sort(sortedClasses.begin(), sortedClasses.end(), attendanceCmp<Class>);

    else if (classPrintConfig["ORDER"] == "attendance" && classPrintConfig["REVERSE"] == "yes")
        sort(sortedClasses.begin(), sortedClasses.end(), attendanceCmpReverse<Class>);

    return sortedClasses;
}

vector<Student*> Menu::getStudents(Class *c) {

    vector<Student*> sortedClassStudents = c->getStudents();

    if (studentPrintConfig["ORDER"] == "name" && studentPrintConfig["REVERSE"] == "no")
        sort(sortedClassStudents.begin(), sortedClassStudents.end(), nameCmp<Student>);

    else if (studentPrintConfig["ORDER"] == "name" && studentPrintConfig["REVERSE"] == "yes")
        sort(sortedClassStudents.begin(), sortedClassStudents.end(), nameCmpReverse<Student>);

    else if (studentPrintConfig["ORDER"] == "number of classes" && studentPrintConfig["REVERSE"] == "no")
        sort(sortedClassStudents.begin(), sortedClassStudents.end(), numberOfClassesCmp<Student>);

    else if (studentPrintConfig["ORDER"] == "number of classes" && studentPrintConfig["REVERSE"] == "yes")
        sort(sortedClassStudents.begin(), sortedClassStudents.end(), numberOfClassesCmpReverse<Student>);

    return sortedClassStudents;
}

void Menu::run() {

    bool alive = true;
    while (alive) {
        switch (stoi(status)) {

            case 0: // Main menu
                mainMenu();
                break;
            case 1: //
                ucMenu(); // SHOWS UCS LIST MENU
                status = "0";
                break;
            case 2: //
                classMenu(); // SHOWS CLASS LIST MENU
                status = "0";
                break;
            case 3: //
                studentMenu();
                status = "0";
                break;
            case 4: //
                findMenu();
                status = "0";
                break;
            case 5: //
                requestMenu();
                status = "0";
                break;
            case 6:
                configMenu();
                status = "0";
                break;
            case 7: // EXIT
                close();
                cleanTerminal();
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

    while (true) {
        cout << "   - OPTION: "; cin >> status;
        if (isNumerical(status) && 1 <= stoi(status) && stoi(status) <= 7) break;
        else cout << "   - INVALID OPTION" << endl;
    }
}

void Menu::ucMenu() {

    bool alive = true;
    vector<UC*> sortedUcs = getUcs();

    while (alive) {
        cleanTerminal();
        cout << "__________________________________________________________________\n"
             << "|                        CURRICULAR UNITS                        |\n"
             << "|                                                                |\n"
             << "|________________________________________________________________|\n";

        for (size_t i = 0; i < sortedUcs.size(); i++) {
            cout << right << setw(20) << to_string((i + 1)) + ".   " << sortedUcs[i]->getName();
            if (ucPrintConfig["SHOW ATTENDANCE"] == "yes") {
                cout << ": " << setw(12) <<  to_string((sortedUcs[i]->countStudents())) + " students";
            }
            cout << endl;
        }
        cout << "__________________________________________________________________\n"
             << "|           WRITE A NUMBER TO INSPECT A CURRICULAR UNIT          |\n"
             << "|                     WRITE 'back' TO GO BACK                    |\n"
             << "|________________________________________________________________|\n\n";

        while (true) {

            cout << "   - OPTION: "; cin >> status;
            if (isNumerical(status) && 1 <= stoi(status) && stoi(status) <= sortedUcs.size()) {
                alive = ucClassMenu(sortedUcs[stoi(status) - 1]);
                break;
            }
            else if (status == "back")
                return;
            else cout << "   - INVALID OPTION" << endl;
        }

    }
}

void Menu::classMenu() {

    bool alive = true;
    int page = 0;
    vector<Class*> sortedClasses = getClasses();

    while (alive) {
        cleanTerminal();
        cout << "__________________________________________________________________\n"
             << "|                            CLASSES                             |\n"
             << "|                                                                |\n"
             << "|________________________________________________________________|\n";

        for (int i = page * 20; i < min(page * 20 + 20, (int) sortedClasses.size()); i++) {
            cout << right << setw(20) << to_string(i + 1) + ".   " << sortedClasses[i]->getUc()->getName() << ' ' << sortedClasses[i]->getName();
            if (classPrintConfig["SHOW ATTENDANCE"] == "yes") {
                cout << ": " << (sortedClasses[i]->countStudents()) << " students";
            }
            cout << endl;
        }

        cout << "__________________________________________________________________\n"
             << "|                WRITE A NUMBER TO INSPECT A CLASS               |\n"
             << "|                      WRITE 'w' TO MOVE UP                      |\n"
             << "|                     WRITE 's' TO MOVE DOWN                     |\n"
             << "|                     WRITE 'back' TO GO BACK                    |\n"
             << "|________________________________________________________________|\n\n";

        while (true) {

            cout << "   - OPTION: "; cin >> status;
            if (isNumerical(status) && page * 20 + 1 <= stoi(status) && stoi(status) <= min(page * 20 + 21, (int) sortedClasses.size())) {
                alive = classStudentMenu(sortedClasses[stoi(status) - 1]);
                break;
            } else if (status == "w" && page * 20 - 20 >= 0) {
                page--;
                break;
            } else if (status == "s" && page * 20 + 20 < sortedClasses.size()) {
                page++;
                break;
            } else if (status == "back")
                return;
            else cout << "   - INVALID OPTION" << endl;
        }
    }
}

void Menu::studentMenu() {

    bool alive = true;

    cleanTerminal();
    cleanTerminal();

    cout << "__________________________________________________________________\n"
         << "|                           STUDENTS                             |\n"
         << "|                                                                |\n"
         << "|________________________________________________________________|\n";

    if (studentPrintConfig["ORDER"] == "name") {

        set<Student*,StudentNameCmp> sortedStudents = sm->getStudentsByNameSet();
        unsigned n = 0;

        for (Student *s : sortedStudents) {
            cout << right << setw(20) << to_string(++n) + ".   " << left << setw(30) << to_string(s->getCode()) + " " + s->getName();
            if (studentPrintConfig["SHOW NUMBER OF CLASSES"] == "yes")
                cout << "   " + to_string(s->countClasses()) + " classes";
            cout << endl;
        }
    }
    if (studentPrintConfig["ORDER"] == "code") {

        set<Student*,StudentCodeCmp> sortedStudents = sm->getStudentsByCodeSet();
        unsigned n = 0;

        for (Student *s : sortedStudents) {
            cout << right << setw(20) << to_string(++n) + ".   " << left << setw(30) << to_string(s->getCode()) + " " + s->getName();
            if (studentPrintConfig["SHOW NUMBER OF CLASSES"] == "yes")
                cout <<  "   " + to_string(s->countClasses()) + " classes";
            cout << endl;
        }
    }
    cout << "__________________________________________________________________\n"
         << "|                     WRITE 'back' TO GO BACK                    |\n"
         << "|________________________________________________________________|\n\n";

    while (true) {
        cout << "   - OPTION: "; cin >> status;
        if (status == "back")
            return;
        else cout << "   - INVALID OPTION" << endl;
    }
}

bool Menu::ucClassMenu(UC *uc) {

    bool alive = true;
    vector<Class*> sortedUcClasses = getClasses(uc);

    while (alive) {
        cleanTerminal();
        cout << "__________________________________________________________________\n"
             << "|" << right << setw(32 + (int)(uc->getName().size() / 2)) << uc->getName() << setw(30) << "|\n"
             << "|                                                                |\n"
             << "|________________________________________________________________|\n";

        for (size_t i = 0; i < sortedUcClasses.size(); i++) {
            cout << right << setw(20) << to_string(i + 1) + ".    " << sortedUcClasses[i]->getName();
            if (classPrintConfig["SHOW ATTENDANCE"] == "yes") {
                cout << ": " << sortedUcClasses[i]->countStudents() << " students";
            }
            cout << endl;
        }

        cout << "__________________________________________________________________\n"
             << "|              WRITE A NUMBER TO INSPECT A CLASS UNIT            |\n"
             << "|                     WRITE 'back' TO GO BACK                    |\n"
             << "|________________________________________________________________|\n\n";

        while (true) {

            cout << "   - OPTION: "; cin >> status;
            if (isNumerical(status) && 1 <= stoi(status) && stoi(status) <= sortedUcClasses.size()) {
                alive = classStudentMenu(sortedUcClasses[stoi(status) - 1]);
                break;
            }
            else if (status == "back")
                return true;
            else cout << "   - INVALID OPTION" << endl;
        }
    }
    return false;
}

bool Menu::classStudentMenu(Class *c) {

    bool alive = true;
    vector<Student*> sortedClassStudents = getStudents(c);

    while (alive) {
        cleanTerminal();
        cout << "__________________________________________________________________\n"
             << "|" << right << setw(32 + (int)(c->getName().size() / 2)) << c->getUc()->getName() << setw(30) << "|\n"
             << "|" << right << setw(32 + (int)(c->getName().size() / 2)) << c->getName() << setw(30) << "|\n"
             << "|________________________________________________________________|\n";

        for (size_t i = 0; i < sortedClassStudents.size(); i++) {
            cout << right << setw(20) << to_string(i + 1) + ".    " << sortedClassStudents[i]->getName();
            if (studentPrintConfig["SHOW NUMBER OF CLASSES"] == "yes") {
                cout << ": " << (sortedClassStudents[i]->countClasses()) << " classes";
            }
            cout << endl;
        }

        cout << "__________________________________________________________________\n"
             << "|                WRITE A NUMBER TO INSPECT A STUDENT             |\n"
             << "|                     WRITE 'back' TO GO BACK                    |\n"
             << "|________________________________________________________________|\n\n";

        while (true) {

            cout << "   - OPTION: "; cin >> status;
            if (isNumerical(status) && 1 <= stoi(status) && stoi(status) <= sortedClassStudents.size()) {
                alive = studentMenu(sortedClassStudents[stoi(status) - 1]);
                break;
            }
            else if (status == "back")
                return true;
            else cout << "   - INVALID OPTION" << endl;
        }
    }
    return false;
}

bool Menu::studentMenu(Student *s) {

    bool alive = true;
    vector<Class*> sortedStudentClasses = getClasses(nullptr, s);

    while (alive) {
        cleanTerminal();
        cout << "__________________________________________________________________\n"
             << "|" << right << setw(32 + (int)(s->getName().size() / 2)) << s->getName() << setw(32) << "|\n"
             << "|" << right << setw(37) << s->getCode() << setw(29) << "|\n"
             << "|________________________________________________________________|\n";

        for (int i = 0; i < sortedStudentClasses.size(); i++) {
            cout << right << setw(20) << to_string(i + 1) + ".    " << sortedStudentClasses[i]->getName() << endl;
            for (Slot *slot : sortedStudentClasses[i]->getSlots())
                cout << right << setw(11) << " - " << *slot;
            cout << endl;
        }

        cout << "__________________________________________________________________\n";
        s->getStatus() ? cout << "|" << right << setw(46) << "WRITE 'd' TO DELETE STATUS" << setw(20) << "|\n" : cout << "|" << right << setw(44) << "WRITE 'a' TO ADD STATUS" << setw(22) << "|\n";
        cout << "|                     WRITE 'back' TO GO BACK                    |\n"
             << "|________________________________________________________________|\n\n";

        while (true) {

            cin >> status;

            if (status == "d" && s->getStatus()) {
                s->setStatus(false);
                break;
            }
            if (status == "a" && !s->getStatus()) {
                s->setStatus(true);
                break;
            }
            if (status == "back")
                return false;

            cout << "Invalid option";
        }
    }
    return false;
}

void Menu::addRequest() {

   string tmp1, tmp2; Student *student; Class *intended;
    while (true) {
        cout << "\nStudent name or code: "; getline(cin >> ws, tmp1);
        if (!isNumerical(tmp1)) student = sm->findStudentByName(tmp1);
        else student = sm->findStudentByCode(tmp1);
        if (student) break;
        cout << "  - INVALID OPTION\n";
    }
    while (true) {
        cout << "UC Code: "; cin >> tmp2;
        if (sm->findUc(tmp2)) break;
        cout << "  - INVALID OPTION\n";
    }
    while (true) {
        cout << "Intended Class code: "; cin >> tmp1;
        intended = sm->findClass(tmp2, tmp1);
        if (intended) break;
        cout << "  - INVALID OPTION\n";
    }
    sm->createRequest(new AddRequest(student, intended));
}

void Menu::removeRequest() {

    string tmp1, tmp2; Student *student; Class *current;
    while (true) {
        cout << "\nStudent name or code: "; getline(cin >> ws, tmp1);
        if (!isNumerical(tmp1)) student = sm->findStudentByName(tmp1);
        else student = sm->findStudentByCode(tmp1);
        if (student) break;
        cout << "  - INVALID OPTION\n";
    }
    while (true) {
        cout << "UC Code: "; cin >> tmp2;
        if (sm->findUc(tmp2)) break;
        cout << "  - INVALID OPTION\n";
    }
    while (true) {
        cout << "Current Class code: "; cin >> tmp1;
        current = sm->findClass(tmp2, tmp1);
        if (current) break;
        cout << "  - INVALID OPTION\n";
    }
    sm->createRequest(new RemoveRequest(student, current));
}

void Menu::switchRequest() {
    string tmp1, tmp2; Student *student; Class *current, *intended;
    while (true) {
        cout << "\nStudent name or code: "; getline(cin >> ws, tmp1);
        if (!isNumerical(tmp1)) student = sm->findStudentByName(tmp1);
        else student = sm->findStudentByCode(tmp1);
        if (student) break;
        cout << "  - INVALID OPTION\n";
    }
    while (true) {
        cout << "UC Code: "; cin >> tmp2;
        if (sm->findUc(tmp2)) break;
        cout << "  - INVALID OPTION\n";
    }
    while (true) {
        cout << "Current Class code: "; cin >> tmp1;
        current = sm->findClass(tmp2, tmp1);
        if (current) break;
        cout << "  - INVALID OPTION\n";
    }
    while (true) {
        cout << "Intended Class code: "; cin >> tmp1;
        intended = sm->findClass(tmp2, tmp1);
        if (intended) break;
        cout << "  - INVALID OPTION\n";
    }
    sm->createRequest(new SwitchRequest(student, current, intended));

}
void Menu::swapRequest() {
    string tmp1, tmp2; Student *student, *colleague; Class *current, *intended;
    while (true) {
        cout << "\nStudent name or code: "; getline(cin >> ws, tmp1);
        if (!isNumerical(tmp1)) student = sm->findStudentByName(tmp1);
        else student = sm->findStudentByCode(tmp1);
        if (student) break;
        cout << "  - INVALID OPTION\n";
    }
    while (true) {
        cout << "\nColleague name or code: "; getline(cin >> ws, tmp1);
        if (!isNumerical(tmp1)) colleague = sm->findStudentByName(tmp1);
        else colleague = sm->findStudentByCode(tmp1);
        if (colleague) break;
        cout << "  - INVALID OPTION\n";
    }
    while (true) {
        cout << "UC Code: "; cin >> tmp2;
        if (sm->findUc(tmp2)) break;
        cout << "  - INVALID OPTION\n";
    }
    while (true) {
        cout << "Current Class code: "; cin >> tmp1;
        current = sm->findClass(tmp2, tmp1);
        if (current) break;
        cout << "  - INVALID OPTION\n";
    }
    while (true) {
        cout << "Intended Class code: "; cin >> tmp1;
        intended = sm->findClass(tmp2, tmp1);
        if (intended) break;
        cout << "  - INVALID OPTION\n";
    }
    sm->createRequest(new SwapRequest(student, colleague, current, intended));
}

void Menu::requestMenu() {
    cleanTerminal();
    cout << "__________________________________________________________________\n"
         << "|                          Request menu                          |\n"
         << "|                  Choose an option to continue                  |\n"
         << "|________________________________________________________________|\n"
         << "|                                                                |\n"
         << "|                  1. ADD REQUEST                                |\n"
         << "|                  2. REMOVE REQUEST                             |\n"
         << "|                  3. SWITCH REQUEST                             |\n"
         << "|                  4. SWAP REQUEST                               |\n"
         << "|                  5. EXIT                                       |\n"
         << "|________________________________________________________________|\n\n";

    while (true) {
        cout << "   - OPTION: "; cin >> status;
        if (isNumerical(status) && 1 <= stoi(status) && stoi(status) <= 4)
            break;
        if (status == "5")
            return;
        else cout << "   - INVALID OPTION" << endl;
    }
    switch (stoi(status)) {
      case 1:
            addRequest();
            break;
        case 2:
            removeRequest();
            break;
        case 3:
            switchRequest();
            break;
        case 4:
            swapRequest();
            break;
    }
}

void Menu::findMenu() {
    while (true) {
        cleanTerminal();
        cout << "__________________________________________________________________\n"
             << "|                           Find menu                            |\n"
             << "|                  Choose an option to continue                  |\n"
             << "|________________________________________________________________|\n"
             << "|                                                                |\n"
             << "|                  1. CURRICULAR UNIT                            |\n"
             << "|                  2. CLASS                                      |\n"
             << "|                  3. STUDENT                                    |\n"
             << "|                  4. EXIT                                       |\n"
             << "|________________________________________________________________|\n\n";

        while (true) {
            cout << "   - OPTION: "; cin >> status;
            if (isNumerical(status) && 1 <= stoi(status) && stoi(status) <= 3)
                break;
            if (status == "4")
                return;
            else cout << "   - INVALID OPTION" << endl;
        }

        string tmp1, tmp2; Student *s; Class *c; UC *uc;

        switch (stoi(status)) {
            case 1:
                while (true) {
                    cout << "UC Code: "; cin >> tmp1;
                    uc = sm->findUc(tmp1);
                    if (c) {
                        ucClassMenu(uc);
                        return;
                    }
                    cout << "  - INVALID OPTION\n";
                }
            case 2:
                while (true) {
                    cout << "UC Code: "; cin >> tmp1;
                    uc = sm->findUc(tmp1);
                    if (uc) break;
                    cout << "  - INVALID OPTION\n";
                }
                while (true) {
                    cout << "Current Class code: "; cin >> tmp2;
                    c = sm->findClass(tmp1, tmp2);
                    if (c) {
                        classStudentMenu(c);
                        return;
                    }
                    cout << "  - INVALID OPTION\n";
                }
            case 3:
                while (true) {
                    cout << "\nStudent name or code: "; getline(cin >> ws, tmp1);
                    if (!isNumerical(tmp1)) s = sm->findStudentByName(tmp1);
                    else s = sm->findStudentByCode(tmp1);
                    if (s) {
                        studentMenu(s);
                        return;
                    }
                    cout << "  - INVALID OPTION\n";
                }
        }
    }
}

void Menu::configUcMenu() {

    string tmp;
    while (true) {
        cout << "   - ORDER->(NAME / ATTENDANCE): ";
        cin >> tmp;
        tmp = toLower(tmp);
        if (tmp == "name" || tmp == "attendance") {
            ucPrintConfig["ORDER"] = tmp;
            break;
        }
        else cout << "   - INVALID OPTION" << endl;
    }
    while (true) {
        cout << "   - SHOW ATTENDANCE->(YES / NO): ";
        cin >> tmp;
        tmp = toLower(tmp);
        if (tmp == "yes" || tmp == "no") {
            ucPrintConfig["SHOW ATTENDANCE"] = tmp;
            break;
        }
        else cout << "   - INVALID OPTION" << endl;
    }
    while (true) {
        cout << "   - REVERSE->(YES / NO): ";
        cin >> tmp;
        tmp = toLower(tmp);
        if (tmp == "yes" || tmp == "no") {
            ucPrintConfig["REVERSE"] = tmp;
            break;
        }
        else cout << "   - INVALID OPTION" << endl;
    }
    while (true) {
        cout << "   - YEAR->(1 / 2 / 3 / ALL): ";
        cin >> tmp;
        tmp = toLower(tmp);
        if (tmp == "1" || tmp == "2" || tmp == "3" || tmp == "all") {
            ucPrintConfig["YEAR"] = tmp;
            break;
        }
        else cout << "   - INVALID OPTION" << endl;
    }
}

void Menu::configClassMenu() {

    string tmp;
    while (true) {
        cout << "   - ORDER->(NAME / ATTENDANCE): ";
        cin >> tmp;
        tmp = toLower(tmp);
        if (tmp == "name" || tmp == "attendance") {
            classPrintConfig["ORDER"] = tmp;
            break;
        }
        else cout << "   - INVALID OPTION" << endl;
    }
    while (true) {
        cout << "   - SHOW ATTENDANCE->(YES / NO): ";
        cin >> tmp;
        tmp = toLower(tmp);
        if (tmp == "yes" || tmp == "no") {
            classPrintConfig["SHOW ATTENDANCE"] = tmp;
            break;
        }
        else cout << "   - INVALID OPTION" << endl;
    }
    while (true) {
        cout << "   - REVERSE->(YES / NO): ";
        cin >> tmp;
        tmp = toLower(tmp);
        if (tmp == "yes" || tmp == "no") {
            classPrintConfig["REVERSE"] = tmp;
            break;
        }
        else cout << "   - INVALID OPTION" << endl;
    }
    while (true) {
        cout << "   - YEAR->(1 / 2 / 3 / ALL): ";
        cin >> tmp;
        tmp = toLower(tmp);
        if (tmp == "1" || tmp == "2" || tmp == "3" || tmp == "all") {
            classPrintConfig["YEAR"] = tmp;
            break;
        }
        else cout << "   - INVALID OPTION" << endl;
    }
}

void Menu::configStudentMenu() {
    string tmp;
    while (true) {
        cout << "   - ORDER->(NAME / CODE): ";
        cin >> tmp;
        tmp = toLower(tmp);
        if (tmp == "name" || tmp == "code") {
            studentPrintConfig["ORDER"] = tmp;
            break;
        }
        else cout << "   - INVALID OPTION" << endl;
    }
    while (true) {
        cout << "   - SHOW NUMBER OF CLASSES->(YES / NO): ";
        cin >> tmp;
        tmp = toLower(tmp);
        if (tmp == "yes" || tmp == "no") {
            studentPrintConfig["SHOW NUMBER OF CLASSES"] = tmp;
            break;
        }
        else cout << "   - INVALID OPTION" << endl;
    }
    /*while (true) {
        cout << "   - REVERSE->(YES / NO): ";
        cin >> tmp;
        tmp = toLower(tmp);
        if (tmp == "yes" || tmp == "no") {
            studentPrintConfig["REVERSE"] = tmp;
            break;
        }
        else cout << "   - INVALID OPTION" << endl;
    }*/
}

void Menu::configMenu() {

    while (true) {
        cleanTerminal();
        cout << "__________________________________________________________________\n"
             << "|                      Configurations menu                       |\n"
             << "|                  Choose an option to continue                  |\n"
             << "|________________________________________________________________|\n"
             << "|                                                                |\n"
             << "|                  1. CURRICULAR UNITS                           |\n"
             << "|                  2. CLASSES                                    |\n"
             << "|                  3. STUDENTS                                   |\n"
             << "|                  4. EXIT                                       |\n"
             << "|________________________________________________________________|\n\n";

        while (true) {
            cout << "   - OPTION: "; cin >> status;
            if (isNumerical(status) && 1 <= stoi(status) && stoi(status) <= 3)
                break;
            if (status == "4")
                return;
            else cout << "   - INVALID OPTION" << endl;
        }

        switch (stoi(status)) {

            case 1:
                configUcMenu();
                break;
            case 2:
                configClassMenu();
                break;
            case 3:
                configStudentMenu();
                break;
        }
    }
}

void Menu::close() {
    cleanTerminal();
    cout << "__________________________________________________________________\n"
         << "|             Do you wish to save the requests made?             |\n"
         << "|                            yes / no                            |\n"
         << "|________________________________________________________________|\n";

    while (true) {
        cout << "   - OPTION: "; cin >> status;
        if (status == "yes") {
            sm->processRequests();
            sm->writeChanges();
            break;
        }
        if (status == "no")
            return;
        else cout << "   - INVALID OPTION" << endl;
    }
}

void Menu::cleanTerminal() {
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

