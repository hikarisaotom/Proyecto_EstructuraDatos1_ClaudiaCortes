// Titulo: Proyecto #1
//Implementacion del TDA Lista usando Listas Doblemente Enlazadas
//
// Proposito: crear un API que contiene todas las operaciones de lista usando listas
//enlazadas
//
// Clase: CCC209 – Q3 – 2018
//
// Author: Claudia Patricia Cortes Pavon 

#pragma once
#include "object.h"
#include "list.h"
#include <string>
using std::string;

class DoubleLinkedList : public List{
private:
    struct Node {
        Object* data;
        Node* next;
        Node* prev;
    };
    Node* _head;
    DoubleLinkedList(const DoubleLinkedList&);
    const DoubleLinkedList& operator=(const DoubleLinkedList&)const;
public:
    DoubleLinkedList();
    virtual ~DoubleLinkedList();
    virtual bool Equals(const Object*)const;
    virtual bool Insert(Object*, size_t);
    virtual bool Remove(size_t);
    virtual Object* Get(size_t)const;
    virtual int IndexOf(const Object*)const;   
};
