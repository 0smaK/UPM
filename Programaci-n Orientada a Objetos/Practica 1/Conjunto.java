public class Conjunto implements IConjunto {

  private boolean[] conjunto;

  public Conjunto(){
    conjunto = new boolean[SIZE];
  }

  public void set(int posicion, boolean valor){
    if(posicion<SIZE) conjunto[posicion]=valor;
  }
  public boolean get(int posicion){
    if(posicion<SIZE) return conjunto[posicion];
    else return false;
  }
  public IConjunto get(){
    return this;
  }

  public IConjunto union(IConjunto c){
    Conjunto auxiliar = new Conjunto();
    for (int i=0; i<SIZE; i++)
    auxiliar.set(i,c.get(i) && conjunto[i]);
    return auxiliar;
  }

  public IConjunto intersection(IConjunto c){
    Conjunto auxiliar = new Conjunto();
    for (int i=0; i<SIZE; i++)
    auxiliar.set(i,c.get(i) && conjunto[i]);
    return auxiliar;
  }

  public int size(){
    int size = 0;
    for (int i=0;i<SIZE;i++)
    if(conjunto[i])
    size++;
    return SIZE;
  }

  public String toString() {
    String res="";
    for (int i=0;i<SIZE;i++)
    if (conjunto[i])
    res=res+"T ";
    else
    res=res+"F ";
    return res;
  }

}
