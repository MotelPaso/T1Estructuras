

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
  Queue() : first(nullptr), last(nullptr) {};
  ~Queue() {};

  void push(T data);
  T *front();
  void pop();
  bool isEmpty();
  int lentejas();
};