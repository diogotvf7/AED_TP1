//
// Created by diogotvf7 on 04-11-2022.
//

#ifndef AED_TP1_OOPSIE_H
#define AED_TP1_OOPSIE_H

#include <iostream>
#include <string>

#include "Class.h"

class Oopsie : public std::exception {

public:
    explicit Oopsie(std::string msg);
    std::string what();
private:
    std::string message;
};


#endif //AED_TP1_OOPSIE_H
