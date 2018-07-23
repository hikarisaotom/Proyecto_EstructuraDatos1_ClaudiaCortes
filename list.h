/**************************************************
Class List:         Abstract class that represents
                    the ADT List, this will be the
                    base class of all List
                    implementations. Methods
                    Size() and IsEmpty() are defined
                    here and don't need to be
                    overloaded
Author:             Carlos R. Arias
Date:               2018 - 07 - 16
**************************************************/
#pragma once

#include "object.h"

class List: public Object{
protected:
    size_t _size;
public:
    List();
    virtual ~List();
    virtual string ToString()const;

    virtual bool Insert(Object*, size_t) = 0;
    virtual bool Remove(size_t) = 0;
    virtual Object* Get(size_t)const = 0;
    virtual int IndexOf(const Object*)const = 0;
    size_t Size()const;
    bool IsEmpty()const;
};
