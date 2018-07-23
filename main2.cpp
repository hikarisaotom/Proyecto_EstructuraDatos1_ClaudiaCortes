#include "list.h"
#include "object.h"
#include "doublelinkedlist.h"
#include "character.h"
#include "integer.h"

#include <iostream>
#include <string>
using std::ostream;
using std::istream;
using std::string;
using std::cerr;
using std::endl;

int main(int argc, char* argv[]){
    DoubleLinkedList* lista=new DoubleLinkedList;
    DoubleLinkedList* lista2=new DoubleLinkedList;
    Integer* o;
    cout<<"Comparar Vacías"<<endl;
    lista->Equals(lista2);
    cout<<"Get Listas Vacias"<<endl;
    lista->Get(0);
    cout<<"IndexOf Vacia Lista"<<endl;
    cout<<lista->IndexOf(o)<<endl;
    o=new Integer(0);
    cout<<"Insertar al Inicio al estra vacía: "<<endl;
    lista->Insert(o,0);
    lista2->Insert(o,0);
    o=new Integer(1);
    cout<<"Insertar al Inicio pero sin estar vacía: "<<endl;
    lista->Insert(o,0);
    lista2->Insert(o,0);
    o=new Integer(2);
    cout<<"En Inicio: "<<endl;
    lista->Insert(o,0);
    lista2->Insert(o,0);
    o=new Integer(3);
    cout<<"En Inicio: "<<endl;
    lista->Insert(o,0);
    lista2->Insert(o,0);
    o=new Integer(4);
    cout<<"En Inicio: "<<endl;
    lista->Insert(o,0);
    lista2->Insert(o,0);
    o=new Integer(5);
    cout<<"Al Medio: 3"<<endl;
    lista->Insert(o,3);
    lista2->Insert(o,3);
    o=new Integer(6);
    cout<<"Al medio: 1"<<endl;
    lista->Insert(o,1);
    lista2->Insert(o,1);
    cout<<"Al final"<<endl;
    o=new Integer(8);
    lista->Insert(o,7);
    lista2->Insert(o,7);
    cout<<"Al medio: 2"<<endl;
    o=new Integer(7);
    lista->Insert(o,2);
    lista2->Insert(o,2);
    cout<<"Al final"<<endl;
    o=new Integer(9);
    lista->Insert(o,9);
    lista2->Insert(o,9);
    cout<<"Lista"<<endl;
    cout<<"1"<<lista->ToString()<<endl;
    cout<<"2"<<lista2->ToString()<<endl;
    cout<<"Index Of 9"<<endl;
    o=new Integer(9);
    cout<<lista->IndexOf(o)<<endl;
    cout<<"Remove 0"<<endl;
    lista->Remove(0);
    lista2->Remove(0);
    cout<<"Remove Ultimo 8"<<endl;
    lista->Remove(8);
    lista2->Remove(8);
    cout<<"Remove 0"<<endl;
    lista->Remove(0);
    lista2->Remove(0);
    cout<<"Remove Ultimo 6"<<endl;
    lista->Remove(6);
    lista2->Remove(6);
    cout<<"Remove Medio 4"<<endl;
    lista->Remove(4);
    lista2->Remove(4);
    cout<<"Remove Medio 2"<<endl;
    lista->Remove(2);
    lista2->Remove(2);
    cout<<"Remove Medio 2"<<endl;
    lista->Remove(2);
    lista2->Remove(2);
    cout<<"Remove ultimo 2"<<endl;
    lista->Remove(2);
    lista2->Remove(2);
    cout<<"Comparar"<<endl;
    lista2->Remove(0);
    cout<< lista->Equals(lista2)<<endl;
    //cout<<false<<endl;
    cout<<"1"<<lista->ToString()<<endl;
    cout<<"2"<<lista2->ToString()<<endl;
    cout<<"Index Of 3"<<endl;
    o=new Integer(3);
    cout<<"P"<<lista->IndexOf(o)<<endl;
    cout<<"Eliminar Listas"<<endl;;
    delete lista2,lista;
}
