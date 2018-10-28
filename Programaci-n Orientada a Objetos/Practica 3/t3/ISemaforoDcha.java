package t3;

public interface ISemaforoDcha extends ISemaforo {
    
    /**
    * @return color dcha que tiene el sem�foro
    */
    int getColorDcha();

    /**
    * @param colorCentral derecha que se le pone al semaforo
    */
    void setColorDerecha(int colorCentral);

    /**
    * Compara la instancia del sem�foro con el sem�foro que pasa por parametro. Dos semaforos son iguales si se encuentran en el mismo estado (tienen los mismos colores)
    * @param s Sem�foro a comparar con la instancia
    * @return true si son iguales
    */
    boolean equals(ISemaforoDcha s);

    /**
    * Crea una copia del sem�foro
    * @return La copia del sem�foro
    */
    ISemaforoDcha clone();

}