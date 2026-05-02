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
  return;
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
