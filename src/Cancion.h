#include <string>

using namespace std;
class Cancion
{
private:
  int id;
  string titulo;
  string autor;
  string album;
  int year;
  int duracion;
  string filePath;

public:
  Cancion(int id, string titulo, string autor, string album, int year, int duracion, string filePath)
  {
    this->id = id;
    this->titulo = titulo;
    this->autor = autor;
    this->album = album;
    this->year = year;
    this->duracion = duracion;
    this->filePath = filePath;
  };
  ~Cancion() {};
  string mostrar() const
  {
    return "" + this->titulo;
  };
};