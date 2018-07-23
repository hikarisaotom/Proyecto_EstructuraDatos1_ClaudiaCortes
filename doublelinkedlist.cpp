// Titulo: Proyecto #1
//Implementacion del TDA Lista usando Listas Doblemente Enlazadas
//
// Proposito: crear un API que contiene todas las operaciones de lista usando listas
//enlazadas
//
// Clase: CCC209 – Q3 – 2018
//
// Author: Claudia Patricia Cortes Pavon 
#include "object.h"
#include "list.h"
#include "doublelinkedlist.h"

#include <string>
#include <typeinfo>
#include <iostream>
using namespace std;
using std::string;

/*
Inserta un elemento en la lista enlazada
Params: Object* element, representa el elemento que se desea insertar
size_t position, representa la posición donde se desea insertar
Returna: verdadero si la inserción fue exitosa, falso si no se pudo insertar
Errores: si la posición es inválida la función termina retornando falso*/

DoubleLinkedList::DoubleLinkedList(){
  
    _head=nullptr;
}

/*Constructor de copia privado para prevenir
copias de la lista.*/
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList&){

}

const DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList& rhs)const {
    return rhs;
}


DoubleLinkedList::~DoubleLinkedList(){
    cout<<"LIberando Memoria";
}

bool DoubleLinkedList::Equals(const Object* toCompare) const{
    if(toCompare==nullptr){
        cout<<"DI"<<endl;
        return false;
    }
    if(typeid(*toCompare) != typeid(*this)){
        cout<<"DI"<<endl;
        return false;
    }
    if(toCompare==this){
        cout<<"DI"<<endl;
        return true;
    }
    const DoubleLinkedList* tempList = dynamic_cast<const DoubleLinkedList*>(toCompare);
    for(size_t i=0; i<_size;i++){
        if(tempList->Get(i)==nullptr || Get(i)==nullptr){
            cout<<"DI"<<endl;
            return false;
        }
        if (!Get(i)->Equals(tempList->Get(i))){
            cout<<"DI"<<endl;
            return false;
        }
    }
    cout<<"I"<<endl;
    return true;
}


/*Recibimos como parametro el dato o valor que tendra el nodo y la posicion en la que lo insertaremos
el anterior del nuevo nodo sera el anterior del nodo que se desplazara
el siguiente del nuevo nodo sera el nodo desplazado 
el nodo anterior del nodo desplazado sera el nodo nuevo, el nodo siguiente del desplazado se conserva*/

bool DoubleLinkedList::Insert(Object* element, size_t position){
    cout<<"INSERTANDO....."<<endl;
    if(position>_size){//Validacion de posiciones
       return false;
   }

    if(_size ==0){
        cout<<"Entro al caso Vacio"<<endl;
        Node * newNode=new Node();
        cout<<"CReado"<<endl;
        newNode->data=element;
        cout<<"elemento"<<endl;
        newNode->next=nullptr;
        cout<<"next"<<endl;
        newNode->prev=nullptr;
        cout<<"prev"<<endl;
        newNode->next=_head;
        cout<<"next-cabecera"<<endl;
        _head=newNode;
        cout<<"cambio cabacera"<<endl;
        _size++;
        cout<<"nuevo size"<<_size<<endl;
        return true;
    }

    if(_size>0&&position==0){//Inicio
    /*Creamos el nuevo nodo y modificamos los enlaces,
     tambien seteamos el nuevo nodo como la cabecera*/
     cout<<"Entro al caso inicio"<<endl;
        Node * newNode= new Node();
        newNode->data=element;
        newNode->next=nullptr;     
        newNode->prev=nullptr;
        newNode->next=_head;
        _head=newNode;
        _size++;
        return true;
    }

    if(position==_size&&position>0){//Final
    cout<<"Entro al caso final"<<endl;
     Node * newNode= new Node();
        newNode->data=element;
        newNode->next=nullptr;
        newNode->prev=nullptr;
         Node * temporal=_head;
        while(temporal->next!=nullptr){
            temporal=temporal->next;
        }
        temporal->next=newNode;
        newNode->next=nullptr;
        newNode->prev=temporal;
        _size++;
        return true;
    }

    if((position>0&&position<_size)&&_size>0){//En medio
    cout<<"Entro al caso medio"<<endl;
        Node * newNode= new Node();
        newNode->data=element;
        newNode->next=nullptr;
        newNode->prev=nullptr;
        Node * temporal=_head;
        for(size_t i=0;i<position-1;i++){
            temporal=temporal->next;
        }
       
            temporal->next=newNode;
            newNode->prev=temporal;
            newNode->next=temporal->next;
            (temporal->next)->prev=newNode;
           
        _size++;
        return true;
    }
   
}//Cierre de la Llave

/*Recibimos como parametro el numero que eliminaremos
Nodo Previo al eliminado:
su siguiente sera el nodo siguiente del eliminado 
Nodo siguiente  al eliminado:
su previo sera el previo al eliminado
 */
bool DoubleLinkedList::Remove(size_t position){
     cout<<"Eliminando....."<<endl;
    if(position>_size){//Validacion de posiciones
       return false;
   }

    if(_size ==0){
        cout<<"eliminando en Vacio"<<endl;
        cout<<"NO HAY NADA QUE ELIMINAR"<<endl;
        return false;
    }

    if(_size>0&&position==0){//Inicio
        cout<<"eliminando en Inicio"<<endl;
        Node * temporal=_head;
        _head=temporal->next;
        _head->prev=nullptr;
        delete temporal;
        _size--;
        return true;
    }

    if(position==_size-1&&position>0){//Final
        cout<<"Eliminando al final"<<endl;
        Node * temporal= _head;
         cout<<"se asigna el head"<<endl;
        while(temporal->next!=nullptr||temporal->next!=NULL){
            temporal=temporal-> next;
            cout<<"Asignando siguiente"<<endl;
        }
        (temporal->prev)->next=nullptr;
        cout<<"Asignando null "<<endl;
        delete temporal;
        cout<<"eliminando temporal"<<endl;
        _size--;
        cout<<"Asignando siguiente"<<endl;
        return true;
    }

    if((position>0&&position<_size)&&_size>0){//En medio
        cout<<"elimanando en medio"<<endl;
        size_t i=0;
        Node* temporal=_head;
        while(i!=position){
            temporal=temporal->next;
            i++;
        }
        (temporal->next)->prev=temporal->prev;
        (temporal->prev)->next=temporal->next;
        delete temporal;
        _size--;
        return true;
    }
 
}

/*recorreremos buscando y cambiando al siguiente nodo hasta llegar al limite*/
Object* DoubleLinkedList::Get(size_t position)const{
     cout<<"Get...."<<endl;
     if(position>=_size){
         return nullptr;
     }
     if(position==0){
         return _head->data;
     }
     if(position==1){
         Node * temporal=_head->next;
         return temporal->data;
     }
     if(position>1&&position<(_size-1)){
         Node * temporal=_head;
         for(size_t i=0;i<position;i++){
             temporal=temporal->next;
         }
         return temporal->data;
     }

     if(position==(_size-1)){
         Node * temporal=_head;
         for(size_t i=0;i<_size-1;i++){//cambie size a size-1
             temporal=temporal->next;
         }
         return temporal->data;
     }
}
/*Recorre la lista, y si encuentra coincidencia entonces devuelve la posicion en la que se encontro*/
int DoubleLinkedList::IndexOf(const Object* rhs)const{
     cout<<"INdexOf...."<<endl;
    for (size_t i = 0; i < _size; i++) {
        if (Get(i)->Equals(rhs)){
             return i;
        }
    }
    return -1;
}