//Clase NodoArbol; almacena un nodo de un �rbol.

public class NodoArbol {
	// Constructor vacío
	private char clave;
	private NodoArbol iz;
	private NodoArbol de;

	// Constructor con clave
	public NodoArbol (char clave) {
		this.clave = clave;
		iz = null;
		de = null;
	}

	public NodoArbol(char clave, NodoArbol iz, NodoArbol de) {
		this.clave = clave;
		this.iz = iz;
		this.de = de;
	}

	public NodoArbol getIz () {
		return iz;
	}

	public NodoArbol getDe () {
		return de;
	}

	public char getClave () {
		return clave;
	}

	public void setIz (NodoArbol nuevoIz) {
		iz = nuevoIz;
	}

	public void setDe (NodoArbol nuevoDe) {
		de = nuevoDe;
	}

	public void setClave (char nuevaClave) {
		clave = nuevaClave;
	}

}