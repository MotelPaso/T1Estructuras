#pragma once
template <typename T>
class Node
{
  T data;
  Node<T> *next;

public:
  Node() : next(nullptr) {};
  Node(T data) : data(data), next(nullptr) {};
  Node(T *data) : data(*data), next(nullptr) {};

  T *getData()
  {
    return &data;
  };
  Node<T> *getNext() { return next; }
  void setData(const T &data)
  {
    this->data = data;
  }
  void setNext(Node<T> *next)
  {
    this->next = next;
  }
  bool hasNext()
  {
    return this->next != nullptr;
  }
};