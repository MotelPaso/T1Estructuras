#include <iostream>
#include <fstream>
#include <string>

#include "modules/List/LinkedList.h"
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

bool guardarMusica()
{
  fstream arch("../music_source.txt");
  if (!arch)
  {
    return false;
  }
  string linea;
  while (getline(arch, linea))
  {
    string datos[7];
    int i = 0;
    string actual = "";
    for (int j = 0; j < linea.size(); j++)
    {
      if (linea[j] == ',')
      {
        datos[i++] = actual; // primero lo agarra, despues lo suma
        actual = "";
      }
      else
      {
        actual += linea[j];
      }
    }
    datos[i] = actual;

    Cancion *c = new Cancion(stoi(datos[0]), datos[1], datos[2], datos[3], stoi(datos[4]), stoi(datos[5]), datos[6]);
    listadoCanciones->append(c);
  }
  arch.close();
  return true;
};

bool guardarOpciones()
{
  return true;
};

void mostrarCanciones()
{
  cout << listadoCanciones->mostrar() << endl;
}

void cleanUp()
{
  delete listaReproduccion;
  delete listadoCanciones;
};

int main()
{
  bool musicaCargada = guardarMusica();
  bool optionsCargadas = guardarOpciones();

  if (!(musicaCargada && optionsCargadas))
  {
    if (!musicaCargada)
    {
      cout << "Ha habido un problema cargando la musica...";
    }
    if (!optionsCargadas)
    {
      cout << "Ha habido un problema cargando la configuracion...";
    }
    return 0;
  }
  char opcion;
  do
  {
    // test
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
      mostrarCanciones();
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