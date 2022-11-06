//
// Created by diogotvf7 on 04-11-2022.
//

#include "Oopsie.h"

#include <utility>

using namespace std;

Oopsie::Oopsie(string message) {
    this->message = std::move(message);
}

std::string Oopsie::what() {
    return message;
}