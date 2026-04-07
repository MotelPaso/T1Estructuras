#include "LinkedList.h"
#include "../Node.h"

template <typename T>
LinkedList<T>::~LinkedList()
{
  while (head != nullptr)
  {
    Node<T> *temp = head;
    head = head->getNext();
    delete temp;
  };
};
template <typename T>
int LinkedList<T>::length()
{
  return this->size();
}
template <typename T>
void LinkedList<T>::add(T data)
{
}
template <typename T>
void LinkedList<T>::add(T *data) {
};