import java.util.Scanner;

public class Alumno {
    private static final int MAX = 5;
    
    private String nombre, apellidos, matricula;
    private double calificacion;
    private int numAsig;
    private String[] asignaturas;
    //Constructor con 4 parametros
    
    public Alumno(){
        nombre = "";
        apellidos = "";
        matricula = "";
        calificacion = 0;
        numAsig = 0;
        asignaturas = new String[MAX];
    }
    
    public Alumno(String nombre,String apellidos,String matricula,double calificacion){
        this.nombre = nombre;
        this.apellidos = apellidos;
        this.matricula = matricula;
        this.calificacion = calificacion;
        numAsig = 0;
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
    public double getCalificacion(){
        return calificacion;
    }

    public void setNombre(String nombre){
        this.nombre = nombre;
    }

    public void setApellidos(String apellidos){
       this.apellidos = apellidos;
    }

    public void setMatricula(String matricula){
        this.matricula = matricula;
    }
    public void setCalificacion(double calificacion){
        this.calificacion = calificacion;
    }

    public int getNumAsignaturas(){
        return numAsig;
    }

    public void AnadirAsignaturas(String asignatura){
        if(numAsig < MAX){
            asignaturas[numAsig] = asignatura;
            numAsig++;
        } else{
            System.out.println("No se pueden añadir más asignaturas");
        }
    }

    public void mostrarAsignaturas(){
        if(numAsig==0){ System.out.println("El alumno no estám atriculado en ninguna asignatura"); } 
        else for(int i=0; i<numAsig;i++){ System.out.println(asignaturas[i]); }
    }

    public void mostrarAlumno(){
        System.out.println(this.apellidos+", "+this.nombre+". Matr: "+this.matricula+" ("+this.calificacion+")");
        mostrarAsignaturas();
    }

    
}