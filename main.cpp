/**************************************************
Main Program:       Main class to test the program
                    with output directed to cout.
Author:             Carlos R. Arias
Date:               2018 - 07 - 16
Issue:              Should it have a menu for
                    testing?
**************************************************/

#include "integer.h"
#include "doublelinkedlist.h"
#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::stringstream;




int main(int argc, char* argv[]){
    DoubleLinkedList list();
    Integer* toInsert = nullptr;
    toInsert = new Integer(4);
    cout << list.Insert(toInsert, 0) << endl;
    cout << list.ToString() << endl;
    toInsert = new Integer(8);
    cout << list.Insert(toInsert, 1) << endl;
    cout << list.ToString() << endl;
    toInsert = new Integer(-1);
    cout << list.Insert(toInsert, 3) << endl;
    cout << list.ToString() << endl;
    toInsert->SetValue(2);
    cout << list.Insert(toInsert, 2) << endl;
    cout << list.ToString() << endl;
    toInsert = new Integer(9);
    cout << list.Insert(toInsert, 1) << endl;
    cout << list.ToString() << endl;
    toInsert = new Integer(3);
    cout << list.Insert(toInsert, 0) << endl;
    cout << list.ToString() << endl;
    toInsert = new Integer(-2);
    cout << list.Insert(toInsert, 0) << endl;
    delete toInsert;
    cout << list.ToString() << endl;


    return 0;
}
