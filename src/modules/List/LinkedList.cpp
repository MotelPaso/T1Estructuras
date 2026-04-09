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
T LinkedList<T>::get(int index)
{
  if (this->size <= index || index < 0)
    return; // error

  Node<T> *temp = this->head;
  for (int i = 0; i < index; i++)
  {
    temp = temp->getNext();
  }
  return temp->getData();
}

template <typename T>
void LinkedList<T>::append(const T &data)
{
  Node<T> *newNode = new Node<T>();
  newNode->setData(data);
  if (this->empty())
  {
    head = newNode;
    this->size++;
    return;
  }
  else
  {
    Node<T> *temp = head;
    while (temp->hasNext())
    {
      temp = temp->getNext();
    }
    temp->setNext(newNode);
    this->size += 1;
  }
}
template <typename T>
bool LinkedList<T>::empty()
{
  return head == nullptr;
};