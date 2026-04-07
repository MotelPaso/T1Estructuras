#include "LinkedList.h"
#include "../Node.h"

template <typename T>
LinkedList<T>::~LinkedList()
{
  while (head != nullptr)
  {
    Node<T> *temp = head;
    head = head->next;
    delete temp;
  };
};
template <typename T>
int LinkedList<T>::length()
{
  return this->size();
};