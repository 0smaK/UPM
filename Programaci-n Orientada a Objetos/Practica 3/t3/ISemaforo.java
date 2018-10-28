package t3;

public interface ISemaforo {
    int ROJO=0;
    int AMBAR=1;
    int VERDE=2;
    int APAGADO=3;
    /**
    * @return color central que tiene el sem�foro
    */
    int getColorCentral();

    /**
    * @param ColorCentral central que se le pone al sem�foro
    */
    void setColorCentral(int ColorCentral);

    /**
    * Compara la instancia del sem�foro con el sem�foro que pasa por par�metro. Dos semaforos son iguales si se encuentran en el mismo estado (tienen el mismo color).
    * @param s Sem�foro a comparar con la instancia 
    * @return true si son iguales
    */
    boolean equals(ISemaforo s);

    /**
    * Crea una copia del sem�foro 
    * @return la copia del semaforo
    */
    ISemaforo clone();

}