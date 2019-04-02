public class ColaPrioridades {
    private NodoPrioridad inicio;

    public ColaPrioridades() {
        inicio = null;
    }

    public boolean estaVacia() {
        return inicio == null;
    }

    /** Inserta el paciente en la cola que le corresponde según su prioridad.
     * Si no hay ningún paciente con la misma prioridad, crea una cola nueva en la que mete al paciente.
     */
    public void encolar(int prioridad, Paciente paciente) {
        NodoPrioridad anterior = null;
        NodoPrioridad actual = inicio;

        while((actual!=null)&&(actual.getPrioridad()<prioridad)){
            anterior = actual;
            actual = actual.getSiguiente();
        }
        if((actual == null) || (actual.getPrioridad()>prioridad)){
            NodoPrioridad nuevo = new NodoPrioridad(prioridad,paciente,actual);
            if(actual==inicio){
                inicio = nuevo;
            }else{
                anterior.setSiguiente(nuevo);
            }
        }else if(actual.getPrioridad()==prioridad){
            actual.setSiguiente(new NodoPrioridad(prioridad,paciente,null));
        }

    }

    /** Busca la clave en la lista. Si la encuentra devuelve el alumno asociado a dicha clave,
     * y si no la encuentra devuelve NULL.
     */
    public Paciente desencolar() {
        NodoPrioridad nodopr;
        Paciente paciente = null;
        if(inicio==null){
            System.out.println("la cola está vacía");
        }else{
            nodopr = inicio;
            inicio = nodopr.getSiguiente();
            paciente = nodopr.getPaciente();
        }
        return paciente;
    }

    /** Visualizar todos los pacientes del hospital, ordenados por prioridad
     */
    public void verColaPrioridades() {
        NodoPrioridad aux = inicio;
        int auxpr = -1;
        while(aux!=null){
            if(auxpr!=aux.getPrioridad()) System.out.println("Prioridad "+ aux.getPrioridad()+":");
            auxpr = aux.getPrioridad();
            aux.getPaciente().verPaciente();
            aux=aux.getSiguiente();

        }
    }
}


