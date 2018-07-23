/**************************************************
Unit Test Program:  This program has the logic for
                    executing all the operations
                    of the ADT List with the Fixed
                    Size Array implementation.
                    If any assert fails the Program
                    will crash and indicate which
                    assert failed.
Author:             Carlos R. Arias
Date:               2018 - 07 - 16
**************************************************/


#include "object.h"
#include "integer.h"
#include "character.h"
#include "doublelinkedlist.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cassert>


using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::stringstream;
using std::setw;
using std::setprecision;
using std::fixed;


int main(int argc, char* argv[]){
    const float COUNT = 15;
    int testNumber = 1;
    DoubleLinkedList list;

    Integer* toInsert = nullptr;
    Integer toCompare;
    cerr << " ===========================================================" << endl;
    cerr << " 1.    Testing Empty List" << endl;
    assert(list.IsEmpty() == true);
    assert(list.Get(0) == nullptr);
    assert(list.Get(1) == nullptr);
    cerr << " " << setw(2) << testNumber << ".    Passed "
         << setprecision(2) << fixed << (testNumber / COUNT) << endl;
    cerr << list.ToString() << endl;
    testNumber++;
    cerr << " -----------------------------------------------------------" << endl << endl;

    cerr << " ===========================================================" << endl;
    cerr << " 2.    Inserting on Empty List" << endl;
    toInsert = new Integer(4);
    assert(list.Insert(toInsert, 0) == true);
    assert(list.Size() == 1);
    assert(list.IsEmpty() == false);
    toCompare.SetValue(4);
    assert(list.Get(0)->Equals(&toCompare));
    cerr << " " << setw(2) << testNumber << ".    Passed "
         << setprecision(2) << fixed << (testNumber / COUNT) << endl;
    cerr << list.ToString() << endl;
    testNumber++;
    cerr << " -----------------------------------------------------------" << endl << endl;

    cerr << " ===========================================================" << endl;
    cerr << " 3.    Inserting Invalid Position" << endl;
    toInsert = new Integer(2);
    assert(list.Insert(toInsert, 2) == false);
    cerr << " " << setw(2) << testNumber << ".    Passed "
         << setprecision(2) << fixed << (testNumber / COUNT) << endl;
    cerr << list.ToString() << endl;
    testNumber++;
    cerr << " -----------------------------------------------------------" << endl << endl;

    cerr << " ===========================================================" << endl;
    cerr << " 4.    Inserting at the End" << endl;
    assert(list.Insert(toInsert, 1) == true);
    cerr << " " << setw(2) << testNumber << ".    Passed "
         << setprecision(2) << fixed << (testNumber / COUNT) << endl;
    cerr << list.ToString() << endl;
    testNumber++;
    cerr << " -----------------------------------------------------------" << endl << endl;

    cerr << " ===========================================================" << endl;
    cerr << " 5.    Comparing Elements" << endl;
    toCompare.SetValue(4);
    assert(list.Get(0)->Equals(&toCompare) == true);
    toCompare.SetValue(2);
    assert(list.Get(1)->Equals(&toCompare) == true);
    cerr << " " << setw(2) << testNumber << ".    Passed "
         << setprecision(2) << fixed << (testNumber / COUNT) << endl;
    cerr << list.ToString() << endl;
    testNumber++;
    cerr << " -----------------------------------------------------------" << endl << endl;

    cerr << " ===========================================================" << endl;
    cerr << " 6.    Inserting at the beginning" << endl;
    assert(list.Insert(new Integer(7), 0) == true);
    assert(list.Size() == 3);
    cerr << " " << setw(2) << testNumber << ".    Passed "
         << setprecision(2) << fixed << (testNumber / COUNT) << endl;
    cerr << list.ToString() << endl;
    testNumber++;
    cerr << " -----------------------------------------------------------" << endl << endl;

    cerr << " ===========================================================" << endl;
    cerr << " 7.    Comparing Elements" << endl;
    toCompare.SetValue(7);
    assert(list.Get(0)->Equals(&toCompare) == true);
    toCompare.SetValue(4);
    assert(list.Get(1)->Equals(&toCompare) == true);
    toCompare.SetValue(2);
    assert(list.Get(2)->Equals(&toCompare) == true);
    cerr << " " << setw(2) << testNumber << ".    Passed "
         << setprecision(2) << fixed << (testNumber / COUNT) << endl;
    cerr << list.ToString() << endl;
    testNumber++;
    cerr << " -----------------------------------------------------------" << endl << endl;

    cerr << " ===========================================================" << endl;
    cerr << " 8.    Inserting at the end (3x)" << endl;
    assert(list.Insert(new Integer(3), list.Size()) == true);
    assert(list.Insert(new Integer(9), list.Size()) == true);
    assert(list.Insert(new Integer(8), list.Size()) == true);
    cerr << " " << setw(2) << testNumber << ".    Passed "
         << setprecision(2) << fixed << (testNumber / COUNT) << endl;
    cerr << list.ToString() << endl;
    testNumber++;
    cerr << " -----------------------------------------------------------" << endl << endl;


    cerr << " ===========================================================" << endl;
    cerr << " 9.    Comparing Elements (Non existent value)" << endl;
    toCompare.SetValue(0);
    for (size_t i = 0; i < list.Size(); i++) {
        assert(list.Get(i)->Equals(&toCompare) == false);
    }
    assert(list.IsEmpty() == false);
    cerr << " " << setw(2) << testNumber << ".    Passed "
         << setprecision(2) << fixed << (testNumber / COUNT) << endl;
    cerr << list.ToString() << endl;
    testNumber++;
    cerr << " -----------------------------------------------------------" << endl << endl;

    cerr << " ===========================================================" << endl;
    cerr << " 10.   Remove Element at the end" << endl;
    assert(list.Remove(5) == true);
    assert(list.ToString() == "[7, 4, 2, 3, 9]");
    cerr << " " << setw(2) << testNumber << ".    Passed "
         << setprecision(2) << fixed << (testNumber / COUNT) << endl;
    cerr << list.ToString() << endl;
    testNumber++;
    cerr << " -----------------------------------------------------------" << endl << endl;


    cerr << " ===========================================================" << endl;
    cerr << " 11.   Remove Element at the beginning" << endl;
    assert(list.Remove(0) == true);
    assert(list.Size() == 4);
    assert(list.ToString() == "[4, 2, 3, 9]");
    cerr << " " << setw(2) << testNumber << ".    Passed "
         << setprecision(2) << fixed << (testNumber / COUNT) << endl;
    cerr << list.ToString() << endl;
    testNumber++;
    cerr << " -----------------------------------------------------------" << endl << endl;

    cerr << " ===========================================================" << endl;
    cerr << " 12.   Comparing Elements" << endl;
    cout << list.ToString() << endl;
    toCompare.SetValue(4);
    assert(list.Get(0)->Equals(&toCompare) == true);
    toCompare.SetValue(2);
    assert(list.Get(1)->Equals(&toCompare) == true);
    toCompare.SetValue(3);
    assert(list.Get(2)->Equals(&toCompare) == true);
    toCompare.SetValue(9);
    assert(list.Get(3)->Equals(&toCompare) == true);
    cerr << " " << setw(2) << testNumber << ".    Passed "
         << setprecision(2) << fixed << (testNumber / COUNT) << endl;
    cerr << list.ToString() << endl;
    testNumber++;
    cerr << " -----------------------------------------------------------" << endl << endl;


    cerr << " ===========================================================" << endl;
    cerr << " 13.   Remove Element from the middle" << endl;
    cout << list.ToString() << endl;
    assert(list.Remove(2) == true);
    assert(list.Size() == 3);
    toCompare.SetValue(4);
    assert(list.Get(0)->Equals(&toCompare) == true);
    toCompare.SetValue(2);
    assert(list.Get(1)->Equals(&toCompare) == true);
    toCompare.SetValue(9);
    assert(list.Get(2)->Equals(&toCompare) == true);
    cerr << " " << setw(2) << testNumber << ".    Passed "
         << setprecision(2) << fixed << (testNumber / COUNT) << endl;
    cerr << list.ToString() << endl;
    testNumber++;
    cerr << " -----------------------------------------------------------" << endl << endl;


    cerr << " ===========================================================" << endl;
    cerr << " 14.   Remove Element at the end" << endl;
    cout << list.ToString() << endl;
    assert(list.Remove(list.Size() - 1) == true);
    assert(list.Size() == 2);
    cerr << " " << setw(2) << testNumber << ".    Passed "
         << setprecision(2) << fixed << (testNumber / COUNT) << endl;
    cerr << list.ToString() << endl;
    testNumber++;
    cerr << " -----------------------------------------------------------" << endl << endl;


    cerr << " ===========================================================" << endl;
    cerr << " 15.   Comparing Elements" << endl;
    toCompare.SetValue(4);
    assert(list.Get(0)->Equals(&toCompare) == true);
    toCompare.SetValue(2);
    assert(list.Get(1)->Equals(&toCompare) == true);
    cerr << " " << setw(2) << testNumber << ".    Passed "
         << setprecision(2) << fixed << (testNumber / COUNT) << endl;
    cerr << list.ToString() << endl;
    testNumber++;
    cerr << " -----------------------------------------------------------" << endl << endl;

    cerr << "All Unit Tests Passed. Congratulations" << endl;


}
