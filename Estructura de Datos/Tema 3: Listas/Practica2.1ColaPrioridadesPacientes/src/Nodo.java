public class Nodo {

    private Paciente paciente;
    private Nodo siguiente;

    public Nodo(Paciente paciente, Nodo sig) {
        this.paciente = paciente;
        this.siguiente = sig;
    }

    public Nodo getSiguiente() {
        return siguiente;
    }

    public void setSiguiente(Nodo siguiente) {
        this.siguiente = siguiente;
    }

    public Paciente getDato() {
        return paciente;
    }

    public void setDato(Paciente paciente) {
        this.paciente = paciente;
    }
}
