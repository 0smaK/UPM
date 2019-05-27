public class Principal {

	public static void main(String[] args){

		GramETSISI grametsisi = new GramETSISI(10);
		Persona p0 = new Persona("Juan", "123456", "Albufera");
		Persona p1 = new Persona("José", "231465", "Princesa");
		Persona p2 = new Persona("Eva", "321654", "Gaztambide");
		Persona p3 = new Persona("Alicia", "789456", "Castellana");
		Persona p4 = new Persona("Ernesto", "654321", "Arboleda");
		Persona p5 = new Persona("Guillermo", "159267", "Arapiles");
		Persona p6 = new Persona("Alberto", "123456", "Gaztambide");
		Persona p7 = new Persona("Lucas", "231465", "Princesa");
		Persona p8 = new Persona("Clara", "789456", "Catellana");
		Persona p9 = new Persona("Pedro", "666000", "Vallecas");

		grametsisi.insertaVertice(p0);
		grametsisi.insertaVertice(p1);
		grametsisi.insertaVertice(p2);
		grametsisi.insertaVertice(p3);
		grametsisi.insertaVertice(p4);
		grametsisi.insertaVertice(p5);
		grametsisi.insertaVertice(p6);
		grametsisi.insertaVertice(p7);
		grametsisi.insertaVertice(p8);
		grametsisi.insertaVertice(p9);

		grametsisi.insertaArista(0,1);
		grametsisi.insertaArista(0,4);
		grametsisi.insertaArista(0,5);
		grametsisi.insertaArista(1,4);
		grametsisi.insertaArista(4,5);

		grametsisi.insertaArista(2,9);
		grametsisi.insertaArista(2,7);
		grametsisi.insertaArista(7,9);

		grametsisi.insertaArista(3,6);
		grametsisi.insertaArista(6,8);

		System.out.println();
		System.out.println("nº de grupos "+grametsisi.contarGrupos());
		System.out.println();

		System.out.println();
		System.out.println("Contactos");
		grametsisi.imprimirGrafo();
		System.out.println();

		String nombre = "Eva";
		System.out.println("Amigos de "+nombre);
		grametsisi.mostrarAmigos(nombre);
		System.out.println();

		System.out.println("Mayor grupo");
		grametsisi.mayorGrupo();
		System.out.println();

	}

}
