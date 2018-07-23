/**************************************************
Class Object:       Base class to all classes,
                    model after java's Object class.
                    Any element that can be inserted
                    into these lists must use the
                    Object class as base class.
Author:             Carlos R. Arias
Date:               2018 - 07 - 16
**************************************************/
#pragma once

#include <string>
using std::string;

class Object{
public:
    Object();
    virtual string ToString()const;
    virtual bool Equals(const Object*)const;
    virtual ~Object();
};
