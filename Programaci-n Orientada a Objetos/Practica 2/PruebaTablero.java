/**
 * @author osmak
 * 
 */

public class PruebaTablero {

	public static void main(String[] args) {
	  Tablero t = new Tablero(8);
	  t.setPosicion(3, 4, 1); t.setPosicion(7, 7, 1);t.setPosicion(0, 2, 1);
	  System.out.println(t.ocupacion());
	  
	  t.setPosicion(3, 6, 2); t.setPosicion(6, 5, 2);t.setPosicion(1, 7, 2);
	  System.out.println(t.ocupacion());
	  System.out.println();
	
	  System.out.println(t);
	}

}
