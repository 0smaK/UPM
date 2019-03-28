import java.util.List;

public class Aplicacion{


    public static void main(String[] args) {
        Paciente p1 = new Paciente("Alberto","Frecuentes Mareos");
        Paciente p2 = new Paciente("Ana","Infección resistente");
        Paciente p3 = new Paciente("Eva","Problemas Digestivos");
        Paciente p4 = new Paciente("Ernesto", "Problemas cardiovasculares");

        p2.darAlta();
        p3.darAlta();

        ListaOrdinal lista = new ListaOrdinal();

        lista.insertar(p1);
        lista.insertar(p2);
        lista.insertar(p3);
        lista.insertar(p4);

        System.out.println("PACIENTES DEL HOSPITAL:");
        imprimirListaPacientes(lista);
        System.out.println("------------------------");
        System.out.println();

        lista.borrarAltas();

        System.out.println("DESPUÉS DE BORRAR LAS ALTAS:");
        imprimirListaPacientes(lista);
        System.out.println("------------------------");
        System.out.println();

        lista.insertar(p2);
        lista.insertar(p3);

        verAltas(lista);
        System.out.println();

        pacientesSintoma(lista,"mareo");

    }

    public static void verAltas(ListaOrdinal lista){
        System.out.println("PACIENTES DE ALTA");
        for(int i = 0; i<lista.tamaño();i++){
            if(lista.get(i).estaAlta()){
                lista.get(i).verPaciente();
            }
        }
        System.out.println("------------------------");
    }

    public static void imprimirListaPacientes(ListaOrdinal lista){
        for(int i = 0; i<lista.tamaño(); i++){
            lista.get(i).verPaciente();
        }
    }

    public static void pacientesSintoma(ListaOrdinal lista, String sintoma){
        System.out.println("PACIENTES CON "+sintoma.toUpperCase());
        for(int i = 0; i < lista.tamaño(); i++){
            if(lista.get(i).getSintomas().toUpperCase().indexOf(sintoma.toUpperCase())>=0){
                lista.get(i).verPaciente();
            }
        }
        System.out.println("------------------------");
    }

}