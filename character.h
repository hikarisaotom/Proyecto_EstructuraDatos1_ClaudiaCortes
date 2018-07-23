/**************************************************
Class Character:    Wrapper class to represent a
                    character with a class derived
                    from object
Author:             Carlos R. Arias
Date:               2018 - 07 - 16
**************************************************/
#pragma once

#include "object.h"

#include <string>

using std::string;

class Character: public Object{
    char _value;
public:
    Character(char = 0);
    virtual string ToString()const;
    virtual bool Equals(const Object*)const;
    char GetValue()const;
    void SetValue(char);
};
