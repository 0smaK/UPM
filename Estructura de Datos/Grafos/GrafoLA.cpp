#include "GrafoLA.h"
#include "ListaOrdenada.h"
#include <queue>

using namespace std;

GrafoLA::GrafoLA () {
	numVertices = 0;
	dirigido = false;
	maxNodos = 10;
	listaAdyP = new ListaOrdenada [maxNodos];
}

GrafoLA::GrafoLA (int maximo, bool dir) {
	numVertices = 0;
	dirigido = dir;
	maxNodos = maximo;
	listaAdyP = new ListaOrdenada [maxNodos];
}

GrafoLA::~GrafoLA () {
	for (int i = 0; i < numVertices; i++)
		listaAdyP [i].~ListaOrdenada ();
}

bool GrafoLA::getDirigido () {
	return dirigido;
}

void GrafoLA::setDirigido (bool dirigido) {
	this->dirigido = dirigido;
}

int GrafoLA::getMaxNodos () const {
	return maxNodos;
}

int GrafoLA::getNumVertices () {
	return numVertices;
}

void GrafoLA::insertaVertices (int n) {
	if (n > maxNodos - numVertices)
		cout << "Error, se supera el numero de nodos maximo del grafo" << endl;
	else {
		for (int i = numVertices; i < numVertices + n; i++)
			listaAdyP [i] = ListaOrdenada ();
		numVertices += n;
	}
}

void GrafoLA::insertaArista (int i, int j) {
	if ((i >= numVertices) || (j >= numVertices))
		cout << "Error, no existe el vertice en el grafo" << endl;
	else {
		listaAdyP [i].insertar (j);
		if (!dirigido)
			listaAdyP [j].insertar (i);
	}
}

void GrafoLA::eliminarArista (int i, int j) {
	if ((i >= numVertices) || (j >= numVertices))
		cout << "Error, no existe el vertice en el grafo" << endl;
	else {
		listaAdyP [i].eliminar (j);
		if (!dirigido)
			listaAdyP [j].eliminar (i);
	}
}

bool GrafoLA::esVacio () {
	return numVertices == 0;
}

bool GrafoLA::existeArista (int i, int j) {
	if ((i < numVertices) && (j < numVertices))
		return listaAdyP [i].busqueda (j);
	else return false;
}

int GrafoLA::gradoIn (int v) {
	int gIn = 0;
	if (v < numVertices) {
		for (int i = 0; i < numVertices; i++)
			if (listaAdyP [i].busqueda (v))
				gIn++;
	}
	return gIn;
}

int GrafoLA::gradoOut (int i) {
	int gOut = 0;
	if (i < numVertices) {
		gOut = listaAdyP [i].numElementos ();
	}
	return gOut;
}

int GrafoLA::incidencia (int i) {
	int resul = 0;
	if (i < numVertices) {
		if (!dirigido)
			resul = gradoIn (i);
		else resul = gradoIn (i) + gradoOut (i);
	}
	return resul;
}

int GrafoLA::tamano () {
	int tm = 0;
	for (int i = 0; i < numVertices; i++) {
		tm += gradoOut (i);
		if (!dirigido && listaAdyP [i].busqueda (i))
			tm++;
	}
	if (!dirigido)
		tm = tm / 2;
	return tm;
}

void GrafoLA::imprimirListas () {
	cout << "El grafo contiene " << numVertices << " vertices.";
//	cout << "Tamanio maximo: " << maxNodos << " vertices" << endl;
	if (dirigido)
		cout << " Es dirigido" << endl;
	else cout << " No es dirigido" << endl;

	for (int i = 0; i < numVertices; i++) {
		cout << "Lista " << i << ": ";
		listaAdyP [i].escribirLista ();
	}
}

void GrafoLA::profundidadAux (int v, bool visitados []) {
	visitados [v] = true;
	cout << v << " "; //el tratamiento del vertice consiste unicamente en imprimirlo en pantalla
	for (int i = 0; i < numVertices; i++) { //se examinan los vertices adyacentes a v para continuar el recorrido
		if ((v != i) && (!visitados [i]) && (existeArista (v, i)))
			profundidadAux (i, visitados);
	}
}

void GrafoLA::recorrerProfundidad () {
	bool visitados [numVertices];
	for (int i = 0; i < numVertices; i++)
		visitados [i] = false;

	for (int i = 0; i < numVertices; i++) {
		if (!visitados [i])
			profundidadAux (i, visitados);
	}
	cout << endl;
}

void GrafoLA::recorrerAmplitud () {
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

void GrafoLA::conectarVertice (int v) {
	int i,n=numVertices;
	if(v<n){
		for(i=0;i<n;i++)
			if(!existeArista(v,i))
				listaAdyP [v].insertar(i);
	if(!dirigido)
		for(i=0;i<n;i++) if(!existeArista(i,v))
			listaAdyP [i].insertar(v);
	}

	else
		cout<< v <<"no existe en el grafo"<<endl;
}
