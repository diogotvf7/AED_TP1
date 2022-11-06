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
template<class T>
bool codeCmp(T *lhs, T *rhs) {
    return lhs->getCode() < rhs->getCode();
}
template<class T>
bool codeCmpReverse(T *lhs, T *rhs) {
    return lhs->getCode() > rhs->getCode();
}

Menu::Menu(ScheduleManager *sm) {
    this->sm = sm;
    this->status = "0";
    this->ucPrintConfig = {{"ORDER", "NAME"}, {"SHOW ATTENDANCE", "YES"}, {"REVERSE", "NO"}, {"YEAR", "ALL"}}; // ORDER->(NAME / ATTENDANCE)   SHOW ATTENDANCE->(YES / NO)   REVERSE->(YES / NO)   YEAR->(1 / 2 / 3 / ALL)
    this->classPrintConfig = {{"ORDER", "ATTENDANCE"}, {"SHOW ATTENDANCE", "YES"}, {"REVERSE", "NO"}, {"YEAR", "ALL"}}; // ORDER->(NAME / ATTENDANCE)   SHOW ATTENDANCE->(YES / NO)   REVERSE->(YES / NO)   YEAR->(1 / 2 / 3 / ALL)
    this->studentPrintConfig = {{"ORDER", "NUMBER OF CLASSES"}, {"SHOW NUMBER OF CLASSES", "YES"}, {"REVERSE", "NO"}}; // ORDER->(NAME / NUMBER OF CLASSES / CODE)   SHOW NUMBER OF CLASSES->(YES / NO)   REVERSE->(YES / NO)
}

vector<UC*> Menu::getUcs() {
    vector<UC*> sortedUcs = sm->getUcVector();
    if (ucPrintConfig["ORDER"] == "NAME" && ucPrintConfig["REVERSE"] == "NO")
        sort(sortedUcs.begin(), sortedUcs.end(), nameCmp<UC>);
    else if (ucPrintConfig["ORDER"] == "NAME" && ucPrintConfig["REVERSE"] == "YES")
        sort(sortedUcs.begin(), sortedUcs.end(), nameCmpReverse<UC>);
    else if (ucPrintConfig["ORDER"] == "ATTENDANCE" && ucPrintConfig["REVERSE"] == "NO")
        sort(sortedUcs.begin(), sortedUcs.end(), attendanceCmp<UC>);
    else if (ucPrintConfig["ORDER"] == "ATTENDANCE" && ucPrintConfig["REVERSE"] == "YES")
        sort(sortedUcs.begin(), sortedUcs.end(), attendanceCmpReverse<UC>);
    return sortedUcs;
}

vector<Class*> Menu::getClasses(UC *uc, Student *s) {
    vector<Class*> sortedClasses;
    if (uc) sortedClasses = uc->getClasses();
    else if (s) sortedClasses = s->getClasses();
    else sortedClasses = sm->getClassesVector();
    if (classPrintConfig["ORDER"] == "NAME" && classPrintConfig["REVERSE"] == "NO")
        sort(sortedClasses.begin(), sortedClasses.end(), nameCmp<Class>);
    else if (classPrintConfig["ORDER"] == "NAME" && classPrintConfig["REVERSE"] == "YES")
        sort(sortedClasses.begin(), sortedClasses.end(), nameCmpReverse<Class>);
    else if (classPrintConfig["ORDER"] == "ATTENDANCE" && classPrintConfig["REVERSE"] == "NO")
        sort(sortedClasses.begin(), sortedClasses.end(), attendanceCmp<Class>);
    else if (classPrintConfig["ORDER"] == "ATTENDANCE" && classPrintConfig["REVERSE"] == "YES")
        sort(sortedClasses.begin(), sortedClasses.end(), attendanceCmpReverse<Class>);
    return sortedClasses;
}

