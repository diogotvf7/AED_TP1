//
// Created by diogotvf7 on 04-11-2022.
//

#include "Oopsie.h"

using namespace std;

Oopsie::Oopsie(string message) {
    this->message = message;
}

std::string Oopsie::what() {
    return message;
}