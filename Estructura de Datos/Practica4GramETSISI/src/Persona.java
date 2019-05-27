import java.util.Scanner;
public class Persona {
    private String nombre, telefono, direccion;

    public Persona() {
        nombre = "";
        telefono ="";
        direccion ="";
    }

    public Persona(String nombre, String telefono, String direccion) {
        this.nombre = nombre;
        this.telefono = telefono;
        this.direccion = direccion;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getTelefono() {
        return telefono;
    }

    public void setTelefono(String telefono) {
        this.telefono = telefono;
    }

    public String getDireccion() {
        return direccion;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }
    public void leerDatos () {
        Scanner sc = new Scanner (System.in);
        System.out.print ("Nombre: ");
        nombre = sc.nextLine ();
        System.out.print ("Dirección: ");
        direccion = sc.nextLine ();
        System.out.print ("teléfono: ");
        telefono = sc.nextLine ();
    }

    public void mostrarPersona(){
        System.out.println(this.nombre+" ("+this.telefono+") "+this.direccion);
    }

}
