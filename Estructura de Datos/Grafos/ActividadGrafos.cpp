#include <iostream>
#include "GrafoMA.h"
#include "GrafoLA.h"

using namespace std;

GrafoMA juegoEnsayo1 () {
	GrafoMA grafo(7, false);

	//Añadir n de vertices al grafo
	grafo.insertaVertices(7);

	//Insertar Arista
	grafo.insertaArista(0,1);
	grafo.insertaArista(1,4);
	grafo.insertaArista(4,5);

	grafo.insertaArista(0,2);
	grafo.insertaArista(2,6);

	grafo.insertaArista(0,3);
	return grafo;
}

GrafoLA grafoCompletoN (int n) {
	int i,j;
	GrafoLA resul (n, false);
	resul.insertaVertices(n);

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i!=j) resul.insertaArista(i,j);
	return resul;
}

int main () {
	cout << "------------" << endl;
	cout << "Apartado 1.1" << endl;
	cout << "------------" << endl;
	GrafoMA grafo = juegoEnsayo1 ();

	grafo.imprimirTabla ();
	cout << "----------------------- " << endl;
	cout << "Recorrido en amplitud: " << endl;
	grafo.recorrerAmplitud ();
	cout << "----------------------- " << endl;
	cout << "Recorrido en profundidad: " << endl;
	grafo.recorrerProfundidad ();
	cout << "----------------------- " << endl;

	cout << "------------" << endl;
	cout << "Apartado 1.2" << endl;
	cout << "------------" << endl;
	GrafoLA grafol = grafoCompletoN (7);

	grafol.imprimirListas ();

	cout << endl;

	cout << "------------" << endl;
	cout << "Apartado 2.1" << endl;
	cout << "------------" << endl;

	GrafoLA g = grafo.grafoEquivalente ();
	g.imprimirListas ();

	cout << "------------" << endl;
	cout << "Apartado 2.2" << endl;
	cout << "------------" << endl;

	grafo.conectarVertice (3);
	grafo.imprimirTabla ();

	cout << "------------" << endl;
	cout << "Apartado 2.3" << endl;
	cout << "------------" << endl;

	g.conectarVertice (5);
	g.imprimirListas ();
	return 0;
}
