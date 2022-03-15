//
// Created by hajda2 on 2021. 09. 25..
//
#ifndef HF1_KPRIORITYQUEUE_HPP
#define HF1_KPRIORITYQUEUE_HPP

#include "Queue.hpp"

template <class T>
class KPriorityQueue : public Queue<T> {

  double k;
  unsigned short m_size;
  unsigned short cur_size;

public:
  KPriorityQueue(double k, unsigned short m_size);
  ~KPriorityQueue();
  void in(T new_item);
  T out();
  void Step() const;
  void print() const;
  unsigned short max_size() const;
  unsigned short current_size() const;
  unsigned long time_to_finish(T value) const;
private:
    //bool isEmpty() const;

};

#endif //HF1_KPRIORITYQUEUE_HPP
