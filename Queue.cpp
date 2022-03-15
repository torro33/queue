//
// Created by hajda2 on 2021. 09. 30..
//
#include "Queue.hpp"
#include "listexception.hpp"
#include <iostream>

template <class T>
Queue<T>::Queue() { //globális sor
  //TODO
  head = nullptr;
  tail = nullptr;
}

template <class T>
Queue<T>::~Queue() {
  //TODO
    typename Queue<T>::Node* i;
    typename Queue<T>::Node* j;
    i = this->head;
    while(i != nullptr){
        j = i;
        i = i->pNext;
        j->pNext = nullptr;
        delete j;
    }
    this->head = nullptr;
    this->tail = nullptr;
}

template <class T>
void Queue<T>::in(T new_item) {
  //TODO
  //new_item<new_item;
    Node* p = new Node(new_item);
    if(isEmpty()){
        head = tail = p;
    }else{
        tail->pNext = p;
        tail = p;
    }
}

template <class T>
T Queue<T>::out() {
  //TODO
  //return T();
    //T oldvalue;
    Node * newhead;


    if(isEmpty()){
        throw UnderFlowException();
    }else{
        //oldvalue = head->value;
        T oldvalue = T(head->value);
        newhead = head->pNext;
        delete head;
        head = newhead;
        return oldvalue;
    }
    //return oldvalue;
}

template <class T>
T& Queue<T>::first() const { // első ember értékét visszaadja
  //TODO
    return head->value;
}

template <class T>
bool Queue<T>::isEmpty() const { // üres a kasszasor
  //TODO
    return (head == nullptr);
}

template <class T>
void Queue<T>::print() const {
  //TODO
}