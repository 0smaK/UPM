public class Arbol {
    private NodoArbol raiz;

    public Arbol() {
        raiz = null;
    }

    public Arbol(char clave) {
        raiz = new NodoArbol(clave);
    }

    // Escribe las claves del árbol binario de raiz a en preorden.
    private void preOrden(NodoArbol nodo) {
        if (nodo != null) {
            System.out.print (nodo.getClave() + " "); // Nodo
            preOrden(nodo.getIz()); // Izquierda
            preOrden(nodo.getDe()); // Derecha
        }
    }
    public void preOrden() {
        System.out.print ("Preorden: ");
        preOrden(raiz);
        System.out.println();
    }

    // Escribe las claves del árbol binario de raiz a en postorden.
	public String postOrden(){
		System.out.println("Post orden: ");
		return postOrden(raiz);
	}

	public String postOrden(NodoArbol nodo){
		return nodo != null ? postOrden(nodo.getIz()) + postOrden(nodo.getDe()) + " " + nodo.getClave() : "";
	}

    // Escribe las claves del árbol binario de raiz a en orden central.
    private void ordenCentral(NodoArbol nodo) {
        if (nodo != null) {
            ordenCentral(nodo.getIz()); // Izquierda
            System.out.print(nodo.getClave() + " "); // Nodo
            ordenCentral(nodo.getDe()); // Derecha
        }
    }
    public void ordenCentral() {
        System.out.print ("Orden central: ");
        ordenCentral(raiz);
        System.out.println();
    }

     public NodoArbol getRaiz() {
        return raiz;
    }

    public void setRaiz(NodoArbol nodo) {
        raiz = nodo;
    }
	
	public void juntar(char clave, Arbol a1, Arbol a2) {
        if (a1.raiz == a2.raiz && a1.raiz != null)
            System.out.println("no se pueden mezclar, a1 y a2 son iguales");
        else {
            // Crear el nodo nuevo
            raiz = new NodoArbol(clave, a1.raiz, a2.raiz);
            // Borrar los árboles a1 y a2
            if (this != a1)
                a1.raiz = null;
            if (this != a2)
                a2.raiz = null;
        }
    }

	public float calcularValor(){
		System.out.println("Valor: ");
		float val = 0;
		val = calcularValor(raiz);
		return val;
	}

	private float calcularValor(NodoArbol nodo){
		float izq = 0, dcha = 0, result = 0;
		if(nodo != null)
			if(MetodosAE.esOperador(nodo.getClave())){
				if(nodo.getIz()!=null) izq = calcularIzq(nodo, izq);
				if(nodo.getDe()!=null) dcha = calcularDcha(nodo,dcha);
				result = calcularValor(izq, dcha, nodo.getClave());
			}else if(MetodosAE.esDigito(nodo.getClave())) return nodo.getClave();
			return result;
	}

	private float calcularIzq(NodoArbol nodo, float izq){
		izq = calcularValor(nodo.getIz());
		if(nodo.getIz().getIz()==null)
			izq = MetodosAE.pasarAEntero((char) izq);
		return izq;
	}

	private float calcularDcha(NodoArbol nodo, float dcha){
		dcha = calcularValor(nodo.getDe());
		if(nodo.getDe().getDe()==null)
			dcha = MetodosAE.pasarAEntero((char) dcha);
		return dcha;
	}

	private float calcularValor(float izq, float dcha, char operador){
    	float val = 0;
    	switch (operador){
			case '+':
				val = izq + dcha;
				break;
			case '-':
				val = izq - dcha;
				break;
			case '*':
				val = izq * dcha;
				break;
			case '/':
				val = izq / dcha;
				break;
		}
		return val;
	}
}
