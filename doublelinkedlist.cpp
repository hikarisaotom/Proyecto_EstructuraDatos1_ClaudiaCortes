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
Constructor vacio de la clase DoubleLinkedList, inicializa en nullptr la cabecera de la lista
Params: Ninguno
Retorna: NO retornara nada
Errores: */

DoubleLinkedList::DoubleLinkedList()
{

    _head = nullptr;
}

/*
Constructor de copia privado para prevenir
copias de la lista.
Params: Lista desreferenciada
Retorna: NA
Errores: */
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList &)
{
}

/*
Sobrecarga del operador =, se
hace privado para prevenir asignaciones.
Params: Una lista doblemente enlazada desreferenciada
Retorna: El parametro
Errores: NInguno*/

const DoubleLinkedList &DoubleLinkedList::operator=(const DoubleLinkedList &rhs) const
{
    return rhs;
}

/*
Destructor del objeto de la clase DoubleLinkedList
Params: ninguno
Retorna: NA
Errores: NInguno*/
DoubleLinkedList::~DoubleLinkedList()
{
    cout << "Liberando Memoria" << endl;
}

/*Compara dos listas y retorna un valor booleano que indica si se cumple o no la condicion de que sean semejantes
Retorna: Verdadero si las listas son iguales, falsas en caso contrario.
Errores: */
bool DoubleLinkedList::Equals(const Object *compare) const
{
    if (compare == nullptr)
    {
        return false;
    }
    if (typeid(*compare) != typeid(*this))
    {
        return false;
    }
    const DoubleLinkedList *newListToCompare = dynamic_cast<const DoubleLinkedList *>(compare);
    for (size_t i = 0; i < _size; i++)
    {
        if (newListToCompare->Get(i) != this->Get(i))
        {
            return false;
        }
    }
    return true;
}

/*Inserta un objeto en la lista en la posición indicada.
Params: Recibimos como parametro el dato o valor que tendra el nodo y la posicion en la que lo insertaremos
Retorna: Verdadero si la insercion fue exitosa, falso en caso contrario
Errores: Si la posicion es menor que , o es mayor al tamano que tiene la lista retornara falso*/

