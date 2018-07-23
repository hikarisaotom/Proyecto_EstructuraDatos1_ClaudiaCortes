/**************************************************
Class Integer:      Wrapper class to represent an
                    int with a class derived
                    from object
Author:             Carlos R. Arias
Date:               2018 - 07 - 16
**************************************************/

#pragma once

#include "object.h"

#include <string>

using std::string;

class Integer: public Object{
    int _value;
public:
    Integer(int = 0);
    virtual string ToString()const;
    virtual bool Equals(const Object*)const;
    int GetValue()const;
    void SetValue(int);
};
