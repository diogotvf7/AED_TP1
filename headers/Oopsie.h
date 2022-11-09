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

    /**
     * @brief Constructor for the Oopsie Exceptions Class;
     * @param messages string message with the exception cause;
     */
    explicit Oopsie(std::string message);

    /**
     * @brief Get function for the exception cause;
     * @return a string with the exception cause;
     */
    std::string what();
private:
    std::string message;
};


#endif //AED_TP1_OOPSIE_H
