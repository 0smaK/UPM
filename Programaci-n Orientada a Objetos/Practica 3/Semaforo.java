public class Semaforo implements ISemaforo {

    public int colorCentral;

    public Semaforo(){
        setColorCentral(ROJO);
    }

    public Semaforo(int colorCentral){
        setColorCentral(colorCentral);
    }

    public int getColorCentral(){
        return colorCentral;
    }

    public void setColorCentral(int colorCentral){
        setColorCentral(colorCentral);
    }

    public boolean equals(ISemaforo s){
        return this.colorCentral == s.getColorCentral;
    }   
}