import java.util.Scanner;

public class Factorial {
    public static void main(String[] args){
        int valor;
        Scanner lectura = new Scanner(System.in);
        System.out.print("Introduce un valor entero: ");
        valor = lectura.nextInt();
        if (valor >= 1) System.out.println("El factorial de "+valor+" es "+factorial(valor));
        else System.out.println("El numero debe de ser positivo.");
    }

    public static long factorial(int numero){
        long resultado;
        if(numero>1) resultado = numero * factorial(numero-1);
        else resultado = 1;
        return resultado;
    }
}