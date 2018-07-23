#include "character.h"

#include <sstream>
#include <string>
#include <typeinfo>

using std::string;
using std::stringstream;


Character::Character(char value): _value(value){

}
string Character::ToString()const{
    stringstream retVal;
    retVal << _value;
    return retVal.str();
}
char Character::GetValue()const{
    return _value;
}
void Character::SetValue(char value){
    _value = value;
}
bool Character::Equals(const Object* rhs)const{
    if (rhs == nullptr)
        return false;
    if (typeid(*rhs) != typeid(*this))
        return false;
    if (rhs == this)
        return true;
    const Character* other = dynamic_cast<const Character*>(rhs);
    if (other->GetValue() == _value)
        return true;
    else
        return false;
}
