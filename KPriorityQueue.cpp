//
// Created by hajda2 on 2021. 09. 25..
//
#include "KPriorityQueue.hpp"
#include "listexception.hpp"
#include <iostream>

template <class T>
KPriorityQueue<T>::KPriorityQueue(double k, unsigned short m_size):Queue<T>() { // kasszasor
  //TODO
    this->k = k;
    this->m_size = m_size;
    this->cur_size = 0;
}

template <class T>
KPriorityQueue<T>::~KPriorityQueue() { //házis cucc
  //TODO
    typename KPriorityQueue<T>::Node* i;
    typename KPriorityQueue<T>::Node* j;
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
void KPriorityQueue<T>::in(T new_item) { //új elem befűzés // globál csökkentés
  //TODO
  //new_item<new_item;
    typename KPriorityQueue<T>::Node* p = new typename KPriorityQueue<T>::Node(new_item);
    typename KPriorityQueue<T>::Node* p1 = this->head;
    typename KPriorityQueue<T>::Node* p2 = this->head;
    if(cur_size != max_size()){
        if(this->isEmpty()){
            KPriorityQueue<T>::head = KPriorityQueue<T>::tail = p;
            cur_size++;
        }else {
            int i = 0;

            while (p1) {
                    if (p1->value.priority * k > new_item.priority) {
                        i++;
                    }
                    p1 = p1->pNext;
            }
            p1 = nullptr;
            for (int j = 0; j < i; j++) { //insert i-ediknek
                p1 = p2;
                p2 = p2->pNext;
            }
            if(p1 == nullptr) {
                p->pNext = this->head;
                this->head = p;
                cur_size++;
            }else if(p2 == nullptr){
                this->tail->pNext = p;
                this->tail = p;
                cur_size++;
            }else{
                p1->pNext = p;
                p->pNext = p2;
                cur_size++;
            }


        }
    }
}

template <class T>
T KPriorityQueue<T>::out() { //vásárló végez
  //TODO
  //return T();
    //T oldvalue;
    typename KPriorityQueue<T>::Node * newhead;
    if(this->isEmpty()){
        throw UnderFlowException();
    }else{
        int firstproduct = this->head->value.all_product_num;
        T oldvalue = T(this->head->value);
        newhead = this->head->pNext;
        delete this->head;
        this->head = newhead;
        cur_size--;
        typename KPriorityQueue<T>::Node * cur = this->head;
        while(cur){
            if(cur->value.priority + firstproduct <1000) {
                cur->value.priority += firstproduct;
            }else{
                cur->value.priority = 1000;
            }
            cur = cur->pNext;
        }
        return oldvalue;
    }

    //return oldvalue;
}

template <class T>
void KPriorityQueue<T>::print() const {
  //TODO
}

template <class T>
unsigned short KPriorityQueue<T>::max_size() const {
  return m_size;

}

template <class T>
unsigned short KPriorityQueue<T>::current_size() const {
  return cur_size;
}

template <class T>
unsigned long KPriorityQueue<T>::time_to_finish(T value) const { //megkeresi hova érdemes beállni
  //TODO
  //value<value;
  //return 1;
  typename KPriorityQueue<T>::Node * cur =  this->head;
  unsigned long finish = 0;
  while(cur){
      if(value.priority < cur->value.priority * k){
          finish += cur->value.all_product_num;
      }

      cur = cur->pNext;
  }
  return finish;
}
template <class T>
void KPriorityQueue<T>::Step() const{
        this->head->value.current_product_num--;
}

/*template <class T>
bool KPriorityQueue<T>::isEmpty() const { // üres a kasszasor
    return (this->head == nullptr);
}*/

