
#include <iostream>
#include <fstream>
#include <string>

#include "../modules/List/LinkedList.h"
#include "Cancion.h"
using namespace std;

// global lists
LinkedList<Cancion> *listadoCanciones = new LinkedList<Cancion>();
LinkedList<Cancion> *listaReproduccion = new LinkedList<Cancion>();

void mostrarOpciones()
{
  cout << "Opciones:" << endl;
  cout << "W - Reproducir/Pausar" << endl;
  cout << "Q - Pista Anterior" << endl;
  cout << "E - Pista Siguiente" << endl;
  cout << "S - Activar/Desactivar modo aleatorio" << endl;
  cout << "R - Repetición (Desactivado/Repetir una/Repetir todas)" << endl;
  cout << "A - Ver lista de reproducción actual" << endl;
  cout << "L - Listado de canciones" << endl;
  cout << "X - Salir" << endl;
  cout << "Ingrese Opción: ";
};

void guardarMusica() {

};

void guardarOpciones() {

};

void cleanUp()
{
  delete listaReproduccion;
  delete listadoCanciones;
};

int main()
{
  guardarMusica();
  guardarOpciones();
  char opcion;
  do
  {
    mostrarOpciones();
    cin >> opcion;
    switch (opcion)
    {
    case 'W':
      // play
      break;
    case 'Q':
      // prev
      break;
    case 'E':
      // next
      break;
    case 'S':
      // toggle random mode!!!!!!!!!!!
      // how tf
      break;
    case 'R':
      // repeat
      break;
    case 'A':
      // show actual list of sex
      break;
    case 'L':
      // show full song list
      break;
    case 'X':
      cout << "Adios!" << endl;
      break;
    default:
      cout << "Opcion invalida..." << endl;
      break;
    }
  } while (opcion != 'X');

  cleanUp();
  return 0;
}