public class Conjunto implements IConjunto{


  private boolean[] conjunto;

  public Conjunto(){
    conjunto = new boolean[SIZE];
  }

  public void set(int posicion, boolean valor){
    if(posicion<SIZE) conjunto[posicion]=valor;
  }
  public void get(int posicion){
    if(posicion<SIZE) return conjunto[posicion];
    else return false;
  }
  public IConjunto get(){
    return this;
  }
}
