#ifndef GRAFOMA_H_
#define GRAFOMA_H_
#include "GrafoLA.h"

class GrafoMA {
private:
	bool dirigido;
	int numVertices;
	int maxNodos;
	bool **matrizAdyP;
	void profundidadAux (int v, bool visitados []);

public:
	GrafoMA (int n, bool dir);
	~GrafoMA ();
	bool getDirigido ();
	void setDirigido (bool dirigido);
	int getMaxNodos () const;
	int getNumVertices ();

	void insertaVertices (int n);
	void eliminarVertice (int v);
	void insertaArista (int i, int j);
	void eliminarArista (int i, int j);
	bool esVacio ();
	bool existeArista (int i, int j);
	int gradoIn (int i);
	int gradoOut (int i);
	int incidencia (int i);
	int tamano ();
	void imprimirTabla ();
	void recorrerProfundidad ();
	void recorrerAmplitud ();

	GrafoLA grafoEquivalente ();
	void conectarVertice (int v);
};

#endif /* GRAFOMA_H_ */
