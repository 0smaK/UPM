public class Principal {
    public static void main(String[] args) {
        Pila pila = new Pila();
        pila.apilar(10);
        pila.apilar(9);
        pila.apilar(8);
        pila.apilar(1);
        pila.apilar(2);

        pila.escribirPila();
        System.out.println("======================================");
        System.out.println("Suma de la pila: " + sumarElementos(pila));
        System.out.println("======================================");
        System.out.println();

        Pila p1 = new Pila();
        Pila p2 = new Pila();

        p1.apilar(1);
        p1.apilar(2);
        p1.apilar(3);

        p2.apilar(10);
        p2.apilar(20);
        p2.apilar(30);
        p2.apilar(40);

        System.out.println("\nPila 1: ");
        p1.escribirPila();
        System.out.println("\nPila 2: ");
        p2.escribirPila();

        System.out.println("======================================");
        System.out.println("Pila1 unida a Pila2:");
        System.out.println("======================================");
        System.out.println();
        p1.unirPila(p2);
        p1.escribirPila();
    }

    public static int sumarElementos(Pila pila) {
        int sum = 0;
        while (!pila.pilaVacia()) {
            sum += pila.cima();
            pila.desapilar();
        }
        return sum;
    }

    

}

             
