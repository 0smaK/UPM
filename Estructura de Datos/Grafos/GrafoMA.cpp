#include "GrafoMA.h"
#include <iostream>
#include <queue>
using namespace std;

GrafoMA::GrafoMA (int n, bool dir) {
	numVertices = 0;
	dirigido = dir;
	maxNodos = n;
	matrizAdyP = new bool* [maxNodos]; //reservo espacio para el vector de filas
	for (int i = 0; i < maxNodos; i++)
		matrizAdyP [i] = new bool [maxNodos]; //reservo espacio para cada fila
}
GrafoMA::~GrafoMA () {
	 for (int i=0; i < maxNodos; i++)
			delete  matrizAdyP[i];
	 delete  matrizAdyP;
}

bool GrafoMA::getDirigido () {
	return dirigido;
}

void GrafoMA::setDirigido (bool dirigido) {
	this->dirigido = dirigido;
}

int GrafoMA::getMaxNodos () const {
	return maxNodos;
}

int GrafoMA::getNumVertices () {
	return numVertices;
}

void GrafoMA::insertaVertices (int n) {
	if (n > maxNodos - numVertices)
		cout << "Error, se supera el numero de nodos maximo" << endl;
	else {
		for (int i = 0; i < numVertices + n; i++) {
			for (int j = numVertices; j < numVertices + n; j++)
				matrizAdyP [i] [j] = matrizAdyP [j] [i] = false;
		}
		numVertices = numVertices + n;
	}
}

void GrafoMA::insertaArista (int i, int j) {
	if ((i < numVertices) && (j < numVertices)) {
		matrizAdyP [i] [j] = true;
		if (!dirigido)
			matrizAdyP [j] [i] = true;
	}
	else cout << "Error, fuera de rango" << endl;
}

void GrafoMA::eliminarArista (int i, int j) {
	if ((i < numVertices) && (j < numVertices)) {
		matrizAdyP [i] [j] = false;
		if (!dirigido)
			matrizAdyP [j] [i] = false;
	}
	else cout << "Error, fuera de rango" << endl;
}

bool GrafoMA::esVacio () {
	return numVertices == 0;
}

bool GrafoMA::existeArista (int i, int j) {
	if ((i < numVertices) && (j < numVertices))
		return matrizAdyP [i] [j];
	else return false;
}

int GrafoMA::gradoIn (int j) {
	int gIn = 0;
	if (j < numVertices) {
		for (int i = 0; i < numVertices; i++) //recorrido por filas
			if (matrizAdyP [i] [j])
				gIn++; //manteniendo la posición de la columna en [j]
	}
	else cout << "Error, fuera de rango" << endl;
	return gIn;
}

int GrafoMA::gradoOut (int i) {
	int gOut = 0;
	if (i < numVertices) {
		for (int j = 0; j < numVertices; j++)
			if (matrizAdyP [i] [j])
				gOut++; // manteniendo la posición de la fila en [i]
	}
	else cout << "Error, fuera de rango" << endl;
	return gOut;
}

int GrafoMA::incidencia (int i) {
	int resul = 0;
	if (i < numVertices) {
		if (!dirigido)
			resul = gradoIn (i);
		else resul = gradoIn (i) + gradoOut (i);
	}
	return resul;
}

int GrafoMA::tamano () {
	int tm = 0, resul;
	for (int i = 0; i < numVertices; i++)
		for (int j = 0; j < numVertices; j++) {
			if (matrizAdyP [i] [j]) {
				tm++;
				if (!dirigido && i == j)
					tm++;
			}
		}
	if (dirigido)
		resul = tm;
	else resul = tm / 2;
	return resul;
}

void GrafoMA::imprimirTabla () {
	cout << "La matriz contiene " << numVertices << " vertices" << endl;
	cout << "Tamanio maximo: " << maxNodos << " vertices" << endl;
	if (dirigido)
		cout << "Es dirigido" << endl;
	else cout << "No es dirigido" << endl;
	for (int i = 0; i < numVertices; i++) {
		for (int j = 0; j < numVertices; j++) {
			if (matrizAdyP [i] [j])
				cout << "1 ";
			else cout << "0 ";
		}
		cout << endl;
	}
}

void GrafoMA::profundidadAux (int v, bool visitados []) {
	visitados [v] = true;
	cout << v << " "; //el tratamiento del vertice consiste unicamente en imprimirlo en pantalla
	for (int i = 0; i < numVertices; i++) { //se examinan los vertices adyacentes a v para continuar el recorrido
		if ((v != i) && (!visitados [i]) && (existeArista (v, i)))
			profundidadAux (i, visitados);
	}
}

void GrafoMA::recorrerProfundidad () {
	bool visitados [numVertices];
	for (int i = 0; i < numVertices; i++)
		visitados [i] = false;

	for (int i = 0; i < numVertices; i++) {
		if (!visitados [i])
			profundidadAux (i, visitados);
	}
	cout << endl;
}

void GrafoMA::recorrerAmplitud () {
	queue<int> c;
	bool visitados [numVertices];
	for (int i = 0; i < numVertices; i++)
		visitados [i] = false;
	int v;

	for (int i = 0; i < numVertices; i++) {
		if (!visitados [i]) {
			visitados [i] = true;
			c.push (i);
			while (!c.empty ()) {
				v = c.front ();
				c.pop ();
				cout << v << " ";
				//encolar nodos adyacentes a v
				for (int j = 0; j < numVertices; j++) { // encolamos los hijos de v no visitados
					if (existeArista (v, j) && (v != j) && (!visitados [j])) {
						c.push (j);
						visitados [j] = true;
					}
				}
			}
		}
	}
	cout << endl;
}

GrafoLA GrafoMA::grafoEquivalente () {
	int n = numVertices;
	GrafoLA resul(n,dirigido);
	int i,j;

	resul.insertaVertices(n);
	for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(existeArista(i,j))resul.insertaArista(i,j);
	return resul;
}
void GrafoMA::conectarVertice (int v) {
	int i,n=numVertices;
	if(v<n){
		for(i=0;i<n;i++)
			if(!existeArista(v,i))
				matrizAdyP [v] [i] = true;
	if(!dirigido)
		for(i=0;i<n;i++) if(!existeArista(i,v))
			matrizAdyP [i] [v] =true;
	}

	else
		cout<< v <<"no existe en el grafo"<<endl;
}
