#pragma once
#include "../Node.h"

template <typename T>
class LinkedList
{
private:
  Node<T> *head;
  int size = 0;

public:
  LinkedList<T>() : head(nullptr){};
  ~LinkedList();
  int length();
  void append(const T &data);
  void append(T *data);
  T get(int index);
  bool empty();
};

#include "LinkedList.cpp"