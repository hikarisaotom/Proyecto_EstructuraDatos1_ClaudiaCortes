#include "integer.h"

#include <sstream>
#include <string>
#include <typeinfo>

using std::string;
using std::stringstream;


Integer::Integer(int value): _value(value){

}
string Integer::ToString()const{
    stringstream retVal;
    retVal << _value;
    return retVal.str();
}
int Integer::GetValue()const{
    return _value;
}
void Integer::SetValue(int value){
    _value = value;
}
bool Integer::Equals(const Object* rhs)const{
    if (rhs == nullptr)
        return false;
    if (typeid(*rhs) != typeid(*this))
        return false;
    if (rhs == this)
        return true;
    const Integer* other = dynamic_cast<const Integer*>(rhs);
    if (other->GetValue() == _value)
        return true;
    else
        return false;
}
