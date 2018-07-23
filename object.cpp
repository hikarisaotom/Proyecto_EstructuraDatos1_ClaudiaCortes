#include "object.h"

#include <string>
#include <sstream>
#include <typeinfo>

using std::string;
using std::stringstream;


Object::Object(){

}

string Object::ToString()const{
    stringstream ss;
    ss << this;
    return ss.str();
}
bool Object::Equals(const Object* other)const{
    if (other == nullptr)
        return false;
    if (typeid(*other) != typeid(*this))
        return false;
    if (other == this)
        return true;
    else
        return false;
}
Object::~Object(){

}
