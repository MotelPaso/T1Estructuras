#include "ListaReproduccion.h"
#include "../Cancion/Cancion.h"

ListaReproduccion::~ListaReproduccion()
{
  while (head != nullptr)
  {
    DNodo *temp = head;
    head = head->next;
    delete temp;
  }
}
std::string ListaReproduccion::mostrarListaActual()
{
  if (this->actual == nullptr)
  {
    return "Vacía\n";
  }

  std::string datos = "";
  DNodo *temp = this->actual->next;
  int contador = 1;

  if (temp == nullptr)
  {
    return "Vacía\n";
  }

  while (temp != nullptr)
  {
    datos += std::to_string(contador) + ". ";
    datos += temp->cancion->mostrar() + "\n";
    temp = temp->next;
    contador++;
  }

  return datos;
}

void ListaReproduccion::saltarA(int posicion)
{
  if (posicion <= 0 || this->actual == nullptr)
  {
    return;
  }

  DNodo *temp = this->actual->next;
  int contador = 1;

  while (temp != nullptr && contador < posicion)
  {
    temp = temp->next;
    contador++;
  }

  if (temp != nullptr)
  {
    this->actual = temp;
  }
}

void ListaReproduccion::append(Cancion *c)
{
  DNodo *n = new DNodo(c);
  this->size++;
  if (this->head == nullptr)
  {
    this->head = n;
    this->actual = n;
    this->end = n;
    return;
  }
  end->next = n;
  n->prev = end;
  end = n;
  return;
};

void ListaReproduccion::remove()
{
  if (this->size == 0)
  {
    return;
  }
  else if (this->size == 1)
  {
    delete end;
    end = nullptr;
    head = end;
    actual = end;
    this->size--;
    return;
  }
  DNodo *temp = end->prev;
  temp->next = nullptr;
  delete end;
  end = temp;
  return;
};

void ListaReproduccion::activarAleatorio()
{
  this->aleatorio = !this->aleatorio; //puede que ayude

  
};
std::string ListaReproduccion::repetir(std::string r)
{
  if (r == "R0" || r == "R1" || r == "RA")
  {
    this->tipoRepeticion = r;
    return this->tipoRepeticion;
  }
  else
  {
    return "Tipo invalido...";
  }
};

std::string ListaReproduccion::getEstadoActual()
{
  if (this->size == 0)
  {
    return "Reproducción Detenida";
  }
  string datos = "";
  if (reproduciendo)
  {
    datos += "Reproduciendo ";
  }
  else
  {
    datos += "En pausa ";
  }
  if (aleatorio)
  {
    datos += "(S";
  }
  datos += tipoRepeticion != "R0" ? "-" + tipoRepeticion + ")" : ":";

  datos += " " + this->actual->cancion->mostrarEstado();
  return datos;
}

void ListaReproduccion::togglePlayStop()
{
  this->reproduciendo = !this->reproduciendo;
}
void ListaReproduccion::avanzar()
{
  if (this->actual == nullptr || this->actual->next == nullptr)
  {
    return;
  }
  actual = actual->next;
  return;
}
void ListaReproduccion::retroceder()
{
  if (this->actual == nullptr || this->actual->prev == nullptr)
  {
    return;
  }
  actual = actual->prev;
  return;
}
void ListaReproduccion::clear()
{
  while (head != nullptr)
  {
    DNodo *temp = head;
    head = head->next;
    delete temp;
  }

  head = nullptr;
  actual = nullptr;
  end = nullptr;
  size = 0;
}
int ListaReproduccion::lentejas()
{
  return this->size;
}