vector<Student*> Menu::getStudents(Class *c) {

    vector<Student*> sortedClassStudents = c->getStudents();

    if (studentPrintConfig["ORDER"] == "NAME" && studentPrintConfig["REVERSE"] == "NO")
        sort(sortedClassStudents.begin(), sortedClassStudents.end(), nameCmp<Student>);
    else if (studentPrintConfig["ORDER"] == "NAME" && studentPrintConfig["REVERSE"] == "YES")
        sort(sortedClassStudents.begin(), sortedClassStudents.end(), nameCmpReverse<Student>);
    else if (studentPrintConfig["ORDER"] == "NUMBER OF CLASSES" && studentPrintConfig["REVERSE"] == "NO")
        sort(sortedClassStudents.begin(), sortedClassStudents.end(), numberOfClassesCmp<Student>);
    else if (studentPrintConfig["ORDER"] == "NUMBER OF CLASSES" && studentPrintConfig["REVERSE"] == "YES")
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
                requestMenu();
                status = "0";
                break;
            case 6:
                cout << "CONFIGURATIONS"
                    << "0. BACK\n";
                cin >> status;
                break;
            case 7: // EXIT
                close();
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
             << "|________________________________________________________________|\n"
             << "|                                                                |\n";

        for (size_t i = 0; i < sortedUcs.size(); i++) {
            cout << "|" << right << setw(14) << to_string((i + 1)) + ". " << setw(10) << "  " + sortedUcs[i]->getName();
            if (ucPrintConfig["SHOW NUMBER OF CLASSES"] == "YES") {
                cout << ": " << setw(12) <<  to_string((sortedUcs[i]->countStudents())) + " classes" << setw(27) << "|" << endl;
            } else cout << setw(40) << '|' << endl;
        }
        cout << "|________________________________________________________________|\n"
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
             << "|________________________________________________________________|\n"
             << "|                                                                |\n";

        for (int i = page * 20; i < min(page * 20 + 20, (int) sortedClasses.size()); i++) {
            cout << "|" << right << setw(14) << to_string(i + 1) + ". " << setw(10) << "  " << sortedClasses[i]->getUc()->getName() << ' ' << sortedClasses[i]->getName();
            if (classPrintConfig["SHOW ATTENDANCE"] == "YES") {
                cout << ": " << setw(12) <<  to_string((sortedClasses[i]->countStudents())) + " students" << setw(27) << "|" << endl;
            } else cout << setw(40) << '|' << endl;
        }

        cout << "|________________________________________________________________|\n"
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

/*void Menu::studentMenu() {

    bool alive = true;
    int page = 0;
    this->studentPrintConfig = {{"ORDER", "NUMBER OF CLASSES"}, {"SHOW NUMBER OF CLASSES", "YES"}, {"REVERSE", "NO"}}; // ORDER->(NAME / NUMBER OF CLASSES / CODE)   SHOW NUMBER OF CLASSES->(YES / NO)   REVERSE->(YES / NO)

    while (alive) {
        cleanTerminal();
        cout << "__________________________________________________________________\n"
             << "|                            CLASSES                             |\n"
             << "|                                                                |\n"
             << "|________________________________________________________________|\n"
             << "|                                                                |\n";

        for (int i = page * 20; i < min(page * 20 + 20, (int) sortedClasses.size()); i++) {
            cout << "|" << right << setw(14) << to_string(i + 1) + ". " << setw(10) << "  " << sortedClasses[i]->getUc()->getName() << ' ' << sortedClasses[i]->getName();
            if (classPrintConfig["SHOW ATTENDANCE"] == "YES") {
                cout << ": " << setw(12) <<  to_string((sortedClasses[i]->countStudents())) + " students" << setw(27) << "|" << endl;
            } else cout << setw(40) << '|' << endl;
        }

        cout << "|________________________________________________________________|\n"
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
                return true;
            else cout << "   - INVALID OPTION" << endl;
        }
    }
}*/

bool Menu::ucClassMenu(UC *uc) {

    bool alive = true;
    vector<Class*> sortedUcClasses = getClasses(uc);

    while (alive) {
        cleanTerminal();
        cout << "__________________________________________________________________\n"
             << "|" << right << setw(32 + (int)(uc->getName().size() / 2)) << uc->getName() << setw(30) << "|\n"
             << "|                                                                |\n"
             << "|________________________________________________________________|\n"
             << "|                                                                |\n";

        for (size_t i = 0; i < sortedUcClasses.size(); i++) {
            cout << "|" << right << setw(14) << to_string(i + 1) + ". " << setw(10) << "  " + sortedUcClasses[i]->getName();
            if (classPrintConfig["SHOW ATTENDANCE"] == "YES") {
                cout << ": " << setw(12) <<  to_string((sortedUcClasses[i]->countStudents())) + " students" << setw(27) << "|" << endl;
            } else cout << setw(40) << '|' << endl;
        }

        cout << "|________________________________________________________________|\n"
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
             << "|________________________________________________________________|\n"
             << "|                                                                |\n";

        for (size_t i = 0; i < sortedClassStudents.size(); i++) {
            cout << "|" << right << setw(14) << to_string(i + 1) + ". " << setw(10) << "  " + sortedClassStudents[i]->getName();
            if (studentPrintConfig["SHOW NUMBER OF CLASSES"] == "YES") {
                cout << ": " << setw(12) <<  to_string((sortedClassStudents[i]->countClasses())) + " classes" << setw(27) << "|" << endl;
            } else cout << setw(40) << '|' << endl;
        }

        cout << "|________________________________________________________________|\n"
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
             << "|" << right << setw(32 + (int)(s->getName().size() / 2)) << s->getName() << setw(30) << "|\n"
             << "|" << right << setw(37) << s->getCode() << setw(27) << "|\n"
             << "|________________________________________________________________|\n"
             << "|                                                                |\n";

        for (int i = 0; i < sortedStudentClasses.size(); i++) {
            cout << "|" << right << setw(14) << to_string(i) + ". " << setw(10) << "  " + sortedStudentClasses[i]->getName();
            if (classPrintConfig["SHOW ATTENDANCE"] == "YES") {
                cout << ": " << setw(12) <<  to_string(sortedStudentClasses[i]->countStudents()) + " classes" << setw(27) << "|" << endl;
            } else cout << setw(40) << '|' << endl;
        }
                                                //TODO
        cout << "|________________________________________________________________|\n"
             << "|                     fAzEr ReQuEsTs AqUi TaMbEm                 |\n"
             << "|                     WRITE 'back' TO GO BACK                    |\n"
             << "|________________________________________________________________|\n\n";

        while (true) {

            cout << "   - OPTION: "; cin >> status;
            if (isNumerical(status) && 1 <= stoi(status) && stoi(status) <= sortedStudentClasses.size()) {
                cout << status;
                break;
            }
            else if (status == "back")
                return true;
            else cout << "   - INVALID OPTION" << endl;
        }
    }
    return false;
}

void Menu::addRequest() {
    string tmp1, tmp2;
    cout << "\nWrite Student name or code: "; cin >> tmp1;
    cout << "Write intended Class code: "; cin >> tmp2;
    if (isNumerical(tmp1)) sm->createRequest(new AddRequest(sm->findStudentByCode(tmp1), sm->findClass(tmp2)));
    else sm->createRequest(new AddRequest(sm->findStudentByName(tmp1), sm->findClass(tmp2)));
}
void Menu::removeRequest() {
    string tmp1, tmp2;
    cout << "\nWrite Student name or code: "; cin >> tmp1;
    cout << "Write current Class code: "; cin >> tmp2;
    if (isNumerical(tmp1)) sm->createRequest(new RemoveRequest(sm->findStudentByCode(tmp1), sm->findClass(tmp2)));
    else sm->createRequest(new RemoveRequest(sm->findStudentByName(tmp1), sm->findClass(tmp2)));
}
void Menu::switchRequest() {
    string tmp1, tmp2, tmp3;
    cout << "\nWrite Student name or code: "; cin >> tmp1;
    cout << "Write current Class code: "; cin >> tmp2;
    cout << "Write intended Class code: "; cin >> tmp3;
    if (isNumerical(tmp1)) sm->createRequest(new SwitchRequest(sm->findStudentByCode(tmp1), sm->findClass(tmp2), sm->findClass(tmp3)));
    else sm->createRequest(new SwitchRequest(sm->findStudentByName(tmp1), sm->findClass(tmp2), sm->findClass(tmp3)));
}
void Menu::swapRequest() {
    string tmp1, tmp2, tmp3, tmp4;
    cout << "\nWrite Student name or code: "; cin >> tmp1;
    cout << "Write Colleague name or code: "; cin >> tmp2;
    cout << "Write current Class code: "; cin >> tmp3;
    cout << "Write intended Class code: "; cin >> tmp4;
    if (isNumerical(tmp1)) sm->createRequest(new SwapRequest(sm->findStudentByCode(tmp1), sm->findStudentByCode(tmp2), sm->findClass(tmp3), sm->findClass(tmp4)));
    else sm->createRequest(new SwapRequest(sm->findStudentByCode(tmp1), sm->findStudentByName(tmp2), sm->findClass(tmp3), sm->findClass(tmp4)));

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

void Menu::close() {
    cleanTerminal();

    cout << "__________________________________________________________________\n"
         << "|                 Do you wish to save your data?                 |\n"
         << "|                            yes / no                            |\n"
         << "|________________________________________________________________|\n";

    while (true) {
        cout << "   - OPTION: "; cin >> status;
        if (status == "yes") {
            sm->writeClassesFile();
            sm->writeClassesPerUcFile();
            sm->writeStudentsClassesFile();
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

