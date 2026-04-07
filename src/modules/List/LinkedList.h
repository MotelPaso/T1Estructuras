#pragma once
#include "../Node.h"

template <typename T>
class LinkedList
{
private:
  Node<T> *head;
  int size;

public:
  LinkedList<T>() : head(nullptr){};
  ~LinkedList();
  int length();
  void add(T data);
  void add(T *data);
};

#include "LinkedList.cpp"