#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "modules/List/LinkedList.h"
#include "modules/Cancion/Cancion.h"
#include "modules/ListaReproduccion/ListaReproduccion.h"
using namespace std;

// global lists
LinkedList<Cancion> *listadoCanciones = new LinkedList<Cancion>();
ListaReproduccion *listaReproduccion = new ListaReproduccion();

void limpiarPantalla()
{
#ifdef _WIN32
  system("cls"); // si es windows se usa este comando
#else
  system("clear"); // si es linux, este comando.
#endif
}

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

bool cargarMusica()
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

bool cargarOpciones()
{
  return true;
}

void mostrarCanciones()
{
  cout << endl;
  cout << "Canciones registradas:" << endl;

  if (listadoCanciones->isEmpty())
  {
    cout << "No hay canciones registradas." << endl;
    return;
  }

  cout << listadoCanciones->mostrar() << endl;
}
void menuCanciones()
{
  string opcionL;

  do
  {
    mostrarCanciones();

    cout << "Opciones:" << endl;
    cout << "R<num> - Reproducir cancion seleccionada" << endl;
    cout << "A<num> - Agregar cancion al final de la lista" << endl;
    cout << "N - Agregar cancion al registro" << endl;
    cout << "D<num> - Eliminar cancion seleccionada" << endl;
    cout << "V - Volver al menu principal" << endl;
    cout << "Ingrese opcion: ";

    cin >> opcionL;

    if (opcionL == "V" || opcionL == "v")
    {
      return;
    }
    else if (opcionL[0] == 'R' || opcionL[0] == 'r')
    {
      if (opcionL.length() > 1)
      {
        int num = stoi(opcionL.substr(1));

        if (num >= 1 && num <= listadoCanciones->lentejas())
        {
          Cancion *c = listadoCanciones->get(num - 1);
          listaReproduccion->append(c);
          cout << c->mostrar() + " Agregada." << endl;
        }
        else
        {

          cout << "Numero invalido." << endl;
        }
      }
      else
      {
        cout << "Debes ingresar un numero." << endl;
      }
    }
    else
    {
      cout << "Opcion no valida o aun no implementada." << endl;
    }

  } while (true);
}

void cleanUp()
{
  delete listaReproduccion;
  delete listadoCanciones;
};

int main()
{
  bool musicaCargada = cargarMusica();
  bool optionsCargadas = cargarOpciones();
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
    limpiarPantalla();
    cout << listaReproduccion->getEstadoActual() << endl;
    mostrarOpciones();
    cin >> opcion;
    switch (opcion)
    {
    case 'W':
      listaReproduccion->togglePlayStop();
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
      menuCanciones();
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