import java.util.Scanner;

public class Alumno {
    
    Scanner sc = new Scanner(System in);
    String nombre, apellidos, matricula;
    double calificacion, numAsig;
    String[] asignaturas = new String[5];
    //Constructor con 4 parametros
    
    public Alumno(){
        nombre = "";
        apellidos = "";
        matricula = "";
        calificacion = 0;
        numAsig = 0;
    }
    
    public Alumno(nombre, apellidos, matricula, calificacion){
        this.nombre = nombre;
        this.apellidos = apellidos;
        this.matricula = matricula;
        this.calificacion = calificacion;
    }

    public String getNombre(){
        return nombre;
    }

    public String getApellidos(){
        return apellidos;
    }

    public String getMatricula(){
        return matricula;
    }
    public int getCalificacion(){
        return calificacion;
    }

    public void setNombre(){
        System.out.println("Introduce un nombre: ");
        nombre = sc.nextString();
    }

    public void setApellidos(){
        System.out.println("Introduce apellidos: ");
        apellidos = sc.nextString();
    }

    public void setMatricula(){
        System.out.println("Introduce una matricula: ");
        matricula = sc.nextString();
    }
    public void setCalificacion(){
        System.out.println("Introduce una calificacion: ");
        calificacion = sc.nextInt();
    }

    public int getNumAsignaturas(){
        int cont = 0;
        for(int i=0; i<5;i++)
            if(asignaturas[i]!=null) cont++;
        return cont;
    }

    public void AnadirAsignaturas(){
        Sysout.println("Introduce -1 para parar de añadir asignaturas")
        for(int i = 0; i<5; i++)
            if(asignaturas[i]==null){
                asignaturas[i] = sc.nextString();
                if(asignaturas[i]=='-1'){
                    asignaturas[i]=null;
                    i=4
                }
            }else if(asignaturas[i]!=null && i>=4){
                System.out.println("No se pueden añadir mas asignaturas");
            }
    }

    public void mostrarAsignaturas(){
        for(int i=0; i<5;i++)
            if(asignaturas[i]!=null) System.out.println(asignaturas[i]);
    }

    //tocode
}