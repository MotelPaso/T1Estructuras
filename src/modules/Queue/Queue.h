#pragma once
#include "../Node.h"

template <typename T>
class Queue
{
  // lifo
private:
  Node<T> *first;
  Node<T> *last;
  int size;

public:
    Queue() : first(nullptr), last(nullptr), size(0) {};  
    ~Queue() {};

  void push(T data);
  T *front();
  void pop();
  bool isEmpty();
  int lentejas();
};

#include "Queue.cpp"
