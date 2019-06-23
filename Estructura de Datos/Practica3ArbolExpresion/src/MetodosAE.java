import java.util.Stack;

public class MetodosAE {

    public static boolean esOperador(char c) {
                return ((c == '+') || (c == '-') || ('*' == c) || (c == '/'));
    }

    public static boolean esDigito(char c) {
                return Character.isDigit(c);
    }

    public static int pasarAEntero(char c) {
                return (c - 48);
    }

    public static Arbol notacInfija(String s) {
        //Al string s hay que anadirle un paréntesis de apertura y otro de cierre
        //Para que la expresién esté "fully parenthesized"

        s = "(" + s + ")";
        int l = s.length();

        Stack<Arbol> pila = new Stack<Arbol>();
        for (int i = 0; i < l; i++) {
            Character c = s.charAt(i);
            if (esDigito(c) || esOperador(c)) {
                //creo un arbol y lo apilo
                Arbol a = new Arbol(c);
                pila.push(a);
            } else if (c == ')') {
                Arbol de = pila.pop();
                Arbol root = pila.pop();
                Arbol iz = pila.pop();
                char clave = root.getRaiz().getClave();
                root.juntar(clave, iz, de);
                pila.push(root);
            }
        }
        return pila.pop();
    }

}
