public class Cola {
    private Nodo cabeza, fin;
    private int numElem;

    Cola() {
        cabeza = null;
        fin = null;
        numElem = 0;
    }

    public void encolar(Paciente v) {    // Coloca el elemento v al final de la cola
        Nodo nuevo;
        nuevo = new Nodo(v, null);
        if (cabeza != null) {
            fin.setSiguiente(nuevo);
        } else {
            cabeza = nuevo;
        }
        fin = nuevo;
        numElem++;
    }

    public Paciente desencolar() {    //Devuelve el elemento del cabeza de la cola y lo elimina Si la cola está vacía, devuelve como resultado 0 y un mensaje de error
        Nodo nodo;
        Paciente resul = new Paciente("0","0");
        if (cabeza == null) {
            System.out.println("Error, la cola está vacía");
        } else {
            nodo = cabeza;
            cabeza = nodo.getSiguiente();
            resul = nodo.getDato();
            if (cabeza == null)
                fin = null;
            numElem--;
        }
        return resul;
    }

    public boolean colaVacia() {   // Comprueba si la cola está vacía
        return cabeza == null;
    }



    public Paciente primero() {  //Devuelve el elemento del cabeza de la cola Si la cola está vacía, devuelve como resultado -999 y un mensaje de error
        Paciente resul = new Paciente("-999","-999");
        if (!this.colaVacia()) {
            resul = cabeza.getDato();
        } else {
            System.out.println("Error, la cola está vacía");
        }
        return resul;
    }

    public void verCola() {     // Muestra por pantalla el contenido de la cola
        Nodo aux;
        aux = cabeza;
        while (aux != null) {
            aux.getDato().verPaciente();
            aux = aux.getSiguiente();
        }
    }

    public int numElemCola() {       // Devuelve el número de elementos de la cola
        return numElem;
    }
}


