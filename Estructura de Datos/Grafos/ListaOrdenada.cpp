#include "ListaOrdenada.h"

//constructor

ListaOrdenada::ListaOrdenada() {
	inicio = NULL;
}
//destructor

ListaOrdenada::~ListaOrdenada() {
	pNodo aux;
	while (inicio != NULL) {
		aux = inicio;
		inicio = inicio->sig;
		delete aux;
	}
}


bool ListaOrdenada::estaVacia() {
	return (inicio == NULL);
}

bool buscar (pNodo nodo, int x) {
	bool resul = false;
	if (nodo != NULL) {
		if (nodo->clave == x)
			resul = true;
		else if (nodo->clave < x)
				 resul = buscar (nodo->sig, x);
	}
	return resul;
}
bool ListaOrdenada::busqueda (int x) {
	bool aux = buscar (inicio, x);
	return aux;
 }

void insercion (pNodo &nodo, int x) {
	if (nodo != NULL) {
		if (nodo->clave < x)
				 insercion (nodo->sig, x);
		else if (nodo->clave > x)
			nodo = new NodoLista (x, nodo);
	}
	else
		nodo = new NodoLista (x, NULL);
}
void ListaOrdenada::insertar (int x) {
	insercion (inicio, x);
 }
void eliminacion (pNodo &nodo, int x) {
	if (nodo != NULL) {
		if (nodo->clave == x)
			nodo = nodo->sig;
		else if (nodo->clave < x)
				 eliminacion (nodo->sig, x);
			else cout << "Error la clave no existe" << endl;
	}
	else cout << "Error la clave no existe" << endl;

}
void ListaOrdenada::eliminar (int x) {
	eliminacion (inicio, x);
 }
void ListaOrdenada::escribirLista() {
	pNodo aux;
	aux = inicio;
	while (aux != NULL) {
		cout << aux->clave << " ";
		aux = aux->sig;
	}
	cout << endl;
}
void ListaOrdenada::leerLista(){
	int cantidad, i, x;

	inicio = NULL;
	cout << "Numero de elementos de la lista: " << endl;
	cin >> cantidad;
	for (i = 0; i < cantidad; i++) {
		cin >> x;
		insertar(x);
	};
}
int ListaOrdenada::numElementos () {
	pNodo aux = inicio;
	int resul = 0;
	while (aux != NULL) {
		aux = aux->sig;
		resul++;
	}
	return resul;
}
