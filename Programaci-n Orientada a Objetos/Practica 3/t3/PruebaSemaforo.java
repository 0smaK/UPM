package t3;

public class PruebaSemaforo {
	public static void main(String[] args) {

		/**
		 * int ROJO=0; int AMBAR=1; int VERDE=2; int APAGADO=3;
		 */
		ISemaforo s1;
		Semaforo s2;
		ISemaforoDcha sd1;
		SemaforoDcha sd2;
		ISemaforo sd3;

		s1 = new Semaforo(Semaforo.VERDE);
		s2 = new Semaforo(Semaforo.ROJO);
		sd1 = new SemaforoDcha(ISemaforo.VERDE);
		sd2 = new SemaforoDcha(ISemaforo.ROJO, ISemaforo.AMBAR);
		sd3 = new SemaforoDcha(ISemaforo.AMBAR, ISemaforo.ROJO);

		System.out.println("s1: " + s1 + "\ns2: " + s2 + "\nsd1: " + sd1 + "\nsd2: " + sd2 + "\nsd3: " + sd3);

		System.out.println(s1.equals(s2));

		s2.setColorCentral(2);
		System.out.println(s1.equals(s2));

		System.out.println(sd1.getColorCentral() + ", " + sd1.getColorDcha());

	}
}