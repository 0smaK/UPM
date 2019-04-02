
public class Aplicacion {

    public static void main(String[] args) {
        Paciente p1 = new Paciente("Alberto","Frecuentes Mareos");
        Paciente p2 = new Paciente("Ana","Infección resistente");
        Paciente p3 = new Paciente("Eva","Problemas digestivos");

        Cola cp = new Cola();


        cp.encolar(p1);
        cp.encolar(p2);
        cp.encolar(p3);

        System.out.println("CONTENIDO DE LA COLA");
        cp.verCola();
        System.out.println("==================");
        System.out.println();

        while(!cp.colaVacia()){
            cp.desencolar();
        }

        System.out.println("CONTENIDO DE LA COLA");
        cp.verCola();
        System.out.println("==================");
        System.out.println();
        System.out.println();

        ColaPrioridades cpri = new ColaPrioridades();

        System.out.println("COLA DE PRIORIDADES:\n");
        cpri.encolar(4,p1);
        cpri.encolar(2,p2);
        cpri.encolar(4,p3);

        cpri.verColaPrioridades();

        System.out.println();
        System.out.println("=================");
        System.out.println("Paciente atendido");

        cpri.desencolar().verPaciente();
        System.out.println("=================");
        System.out.println();

        cpri.verColaPrioridades();

        System.out.println();
        System.out.println("=================");
        System.out.println("LLEGA ERNESTO CON PRIORIDAD 1");
        System.out.println("=================");
        System.out.println();
        Paciente p4 = new Paciente("Ernesto","Problemas Cardiovasculares");
        cpri.encolar(1,p4);
        cpri.verColaPrioridades();
        System.out.println("=================");
    }

}