bool DoubleLinkedList::Insert(Object *element, size_t position)
{
    //cout << "INSERTANDO....." << endl;
    if (position > _size)
    { //Validacion de posiciones
        return false;
    }
    /*General para los casos: Creamos el nuevo nodo y modificamos los enlaces,
     Casos:
      insercion en Lista Vacia
      insercion en el inicio
      insercion en el final
      insercion en medio*/
    if (_size == 0)
    {
        cout << "Caso:Lista Vacia" << endl;
        Node *newNode = new Node();
        newNode->data = element;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        newNode->next = _head;
        _head = newNode;
        _size++;
        return true;
    }

    if (position == 0 && _size > 0)
    { //Inicio
        cout << "Caso: Lista en el Inicio" << endl;
        Node *newNode = new Node();
        newNode->data = element;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        newNode->next = _head;
        _head = newNode;
        _size++;
        return true;
    }

    if (position > 0 && position == _size)
    { //Final
        cout << "Caso:Lista en el Final" << endl;
        Node *newNode = new Node();
        newNode->data = element;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        Node *temporal = _head;
        while (temporal->next != nullptr)
        {
            temporal = temporal->next;
        }
        temporal->next = newNode;
        newNode->next = nullptr;
        newNode->prev = temporal;
        _size++;
        return true;
    }

    if ((position > 0 && position < _size) && _size > 0)
    { //Medio
        cout << "Caso:Lista en el Medio" << endl;
        Node *newNode = new Node();
        newNode->data = element;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        Node *temporal = _head;
        for (size_t i = 0; i < position - 1; i++)
        {
            temporal = temporal->next;
        }
        temporal->next = newNode;
        newNode->prev = temporal;
        newNode->next = temporal->next;
        (temporal->next)->prev = newNode;
        _size++;
        return true;
    }
}
/*Elimina de la lista un nodo y reasigna las direcciones o enlaces de los otros nodos
Params: Recibimos como parametro la posicion que deseamos eliminar
Retorna: Verdadero si el nodo fue eliminado exitosamente, falso en caso contrario
Errores: Si la posicion es menor que 0 , o es mayor al tamano que tiene la lista retornara falso*/
bool DoubleLinkedList::Remove(size_t position)
{
    //cout << "ELIMINANDO....." << endl;
    if (position > _size)
    { //Validacion de posiciones
        return false;
    }

    /*General para los casos: Eliminamos el nodo y modificamos los enlaces,
     Casos:
      Remover  en Lista Vacia
      Remover en el inicio
      Remover en el final
      Remover en medio*/

    if (_size == 0)
    { //Vacia
        cout << "eliminando en lista Vacia" << endl;
        cout << "NO hay nada que eliminar" << endl;
        return false;
    }

    if (_size > 0 && position == 0)
    { //Inicio
        cout << "Eliminando en Inicio" << endl;
        Node *temporal = _head;
        _head = temporal->next;
        _head->prev = nullptr;
        delete temporal->data;
        delete temporal;
        _size--;
        return true;
    }

    if (position == _size - 1 && position > 0)
    { //Final
        cout << "Eliminando al final" << endl;
        Node *temporal = _head;
        while (temporal->next != nullptr || temporal->next != NULL)
        {
            temporal = temporal->next;
        }
        (temporal->prev)->next = nullptr;
        delete temporal->data;
        delete temporal;
        _size--;
        return true;
    }

    if ((position > 0 && position < _size) && _size > 0)
    { //En medio
        cout << "Elimanando en medio" << endl;
        size_t i = 0;
        Node *temporal = _head;
        while (i != position)
        {
            temporal = temporal->next;
            i++;
        }
        (temporal->next)->prev = temporal->prev;
        (temporal->prev)->next = temporal->next;
        delete temporal->data;
        delete temporal;
        _size--;
        return true;
    }
}
/*Recorremos la lista devolvemos el valor que se encuentre en la posicion que nos indican
Params: La posicion del nodo que deseamos mostrar o traer
Retorna: Verdadero si el nodo encontrado en la posicion dada, falso en caso contrario
Errores: Si la posicion es menor que 0 , o es mayor al tamano que tiene la lista retornara nullptr*/
Object *DoubleLinkedList::Get(size_t position) const
{
    //cout << "GET...." << endl;
    if (position >= _size)
    {
        return nullptr;
    }
    if (position == 0)
    { //Cabecera
        return _head->data;
    }
    if (position == 1)
    { //Primer Valor
        return (_head->next)->data;
    }

    if (position == (_size - 1))
    { //Final
        Node *temporal = _head;
        for (size_t i = 0; i < _size - 1; i++)
        { //cambie size a size-1
            temporal = temporal->next;
        }
        return temporal->data;
    }

    if (position < (_size - 1) && position > 1)
    { //En Medio De La Lista
        Node *temporal = _head;
        for (size_t i = 0; i < position; i++)
        {
            temporal = temporal->next;
        }
        return temporal->data;
    }
}
/*Recorremos la lista devolvemos el indice del valor que se nos provee
-Recorre la lista, y si encuentra coincidencia entonces devuelve la posicion en la que se encontro
Params: el valor del nodo que esta en la posicion que retornaremos
Retorna: la posicion del nodo si lo encontramos en la lista, -1 si no se encuentra contenido en la lista.
Errores: si el valor no se encuentra entonces rertornaremos -1*/
int DoubleLinkedList::IndexOf(const Object *rhs) const
{
    // cout << "INDEXOF...." << endl;
    for (size_t i = 0; i < _size; i++)
    {
        if (Get(i)->Equals(rhs))
        {
            return i;
        }
    }
    return -1;
}