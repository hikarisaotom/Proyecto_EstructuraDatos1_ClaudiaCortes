#include "object.h"
#include "integer.h"
#include "character.h"
#include "doublelinkedlist.h"
#include "list.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cassert>

using std::cerr;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::setw;
using std::string;
using std::stringstream;

using namespace std;
/*
int main(){
    DoubleLinkedList lista;
    DoubleLinkedList lista2;
    Integer* toInsert = nullptr;

    //insertar
    toInsert = new Integer(1);
    if(lista.Insert(toInsert, 0)){
        cout<< "pues si se pudo" << endl;
    }else{
        cout<< "** no se pudo"<< endl;
    }

    Object*  elObjeto = lista.Get(0);
    if(elObjeto != nullptr){
        cout<<" ok aa-> "+ elObjeto->ToString()<< endl;
    }


    toInsert = new Integer(2);
    if(lista.Insert(toInsert, 1)){
        cout<< "pues si se pudo" << endl;
    }else{
        cout<< "** no se pudo"<< endl;
    }

    elObjeto = lista.Get(0);
    if(elObjeto != nullptr){
        cout<<" ok aa-> "+ elObjeto->ToString()<< endl;
    }


    cout<< "Lista uno: " << endl;
    for(size_t i=0; i<lista.Size(); i++){
        Object* elObjeto = lista.Get(i);
        if(elObjeto != nullptr){
            cout<< i<< " ok -> "+ elObjeto->ToString()<< endl;
        }else{
            cout<< "NO hay elementos " << endl;
        }
    }    
    
    ///////////////////////////
    //insertar
    toInsert = new Integer(1);
    if(lista2.Insert(toInsert, 0)){
        cout<< "pues si se pudo" << endl;
    }else{
        cout<< "** no se pudo"<< endl;
    }

    elObjeto = lista2.Get(0);
    if(elObjeto != nullptr){
        cout<<" ok aa-> "+ elObjeto->ToString()<< endl;
    }


    toInsert = new Integer(4);
    if(lista2.Insert(toInsert, 1)){
        cout<< "pues si se pudo" << endl;
    }else{
        cout<< "** no se pudo"<< endl;
    }

    elObjeto = lista2.Get(0);
    if(elObjeto != nullptr){
        cout<<" ok aa-> "+ elObjeto->ToString()<< endl;
    }


    cout<< "Lista dos: " << endl;
    for(size_t i=0; i<lista2.Size(); i++){
        Object* elObjeto = lista2.Get(i);
        if(elObjeto != nullptr){
            cout<< i<< " ok -> "+ elObjeto->ToString()<< endl;
        }else{
            cout<< "NO hay elementos " << endl;
        }
    }    
    

    Integer toCompare;
    toCompare.SetValue(1);
    if(lista.Get(0)->Equals(&toCompare)){
        cout<< "son iguales"<< endl;
    }else{
        cout<< "no lo son"<< endl;
    }

    if(lista.IndexOf(&toCompare) == 0){
        cout<< "Funciona"<< endl;
    }



    //delete lista, lista2;
    cout<< endl<< "Termino!"<< endl;
}
*/
int main(int argc, char *argv[])
{
    DoubleLinkedList *lista = new DoubleLinkedList;
    DoubleLinkedList *lista2 = new DoubleLinkedList;
    Integer *o;
    Integer *x;
    Integer *z;
    o = new Integer(1);
    x = new Integer(1);
    z = new Integer(19);

    cout << "Insertar al Inicio al estra vacía: " << endl;
    lista->Insert(o, 0);
    lista2->Insert(o, 0);
    cout << "Comparandolas con datos" << endl;
    if (lista->Equals(lista2))
    {
        cout << "iguales" << endl;
    }
    else
    {
        cout << "diferentes" << endl;
    }

    cout << "Insertar al datos diferentes: " << endl;
    lista2->Insert(x, 0);

    if (lista->Equals(lista2))
    {
        cout << "iguales" << endl;
    }
    else
    {
        cout << "diferentes" << endl;
    }

    cout << "Insertar al datos diferentes: " << endl;
    lista->Insert(x, 0);

    if (lista->Equals(lista2))
    {
        cout << "iguales" << endl;
    }
    else
    {
        cout << "diferentes" << endl;
    }
    cout << "Probando INdexof" << endl;
    cout << "En la lista 1" << endl;
    cout << "NUmero" << lista->IndexOf(x) << endl;

    cout << "Con un dato no existente" << endl;
    cout << "NUmero" << lista->IndexOf(z) << endl;
    delete lista2, lista;
}
