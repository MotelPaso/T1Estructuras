#include "Queue.h"

template <typename T>
void Queue<T>::push(T data)
{
  Node<T> *temp = new Node<T>(data);
  this->size++;
  if (this->isEmpty())
  {
    this->first = temp;
    this->last = temp;
    return;
  }
  last->next = temp;
  last = temp;
  return;
}
template <typename T>
void Queue<T>::pop()
{
  Node *temp = first->next;
  delete first;
  first = temp;
  return;
}
template <typename T>
T *Queue<T>::front()
{
  return this->front->getData();
}

template <typename T>
bool Queue<T>::isEmpty()
{
  return this->size == 0;
}

template <typename T>
int Queue<T>::lentejas()
{
  return this->size;
};
