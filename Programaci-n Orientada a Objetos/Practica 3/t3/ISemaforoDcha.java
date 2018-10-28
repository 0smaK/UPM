package t3;

public interface ISemaforoDcha extends ISemaforo {
    
    /**
    * @return color dcha que tiene el semáforo
    */
    int getColorDcha();

    /**
    * @param colorCentral derecha que se le pone al semaforo
    */
    void setColorDerecha(int colorCentral);

    /**
    * Compara la instancia del semáforo con el semáforo que pasa por parametro. Dos semaforos son iguales si se encuentran en el mismo estado (tienen los mismos colores)
    * @param s Semáforo a comparar con la instancia
    * @return true si son iguales
    */
    boolean equals(ISemaforoDcha s);

    /**
    * Crea una copia del semáforo
    * @return La copia del semáforo
    */
    ISemaforoDcha clone();

}