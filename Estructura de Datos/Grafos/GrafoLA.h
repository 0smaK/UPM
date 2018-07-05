/*
 * GrafoLA.h
 *
 *  Created on: 6/1/2015
 *      Author: carolinagallardo
 */

#ifndef GRAFOLA_H_
#define GRAFOLA_H_

#include "ListaOrdenada.h"

using namespace std;

class GrafoLA {

private:
	bool dirigido;
	int numVertices;
	int maxNodos;
	ListaOrdenada *listaAdyP;
	void profundidadAux (int v, bool visitados []);

public:
	GrafoLA ();
	GrafoLA (int maximo, bool dir);
	~GrafoLA ();
	bool getDirigido ();
	void setDirigido (bool dirigido);
	int getMaxNodos () const;
	int getNumVertices ();

	void insertaVertices (int n);
	void insertaArista (int i, int j);
	void eliminarArista (int i, int j);
	bool esVacio ();
	bool existeArista (int i, int j);
	/** Devuelve true si existe una arista que una los vertices i y j. **/
	int gradoIn (int i);
	/** Devuelve el grado de entrada del vertice i **/
	int gradoOut (int i);
	/** Devuelve el grado de salida del verticee i **/
	int incidencia (int i);
	/** Devuelve la incidencia del vertice i **/
	int tamano ();
	/** Devuelve el tamaño (nuero de aristas) del grafo **/
	void imprimirListas ();
	void recorrerProfundidad ();
	void recorrerAmplitud ();

	void conectarVertice (int v);
};

#endif /* GRAFOLA_H_ */
