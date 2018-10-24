public class Tablero implements ITablero{
    
    private int[][] tablero;
    private int size;

    public Tablero(int size){
        this.size = size;
        tablero = new int[size][size];
    }

    public int[][] getTablero(){
        return tablero;
    }

    public void setTablero(int[][] tablero){
        this.tablero = tablero;
    }

    public int getTamanio(){
        return size;
    }

    public int getPosicion(int x, int y){
        return tablero[x][y];
    }
   
    public void setPosicion(int x, int y, int valor){
        tablero[x][y] = valor;
    }

    public void borra(){
        for(int i=0; i<size; i++){
            for(int k=0;k<size;k++){
                tablero[k][i]=0;
            }
        }
    }

    public int ocupacion(){
        int nvacias = 0;
        for(int i=0; i<size; i++)
            for(int k=0;k<size;k++)
                if(tablero[k][i]==0) nvacias++;
        return nvacias;
    }

    public String toString() {
	  String resultado="";
	  for (int y=0;y<size;y++) {
		for (int x=0;x<size;x++) 
		  resultado=resultado+tablero[x][y]+" ";	
		resultado=resultado+"\n";
	  }	
	  resultado=resultado+"\n\n";
	  return resultado;
	}
}