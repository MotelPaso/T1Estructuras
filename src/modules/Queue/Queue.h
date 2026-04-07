

#include "../Node.h"

template <typename T>
class Queue
{
private:
  Node<T> *first;
  Node<T> *last;
  int size;

public:
  Queue() : first(nullptr), last(nullptr) {};
  ~Queue() {};

  void push();
  T front();
  void pop();
};