
class Nodo {

    private Paciente paciente;
    private Nodo siguiente;

    public Nodo(Paciente paciente, Nodo siguiente) {
        this.paciente = paciente;
        this.siguiente = siguiente;
    }

    public Nodo getSiguiente() {
        return siguiente;
    }

    public void setSiguiente(Nodo siguiente) {
        this.siguiente = siguiente;
    }

    public Paciente getPaciente() {
        return paciente;
    }


    public void setPaciente(Paciente paciente) {
        this.paciente = paciente;
    }
}
