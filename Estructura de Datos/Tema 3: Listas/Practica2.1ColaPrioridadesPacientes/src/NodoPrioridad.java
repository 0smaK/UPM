public class NodoPrioridad {
    private int prioridad;
    private Paciente paciente;
    private NodoPrioridad siguiente;

    public NodoPrioridad(int prioridad, Paciente paciente, NodoPrioridad siguiente) {
        this.prioridad = prioridad;
        this.paciente = paciente;
        this.siguiente = siguiente;
    }

    public NodoPrioridad getSiguiente() {
        return siguiente;
    }

    public Paciente getPaciente() {
        return paciente;
    }

    public void setSiguiente(NodoPrioridad siguiente) {
        this.siguiente = siguiente;
    }

    public void setCola(Paciente pacinete) {
        this.paciente = paciente;
    }

    public int getPrioridad() {
        return prioridad;
    }

    public void setPrioridad(int prioridad) {
        this.prioridad = prioridad;
    }
}
