#include "list.h"

#include <sstream>
#include <string>

using std::string;
using std::stringstream;

List::List(){
    _size = 0;
}
List::~List(){

}
size_t List::Size()const{
    return _size;
}
bool List::IsEmpty()const{
    return _size == 0;
}
string List::ToString()const{
    stringstream retVal;
    retVal << "[";
    for (size_t i = 0; i < _size; i++) {
        if (i != _size - 1)
            retVal << Get(i)->ToString() << ", ";
        else
            retVal << Get(i)->ToString() << "]";
    }
    return retVal.str();
}
