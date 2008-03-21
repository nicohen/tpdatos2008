/******************************************************************************
 *                   Algoritmos y Programación II - 75.41                     *
 *                        Cátedra Ing. Mandrafina                             *
 *            Facultad de Ingeniería - Universidad de Buenos Aires            *
 ******************************************************************************/ 

/* TDA ArchivoRegistros
 * Implementación con fstream.
 * Archivo : archivoRegistros.cpp
 * Versión : 1.2
 */

/******************************************************************************/
/* Headers */
/*---------*/

#include "archivoRegistros.h"


using namespace std;

/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/

void crear(ArchivoRegistros &archivoRegistros, string nombre, 
           int tamanioRegistro) {

  /* abre el archivo en modo lectura - escritura binario*/  
  archivoRegistros.archivo.open(nombre.c_str(),
                                ios::in |ios::out |ios::binary);
                                         
  /* determina si tuvo éxito la apertura del archivo */
  if (! archivoRegistros.archivo.is_open()) {

    /* limpia los flags de control de estado del archivo */
    archivoRegistros.archivo.clear();
  
    /* crea el archivo */    
    archivoRegistros.archivo.open(nombre.c_str(),
                                  ios::out | ios::binary);      
    archivoRegistros.archivo.close();
    
    /* reabre el archivo para lectura - escritura binario */
    archivoRegistros.archivo.open(nombre.c_str(),
                                  ios::in|ios::out|ios::binary);

    /* verifica que haya podido crear el archivo */                                  
    if (! archivoRegistros.archivo.is_open())
    
      /* arroja una excepción */
      throw string("El archivo no pudo ser abierto");   
  }

  /* almacena el tamaño de los registros */
  archivoRegistros.tamanioRegistro = tamanioRegistro;         
}

/*----------------------------------------------------------------------------*/
void destruir(ArchivoRegistros &archivoRegistros) {

  /* cierra el archivo */
  archivoRegistros.archivo.close();
  archivoRegistros.tamanioRegistro = 0;
}

/*----------------------------------------------------------------------------*/
void escribir(ArchivoRegistros& archivoRegistros, const void* registro) {

  /* verifica que el archivo esté abierto */
  if (archivoRegistros.archivo.is_open()) {

    /* escribe el registro en el archivo */
    archivoRegistros.archivo.write(static_cast<const char*>(registro),
                                   archivoRegistros.tamanioRegistro);

    /* chequea si se ha producido un error */
    if (archivoRegistros.archivo.fail())
      /* arroja una excepción ante la imposibilidad de escribir el reg */
      throw string("No se pudo escribir correctamente el registro");
  }
  else {
    /* arroja una excepción porque el archivo no está abierto */
    throw string("El archivo no está abierto");
  }
}

/*----------------------------------------------------------------------------*/
void leer(ArchivoRegistros& archivoRegistros, void* registro) {

  /* verifica que el archivo esté abierto */
  if (archivoRegistros.archivo.is_open()) {

    /* lee del archivo un registro */
    archivoRegistros.archivo.read(static_cast<char*>(registro),
                                  archivoRegistros.tamanioRegistro);

    /* chequea si se ha producido un error */
    if (archivoRegistros.archivo.fail())
      /* arroja una excepción ante la imposibilidad de leer un reg */
      throw string("No se pudo leer correctamente el registro");
  }
  else {
    /* arroja una excepción porque el archivo no está abierto */
    throw string("El archivo no está abierto");
  }
}

/*----------------------------------------------------------------------------*/
bool fin(ArchivoRegistros& archivoRegistros) {

  /* para comprobar el fin lee un char del buffer, sin retirarlo y lo
     compara con el fin de archivo */
  bool esEof = (archivoRegistros.archivo.peek() == char_traits<char>::eof());

  if (esEof)
    /* si llegó al fin del archivo limpia los flags */
    archivoRegistros.archivo.clear();

  return esEof;
}

/*----------------------------------------------------------------------------*/
long int posicion(ArchivoRegistros& archivoRegistros) {

  long int pos = 0;

  /* verifica que el archivo esté abierto */
  if (archivoRegistros.archivo.is_open())

    /* calcula el número de registro según la posición del byte actual */
    pos = archivoRegistros.archivo.tellg() / archivoRegistros.tamanioRegistro;

  else
    /* arroja una excepción porque el archivo no está abierto */
    throw string("El archivo no está abierto");

  return pos;
}

/*----------------------------------------------------------------------------*/
void posicionarse(ArchivoRegistros& archivoRegistros, long int posicion) {

  /* verifica que el archivo esté abierto */
  if (archivoRegistros.archivo.is_open()) {

    /* mueve la posición actual según sea el tamano del registro */
    archivoRegistros.archivo.seekg(posicion * archivoRegistros.tamanioRegistro,
                                   ios_base::beg);

    /* chequea si se ha producido un error */
    if (archivoRegistros.archivo.fail())
      /* arroja una excepción ante la imposibilidad de leer un reg */
      throw string("No se pudo posicionar correctamente el registro");
  }
  else
    /* arroja una excepción porque el archivo no está abierto */
    throw string("El archivo no está abierto");
}
/*----------------------------------------------------------------------------*/

