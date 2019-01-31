import java.util.Scanner;

public class Divisores {
    public static void main(String[] args){
        int valor;
        Scanner lectura = new Scanner(System.in);
        System.out.print("Introduce un valor entero positivo: ");
        valor = lectura.nextInt();
        if(valor >= 1) mostrarDivisores(valor);
        else System.out.println("Numero no válido");
    }
    public static void mostrarDivisores(int valor){
        for(int i=1; i<=valor; i++){
            if(valor%i==0) System.out.println(i);
        }
    }
}