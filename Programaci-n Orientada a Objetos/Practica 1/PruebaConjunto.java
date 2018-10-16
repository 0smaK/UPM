/**
 *
 * @author POO.
 * Ejercicio de Prácticas de la lección 1.
 *
 */
public class PruebaConjunto {

	public static void main(String[] args) {
		Conjunto c1 = new Conjunto();  // Instanciación con el constructor vacío.
		IConjunto c2 = new Conjunto(); // Se pueden utilizar objetos interfaz como tipos.

		c1.set(1, true);c1.set(2, true);c1.set(10, true);c1.set(15, true);c1.set(18, true);
		c2.set(1, true);c2.set(3, true);c2.set(10, true);c2.set(16, true);

		System.out.println(c1.size()+",  "+c2.size());

		System.out.println(c1.toString());
		System.out.println();
		System.out.println(c2); // El compilador pone la llamada al método toString()

		System.out.println();

		System.out.println(c1.union(c2));  //  lo mismo que: c2.union(c1)
		System.out.println();
		System.out.println(c1.intersection(c2));
	}

}
