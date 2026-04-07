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
  LinkedList<T>(Node<T> *node)
  {
    this.head = node;
  }
  ~LinkedList();

  int length();
};

#include "LinkedList.cpp"
