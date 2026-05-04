#pragma once
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
  bool sonando = false;

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
  int getId() const { return id; }
  string getTitulo() const { return titulo; }
  string getAutor() const { return autor; }
  string getAlbum() const { return album; }
  int getYear() const { return year; }
  int getDuracion() const { return duracion; }
  string getFilePath() const { return filePath; }

  ~Cancion() {};
  string mostrar() const
  {
    return titulo + " - " + autor;
  }
  string mostrarEstado()
  {
    return titulo + "\nArtista: " + autor + "\nAlbum: " + album + "\n";
  }
};