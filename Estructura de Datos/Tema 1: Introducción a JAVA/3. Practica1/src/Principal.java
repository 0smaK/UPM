public class Principal {
    public static void main(String[] args){
        Alumno[] alum = new Alumno[4];

        alum[0] = new Alumno("Felipe","Arias Gonzalez","aa1253",3.50);
        alum[1] = new Alumno("Manuel","García Sacedón","ax0074",8.35);
        alum[2] = new Alumno("Margarita","Lopez Medina","mj7726",7.70);
        alum[3] = new Alumno("Estela","Sanchez Arellano","bc2658",6.75);

        alum[3].AnadirAsignaturas("Matemáticas Discretas");
        alum[3].AnadirAsignaturas("Estructuras de Datos");

        System.out.println("******************");
        alum[0].mostrarAlumno();
        System.out.println("******************");
        alum[3].mostrarAlumno();
    } 
}