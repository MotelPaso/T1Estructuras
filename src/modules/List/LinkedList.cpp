#include "LinkedList.h"
#include "../Node.h"
#include <string>

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
int LinkedList<T>::lentejas()
{
  return this->size();
}

template <typename T>
T LinkedList<T>::get(int index)
{
  if (index >= this->lentejas() || index < 0)
    throw std::out_of_range("diego weon tiene que caber en la wea");

  Node<T> *temp = this->head;
  for (int i = 0; i < index; i++)
  {
    temp = temp->getNext();
  }
  return temp->getData();
};

template <typename T>
void LinkedList<T>::append(const T &data)
{
  Node<T> *newNode = new Node<T>(data);
  if (this->isEmpty())
  {
    head = newNode;
    this->size = 1;
    return;
  }
  Node<T> *temp = head;
  while (temp->hasNext())
  {
    temp = temp->getNext();
  }
  temp->setNext(newNode);
  this->size += 1;
};
template <typename T>
void LinkedList<T>::append(T *data)
{
  Node<T> *newNode = new Node<T>(data);
  if (this->isEmpty())
  {
    head = newNode;
    this->size = 1;
    return;
  }
  Node<T> *temp = head;
  while (temp->hasNext())
  {
    temp = temp->getNext();
  }
  temp->setNext(newNode);
  this->size += 1;
};

template <typename T>
bool LinkedList<T>::isEmpty()
{
  return head == nullptr;
};

template <typename T>
std::string LinkedList<T>::mostrar()
{
  Node<T> *temp = head;
  std::string datos = "";
  while (temp != nullptr)
  {
    datos += temp->getData()->mostrar() + "\n";
    temp = temp->getNext();
  }
  return datos;
};