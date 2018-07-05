#ifndef NODOLISTA_H_
#define NODOLISTA_H_

class NodoLista {
public:
	int clave;
	NodoLista *sig;

	NodoLista (int elemento, NodoLista *n) {
		clave = elemento;
		sig = n;
	}
};
#endif /* NODOLISTA_H_ */

#ifndef LISTAORDENADA_H_
#define LISTAORDENADA_H_

#include <iostream>
using namespace std;

typedef NodoLista *pNodo;

class ListaOrdenada {
	//Variables miembro
private:
	pNodo inicio;
	// Interfaz/Prototipo
public:
	ListaOrdenada ();
	~ListaOrdenada ();

	bool estaVacia ();
	bool busqueda (int x);
	void insertar (int x);
	void eliminar (int x);
	void escribirLista ();
	void leerLista ();
	int numElementos ();
};

#endif /* LISTAORDENADA_H_ */
