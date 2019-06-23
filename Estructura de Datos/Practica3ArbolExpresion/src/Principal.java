public class Principal {
	public static void main(String[] args){
		Arbol[] expresion = new Arbol[3];
		expresion[0] = MetodosAE.notacInfija("((5+2)*(8-3))/4");
		expresion[1] = MetodosAE.notacInfija("((9+2)*(7-2))/2");
		expresion[2] = MetodosAE.notacInfija("((2*9)+((3-7)*5))/9");

		for(Arbol expr : expresion){
			System.out.println(expr.postOrden());
			System.out.println(expr.calcularValor());
			System.out.println("=============\n");
		}
	}
}
