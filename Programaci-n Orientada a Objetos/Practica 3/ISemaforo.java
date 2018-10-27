public interface ISemaforo {
    
    /**
    * @return color central que tiene el semáforo
    */
    int getColorCentral();

    /**
    * @param ColorCentral central que se le pone al semáforo
    */
    void setColorCentral(int ColorCentral);

    /**
    * Compara la instancia del semáforo con el semáforo que pasa por parámetro. Dos semaforos son iguales si se encuentran en el mismo estado (tienen el mismo color).
    * @param s Semáforo a comparar con la instancia 
    * @return true si son iguales
    */
    boolean equals(ISemaforo s);

    /**
    * Crea una copia del semáforo 
    * @return la copia del semaforo
    */
    ISemaforo clone();

}