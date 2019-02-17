public class GrupoAlumnos{
    private Alumno[] listaAlumnos;
    private int numAlumnos;
    private int maxim;
    private String nombre;

    public GrupoAlumnos(){
        nombre="Grupo alumnos";
        maxim = 10;
        listaAlumnos = new Alumno[10];
        numAlumnos = 0;
    }

    public GrupoAlumnos(int max, String nom){
        nombre=nom;
        maxim=max;
        listaAlumnos = new Alumno[maxim];
        numAlumnos = 0;
    }

    public int getNumAlumnos(){
        return numAlumnos;
    }

    public int getMaximo(){
        return maxim;
    }

    public String getNombre(){
        return nombre;
    }
}