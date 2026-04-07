#pragma once
template <typename T>
class Node
{
  T data;
  Node<T> *next;

public:
  Node() : next(nullptr) {};

  Node(T data)
  {
    this.data = data;
    this.next = nullptr;
  };

  const T *getData() { return &data; };
  Node *getNext() { return next; }
  void setData(const T &data)
  {
    this.data = data;
  }
  void setNext(Node *next)
  {
    this.next = next;
  }
};